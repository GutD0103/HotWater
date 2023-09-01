/*
 * water_out.c
 *
 *  Created on: Aug 18, 2023
 *      Author: ntdat
 */
#include "APP/water_out.h"


#define BOILING_DURATION 		300000
#define TOO_HOT_DURATION		60000
#define WATERING_DURATION		300000
#define UART_DURATION			100

#define CHECK_FLOWING_DURATION 				1000
#define CHECK_TEMP_DURATION 				500
#define CHECK_WATER_LEVEL_DURATION 			1000

#define MAX_COUNTS           7
enum {
	SYSTEM0,
	SYSTEM1,
	MAX_SYSTEM
};

enum{
	FLOW_INIT,
	FLOW_NORMAL,
	NOT_FLOWING,
	LEAKING
};
enum{
	WATER_INIT,
	WATER_NORMAL,
	WATER_EMPTY,
	WATER_OVERFLOW,
	WATER_EROR
};
enum{
	TEMP_INIT,
	TEMP_HOT,
	TEMP_TOO_HOT,
	TEMP_NOT_HOT_ENOUGH,
	TEMP_COOL,
	TEMP_EROR
};

enum{
	WATER_OUT_CLOSE,
	WATER_OUT_OPEN
};

static bool timeout_temp[MAX_SYSTEM] = {0};
static bool timeout_flow[MAX_SYSTEM] = {0};
static bool timeout_water_level[MAX_SYSTEM] = {0};
static uint32_t timeout_temp_id[MAX_SYSTEM];
static uint32_t timeout_flow_id[MAX_SYSTEM];
static uint32_t timeout_water_level_id[MAX_SYSTEM];
static uint32_t counter_temp[MAX_SYSTEM] = {0};
static uint32_t counter_flow[MAX_SYSTEM] = {0};
static uint32_t counter_water_level[MAX_SYSTEM] = {0};
static uint8_t MSG_temp[MAX_SYSTEM][50] = {'\0'};
static uint8_t MSG_flow[MAX_SYSTEM][50] = {'\0'};
static uint8_t MSG_water[MAX_SYSTEM][50] = {'\0'};

static uint8_t temp_state[MAX_SYSTEM];
static uint8_t water_state[MAX_SYSTEM];
static uint8_t flow_state[MAX_SYSTEM];
static uint8_t system_state[MAX_SYSTEM];

static bool flag_liter[MAX_SYSTEM];
static uint32_t liter[MAX_SYSTEM];

static void timeout_temp0(){timeout_temp[SYSTEM0] = true;}
static void timeout_temp1(){timeout_temp[SYSTEM1] = true;}
static void timeout_flow0(){timeout_flow[SYSTEM0] = true;}
static void timeout_flow1(){timeout_flow[SYSTEM1] = true;}
static void timeout_water_level0(){timeout_water_level[SYSTEM0] = true;}
static void timeout_water_level1(){timeout_water_level[SYSTEM1] = true;}

static void TEMP_init(uint8_t id);
static void TEMP_hot(uint8_t id);
static void TEMP_too_hot(uint8_t id);
static void TEMP_not_hot_enough(uint8_t id);
static void TEMP_cool(uint8_t id);
static void TEMP_error(uint8_t id);
static void TEMP_check(uint8_t id);

static void FLOW_init(uint8_t id);
static void FLOW_normal(uint8_t id);
static void FLOW_not_flowing(uint8_t id);
static void FLOW_leaking(uint8_t id);
static void FLOW_check(uint8_t id);

static void WATER_LEVEL_init(uint8_t id);
static void WATER_LEVEL_normal(uint8_t id);
static void WATER_LEVEL_empty(uint8_t id);
static void WATER_LEVEL_overflow(uint8_t id);
static void WATER_LEVEL_error(uint8_t id);
static void WATER_LEVEL_check(uint8_t id);

static void WATER_OUT_open(uint8_t id);
static void WATER_OUT_close(uint8_t id);
static void WATER_OUT_system(uint8_t id);

