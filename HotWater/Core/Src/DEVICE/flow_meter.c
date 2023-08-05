/*
 * flow_meter.c
 *
 *  Created on: Jul 31, 2023
 *      Author: ntdat
 */
#include "DEVICE/flow_meter.h"

#define PPL 450 // pulse for 1 liter

static uint64_t toltal_pulse = 0;
static uint64_t pulse[2] = {0};
static bool pre[2] = {0};
static bool cur[2] = {0};

void get_pulse(int index){
	pre[index] = cur[index];
	cur[index] = (index == 0) ? HAL_GPIO_ReadPin(FLOW1_GPIO_Port, FLOW1_Pin) : HAL_GPIO_ReadPin(FLOW2_GPIO_Port, FLOW2_Pin);
	if(cur[index] == 1 && pre[index] == 0)
	{
		pulse[index] ++;
		toltal_pulse++;
	}
}

float get_flow_meter(uint8_t id)
{
	float V = pulse[id] / PPL;
	pulse[id] = 0;
	return V;
}
