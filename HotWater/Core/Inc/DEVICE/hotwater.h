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

#define RELAY1_ON   			HAL_GPIO_WritePin(RELAY1_GPIO_Port, RELAY1_Pin, GPIO_PIN_SET)
#define RELAY1_OFF  			HAL_GPIO_WritePin(RELAY1_GPIO_Port, RELAY1_Pin, GPIO_PIN_RESET)
#define RELAY1_STATE 			HAL_GPIO_ReadPin(RELAY1_GPIO_Port, RELAY1_Pin)

#define RELAY2_ON   			HAL_GPIO_WritePin(RELAY2_GPIO_Port, RELAY2_Pin, GPIO_PIN_SET)
#define RELAY2_OFF  			HAL_GPIO_WritePin(RELAY2_GPIO_Port, RELAY2_Pin, GPIO_PIN_RESET)
#define RELAY2_STATE 			HAL_GPIO_ReadPin(RELAY2_GPIO_Port, RELAY2_Pin)

#define SOLENOID1_OPEN   		HAL_GPIO_WritePin(SOLENOID1_GPIO_Port, SOLENOID1_Pin, GPIO_PIN_SET)
#define SOLENOID1_CLOSE   		HAL_GPIO_WritePin(SOLENOID1_GPIO_Port, SOLENOID1_Pin, GPIO_PIN_RESET)
#define SOLENOID1_STATE 		HAL_GPIO_ReadPin(SOLENOID1_GPIO_Port, SOLENOID1_Pin)

#define SOLENOID2_OPEN   		HAL_GPIO_WritePin(SOLENOID2_GPIO_Port, SOLENOID2_Pin, GPIO_PIN_SET)
#define SOLENOID2_CLOSE   		HAL_GPIO_WritePin(SOLENOID2_GPIO_Port, SOLENOID2_Pin, GPIO_PIN_RESET)
#define SOLENOID2_STATE 		HAL_GPIO_ReadPin(SOLENOID2_GPIO_Port, SOLENOID2_Pin)


typedef float (* get_temp_ptr)(uint8_t);
typedef float (* get_water_level_ptr)(uint8_t);
typedef float (* get_flow_ptr)(uint8_t);

typedef struct{
	float temp;
	float water_level;
	float flow;
	uint8_t solenoid;
	uint8_t relay;
}water_out1;

typedef struct{
	get_temp_ptr temp;
	get_water_level_ptr water_level;
	get_flow_ptr flow;
	uint8_t solenoid;
	uint8_t relay;
}water_out2;

#endif /* INC_DEVICE_HOTWATER_H_ */