void SYSTEM_init(){
	for(uint8_t i = 0; i < MAX_SYSTEM; i++){
		waterout[i].set_relay(DEVICE_CLOSE);
		waterout[i].set_solenoid_in(DEVICE_CLOSE);
		waterout[i].set_solenoid_out(DEVICE_CLOSE);
		BOILING_OFF(i);
		WT_EMPTY_OFF(i);
	}
}

void SYSTEM_output_water(uint8_t _liter, uint8_t id){
	flag_liter[id] = 1;
	liter[id] = _liter;
}

void SYSTEM_check(){
	FLOW_get_pulse();
	for(uint8_t i = 0; i <  MAX_SYSTEM ; i++){
		TEMP_check(i);
		FLOW_check(i);
		//WATER_LEVEL_check(i);
	}
}
void SYSTEM_run(){
	for(uint8_t i = 0; i <  MAX_SYSTEM ; i++){
		WATER_OUT_system(i);
	}
}

static void TEMP_check(uint8_t id){
	switch (temp_state[id]) {
		case TEMP_INIT:
			TEMP_init(id);
			break;
		case TEMP_HOT:
			TEMP_hot(id);
			break;
		case TEMP_TOO_HOT:
			TEMP_too_hot(id);
			break;
		case TEMP_NOT_HOT_ENOUGH:
			TEMP_not_hot_enough(id);
			break;
		case TEMP_COOL:
			TEMP_cool(id);
			break;
		case TEMP_EROR:
			TEMP_error(id);
			break;
		default:
			break;
	}
}

static void FLOW_check(uint8_t id){
	switch (flow_state[id]) {
		case FLOW_INIT:
			FLOW_init(id);
			break;
		case FLOW_NORMAL:
			FLOW_normal(id);
			break;
		case NOT_FLOWING:
			FLOW_not_flowing(id);
			break;
		case LEAKING:
			FLOW_leaking(id);
			break;
		default:
			break;
	}
}

static void WATER_LEVEL_check(uint8_t id){
	switch (water_state[id]) {
		case WATER_INIT:
			WATER_LEVEL_init(id);
			break;
		case WATER_NORMAL:
			WATER_LEVEL_normal(id);
			break;
		case WATER_EMPTY:
			WATER_LEVEL_empty(id);
			break;
		case WATER_OVERFLOW:
			WATER_LEVEL_overflow(id);
			break;
		case WATER_EROR:
			WATER_LEVEL_error(id);
			break;
		default:
			break;
	}
}

static void WATER_OUT_system(uint8_t id){
	switch (system_state[id]) {
		case WATER_OUT_CLOSE:
			WATER_OUT_close(id);
			break;
		case WATER_OUT_OPEN:
			WATER_OUT_open(id);
			break;
		default:
			break;
	}
}

