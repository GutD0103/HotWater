/*
 * hotwater.c
 *
 *  Created on: Jul 26, 2023
 *      Author: ntdat
 */


#include "DEVICE/hotwater.h"

static GPIO_PinState water_0_level_0() {
	GPIO_PinState state = WATER0_LEVEL0_STATE;
	if(state == WT_LV_FULL){
		WT_EMPTY_OFF(0);
	}else if(state == WT_LV_EMPTY){
		WT_EMPTY_ON(0);
	}
	return state;
}
static GPIO_PinState water_0_level_1() {return WATER0_LEVEL1_STATE;}
static GPIO_PinState water_1_level_0() {
	GPIO_PinState state = WATER1_LEVEL0_STATE;
	if(state == WT_LV_FULL){
		WT_EMPTY_OFF(1);
	}else if(state == WT_LV_EMPTY){
		WT_EMPTY_ON(1);
	}
	return state;
}
static GPIO_PinState water_1_level_1() {return WATER1_LEVEL1_STATE;}
static float GetTemp0(){return TEMP_get_temp(0);}
static float GetTemp1(){return TEMP_get_temp(1);}
static bool GetFlow0(){return FLOW_is_flowing(0);}
static bool GetFlow1(){return FLOW_is_flowing(1);}
static void ControlRelay0(GPIO_PinState state){
	if(state == DEVICE_CLOSE){
		BOILING_OFF(0);
	}else if(state == DEVICE_OPEN){
		BOILING_ON(0);
	}
	HAL_GPIO_WritePin(RELAY0_GPIO_Port, RELAY0_Pin, state);
}
static void ControlRelay1(GPIO_PinState state){
	if(state == DEVICE_CLOSE){
		BOILING_OFF(1);
	}else if(state == DEVICE_OPEN){
		BOILING_ON(1);
	}
	HAL_GPIO_WritePin(RELAY1_GPIO_Port, RELAY1_Pin, state);
}
static void ControlSolenoidOut0(GPIO_PinState state){ HAL_GPIO_WritePin(SOLENOID_OUT0_GPIO_Port, SOLENOID_OUT0_Pin, state);}
static void ControlSolenoidOut1(GPIO_PinState state){ HAL_GPIO_WritePin(SOLENOID_OUT1_GPIO_Port, SOLENOID_OUT1_Pin, state);}
static void ControlSolenoidIn0(GPIO_PinState state){ HAL_GPIO_WritePin(SOLENOID_IN0_GPIO_Port, SOLENOID_IN0_Pin, state);}
static void ControlSolenoidIn1(GPIO_PinState state){ HAL_GPIO_WritePin(SOLENOID_IN1_GPIO_Port, SOLENOID_IN1_Pin, state);}
static GPIO_PinState GetRelay0() {return RELAY0_STATE;}
static GPIO_PinState GetRelay1() {return RELAY1_STATE;}
static GPIO_PinState GetSolenoid0() {return SOLENOID_OUT0_STATE ;}
static GPIO_PinState GetSolenoid1() {return SOLENOID_OUT1_STATE ;}

WaterOut waterout[2] = {
    {
        .temp = GetTemp0,
        .flow = GetFlow0,
		.get_relay = GetRelay0,
		.get_solenoid_out = GetSolenoid0,
        .set_relay = ControlRelay0,
        .set_solenoid_out = ControlSolenoidOut0,
		.set_solenoid_in = ControlSolenoidIn0,
		.water_level_0 = water_0_level_0,
        .water_level_1 = water_0_level_1
    },
    {
        .temp = GetTemp1,
        .flow = GetFlow1,
		.get_relay = GetRelay1,
		.get_solenoid_out = GetSolenoid1,
        .set_relay = ControlRelay1,
        .set_solenoid_out = ControlSolenoidOut1,
		.set_solenoid_in = ControlSolenoidIn1,
        .water_level_0 = water_1_level_0,
        .water_level_1 = water_1_level_1
    }
};


