/*
 * hotwater.h
 *
 *  Created on: Jul 26, 2023
 *      Author: ntdat
 */

#ifndef INC_DEVICE_HOTWATER_H_
#define INC_DEVICE_HOTWATER_H_

#include <stdint.h>
#include "main.h"
#include "DEVICE/ntc.h"
#include "DEVICE/flow_meter.h"
#include "DEVICE/water_level.h"

#define DEVICE_OPEN  	GPIO_PIN_RESET
#define DEVICE_CLOSE  	GPIO_PIN_SET

#define WT_LV_EMPTY    GPIO_PIN_RESET
#define WT_LV_FULL	   GPIO_PIN_SET

typedef float (* GetTemp)(void);
typedef bool (* GetFlow)(void);
typedef GPIO_PinState (*GPIO_ReadPinFunction)(void);
typedef void (*GPIO_WritePinFunction)(GPIO_PinState);

typedef struct{
	float temp;
	float water_level;
	float flow;
	uint8_t solenoid;
	uint8_t relay;
}water_out1;

typedef struct{
	GetTemp temp;
	GetFlow flow;
	GPIO_ReadPinFunction get_solenoid_out;
	GPIO_ReadPinFunction get_relay;
	GPIO_ReadPinFunction water_level_0;
	GPIO_ReadPinFunction water_level_1;
	GPIO_WritePinFunction set_solenoid_out;
	GPIO_WritePinFunction set_solenoid_in;
	GPIO_WritePinFunction set_relay;

}WaterOut;
extern WaterOut waterout[2];


// TESTING

void set_wt(bool value, int lv);

#endif /* INC_DEVICE_HOTWATER_H_ */