static void TEMP_init(uint8_t id){
	void (*fn)(void) = (id == SYSTEM0) ? timeout_temp0 : timeout_temp1;
	timeout_temp_id[id] = SCH_Add_Task(fn, CHECK_TEMP_DURATION, CHECK_TEMP_DURATION);
	temp_state[id] =TEMP_HOT;
}
static void TEMP_hot(uint8_t id){
	if(timeout_temp[id]){
		UART_send(UART_3, "HOT\n", sizeof("HOT\n"));
		timeout_temp[id] = false;
		if (waterout[id].temp() > 100) {
			temp_state[id] = TEMP_TOO_HOT;
			waterout[id].set_relay(DEVICE_CLOSE);
			counter_temp[id] = 0;
		}else if(waterout[id].temp() < 85 && waterout[id].temp() >= 50 ){
			temp_state[id] = TEMP_NOT_HOT_ENOUGH;
			counter_temp[id] = 0;
		}else if(waterout[id].temp() < 50){
			temp_state[id] = TEMP_COOL;
			counter_temp[id] = 0;
		}
	}
}
static void TEMP_too_hot(uint8_t id){
	if(timeout_temp[id]){
		UART_send(UART_3, "TOO HOT\n", sizeof("TOO HOT\n"));
		timeout_temp[id] = false;
		if(waterout[id].temp() < 95) {
			temp_state[id] = TEMP_HOT;
		}else{
			counter_temp[id]++;
		}

		if(counter_temp[id] >= MAX_COUNTS){
			temp_state[id] = TEMP_EROR;
			waterout[id].set_relay(DEVICE_CLOSE);
			sprintf(MSG_temp[id],"%s%d%s","ERROR TEMP ",id,": TOO HOT\n");
		}
	}
}
static void TEMP_cool(uint8_t id){

	if(water_state[id] == WATER_EMPTY || water_state[id] == WATER_EROR){
		counter_temp[id] = 0;
		waterout[id].set_relay(DEVICE_CLOSE);
	}else{
		waterout[id].set_relay(DEVICE_OPEN);
	}
	if(timeout_temp[id]){
		UART_send(UART_3, "COOL\n", sizeof("COOL\n"));
		timeout_temp[id] = false;
		if(waterout[id].temp() > 50){
			temp_state[id] = TEMP_NOT_HOT_ENOUGH;
			waterout[id].set_relay(DEVICE_OPEN);
			counter_temp[id] = 0;
		}else{
			counter_temp[id]++;
		}
		if(counter_temp[id] >= MAX_COUNTS){
			temp_state[id] = TEMP_EROR;
			waterout[id].set_relay(DEVICE_CLOSE);
			sprintf(MSG_temp[id],"%s%d%s","ERROR TEMP ",id,": TOO COOL\n");
		}
	}
}
static void TEMP_not_hot_enough(uint8_t id){

	if(water_state[id] == WATER_EMPTY || water_state[id] == WATER_EROR){
		waterout[id].set_relay(DEVICE_CLOSE);
	}else{
		waterout[id].set_relay(DEVICE_OPEN);
	}
	if(timeout_temp[id]){
		UART_send(UART_3, "NOT HOT\n", sizeof("NOT HOT\n"));
		timeout_temp[id] = false;
		if(waterout[id].temp() > 90){
			temp_state[id] = TEMP_HOT;
			waterout[id].set_relay(DEVICE_CLOSE);
			counter_temp[id] = 0;
		}
		else if(waterout[id].temp() < 50){
			temp_state[id] = TEMP_COOL;
		}
	}
}
static void TEMP_error(uint8_t id){

	if(timeout_temp[id]){
		UART_send(UART_3, "ER\n", sizeof("ER\n"));
		timeout_temp[id] = false;
		UART_send(UART_3, MSG_temp[id], sizeof(MSG_temp[id]));
		if(waterout[id].temp() > 65 && waterout[id].temp() < 80){
			temp_state[id] = TEMP_HOT;
		}
	}
}

static void FLOW_init(uint8_t id){
	void (*fn)(void) = (id == SYSTEM0) ? timeout_flow0 : timeout_flow1;
	timeout_flow_id[id] = SCH_Add_Task(fn, CHECK_FLOWING_DURATION, CHECK_FLOWING_DURATION);
	flow_state[id] = FLOW_NORMAL;
}
static void FLOW_normal(uint8_t id){
	if(timeout_flow[id]){
		timeout_flow[id] = false;
		if(waterout[id].flow() && (system_state[id] == WATER_OUT_CLOSE)){
			flow_state[id] = LEAKING;
			sprintf(MSG_flow[id],"%s%d%s","ERROR FLOW ", id, ": WATER LEAKING\r\n");
		}
		if((!waterout[id].flow()) && (system_state[id] == WATER_OUT_OPEN)){
			flow_state[id] = NOT_FLOWING;
			sprintf(MSG_flow[id],"%s%d%s","ERROR FLOW ", id, ": WATER NOT FLOWING\r\n");
		}
	}
}
static void FLOW_not_flowing(uint8_t id){
	if(timeout_flow[id]){
		timeout_flow[id] = false;
		UART_send(UART_3, MSG_flow[id], sizeof(MSG_flow[id]));
		if(waterout[id].flow() && (system_state[id] == WATER_OUT_CLOSE)){
			SCH_Delete_Task(timeout_flow_id[id]);
			flow_state[id] = LEAKING;
			sprintf(MSG_flow[id],"%s%d%s","ERROR FLOW ", id, ": WATER LEAKING\r\n");
		}
		if((!waterout[id].flow() && (system_state[id] == WATER_OUT_CLOSE)) ||
			(waterout[id].flow()) && (system_state[id] == WATER_OUT_OPEN)){
			flow_state[id] = FLOW_NORMAL;
		}

	}
}
static void FLOW_leaking(uint8_t id){
	if(timeout_flow[id]){
		timeout_flow[id] = false;
		UART_send(UART_3, MSG_flow[id], sizeof(MSG_flow[id]));
		if((!waterout[id].flow()) && (system_state[id] == WATER_OUT_OPEN)){
			SCH_Delete_Task(timeout_flow_id[id]);
			flow_state[id] = NOT_FLOWING;
			sprintf(MSG_flow[id],"%s%d%s","ERROR FLOW ", id, ": WATER NOT FLOWING\r\n");
		}
		if((!waterout[id].flow() && (system_state[id] == WATER_OUT_CLOSE)) ||
			(waterout[id].flow()) && (system_state[id] == WATER_OUT_OPEN)){
			flow_state[id] = FLOW_NORMAL;
		}
	}
}

static void WATER_LEVEL_init(uint8_t id){
	void (*fn)(void) = (id == SYSTEM0) ? timeout_water_level0 : timeout_water_level1;
	timeout_water_level_id[id] = SCH_Add_Task(fn, CHECK_WATER_LEVEL_DURATION , CHECK_WATER_LEVEL_DURATION );
	water_state[id] = WATER_NORMAL;
}
static void WATER_LEVEL_normal(uint8_t id){
	if(timeout_water_level[id]){
		timeout_water_level[id] = false;
		if (waterout[id].water_level_0() == GPIO_PIN_RESET && waterout[id].water_level_1() == GPIO_PIN_RESET) {
			water_state[id] = WATER_EMPTY;
			waterout[id].set_solenoid_in(DEVICE_OPEN);
			counter_water_level[id] = 0;
		}
	}
}
static void WATER_LEVEL_empty(uint8_t id){
	if(timeout_water_level[id]){
		timeout_water_level[id] = false;
		if(waterout[id].water_level_0() == GPIO_PIN_SET && waterout[id].water_level_1() == GPIO_PIN_SET) {
			water_state[id] = WATER_NORMAL;
			waterout[id].set_solenoid_in(DEVICE_CLOSE);
			counter_water_level[id] = 0;
		}else{
			counter_water_level[id]++;
		}
		if(counter_water_level[id] >= MAX_COUNTS){
			sprintf(MSG_water[id],"%s%d%s","ERROR SOLENOID IN ", id, ": NO WATER IN\r\n");
			water_state[id] = WATER_EROR;
			waterout[id].set_solenoid_in(DEVICE_OPEN);
		}
	}
}
static void WATER_LEVEL_overflow(uint8_t id){
	// DONT KNOW WHAT TO DO
}
static void WATER_LEVEL_error(uint8_t id){
	if(timeout_water_level[id]){
		timeout_water_level[id] = false;
		UART_send(UART_3, MSG_water[id], sizeof(MSG_water[id]));
		if(waterout[id].water_level_0() == GPIO_PIN_SET && waterout[id].water_level_1() == GPIO_PIN_SET) {
			water_state[id] = WATER_NORMAL;
			waterout[id].set_solenoid_in(DEVICE_CLOSE);
			counter_water_level[id] = 0;
		}
	}
}
static void WATER_OUT_open(uint8_t id){
	if(FLOW_is_enough_water(id)){
		system_state[id] = WATER_OUT_CLOSE;
		waterout[id].set_solenoid_out(DEVICE_CLOSE);
		UART_send(UART_3, "DU NUOC\n", sizeof("DU NUOC\n"));
	}
}
static void WATER_OUT_close(uint8_t id){
	if(flag_liter[id]){
		if((water_state[id] != WATER_EMPTY && water_state[id] != WATER_EROR) && (temp_state[id] != TEMP_COOL  && temp_state[id] != TEMP_EROR)){
			flag_liter[id] = false;
			FLOW_set_liter(id, liter[id]);
			system_state[id] = WATER_OUT_OPEN;
			waterout[id].set_solenoid_out(DEVICE_OPEN);
			UART_send(UART_3, "MO VOI\n", sizeof("MO VOI\n"));
		}
	}
}
