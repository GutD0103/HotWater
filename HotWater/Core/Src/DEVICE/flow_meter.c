/*
 * flow_meter.c
 *
 *  Created on: Jul 31, 2023
 *      Author: ntdat
 */
#include "DEVICE/flow_meter.h"
#include "HAL/uart.h"

#define PPL  1 //5880 // pulse for 1 liter
#define MAX_WATEROUT 2

static uint64_t toltal_pulse[MAX_WATEROUT] = {0};
static uint64_t toltal_pulse1[MAX_WATEROUT] = {0};
static uint64_t toltal_pulse2[MAX_WATEROUT] = {0};
static uint64_t pulse[MAX_WATEROUT] = {0};
static bool flag[MAX_WATEROUT] = {0};
static bool pre[MAX_WATEROUT] = {0};
static bool cur[MAX_WATEROUT] = {0};


void FLOW_get_pulse(){
	for(uint8_t index = 0; index < MAX_WATEROUT;index++){
		pre[index] = cur[index];
		cur[index] = (index == 0) ? FLOW0_STATE :  FLOW1_STATE ;
		if(cur[index] == 1 && pre[index] == 0)
		{
			toltal_pulse[index]++;
			toltal_pulse1[index]++;
			if(pulse[index] > 0){
				pulse[index]--;
				char msg[50] = {'\0'};
				sprintf(msg,"%d\n" ,pulse[index]);
				UART_send(UART_3, msg, sizeof(msg));
				if(pulse[index] == 0){
					flag[index] = 1;
				}
			}
		}
	}
}
bool FLOW_is_flowing(uint8_t index){
	if(index < 0 || index >= MAX_WATEROUT){
		return 0;
	}
	if((toltal_pulse1[index] - toltal_pulse2[index]) >= 10){
		toltal_pulse1[index] = 0;
		toltal_pulse2[index] = 0;
		return 1;
	}
	toltal_pulse1[index] = 0;
	toltal_pulse2[index] = 0;
	return 0;
}
bool FLOW_is_enough_water(uint8_t index){
	if(index < 0 || index >= MAX_WATEROUT){
		return 0;
	}
	if(flag[index] == 1){
		flag[index] = 0;
		return 1;
	}
	return 0;
}
void FLOW_set_liter(uint8_t index, uint64_t milliliter)
{
	if(milliliter <= 0){
		return;
	}
	uint64_t num_pulse = milliliter * 1;
	char msg[50] = {'\0'};
	sprintf(msg,"%d\n" ,milliliter);
	UART_send(UART_3, msg, sizeof(msg));
	pulse[index] = num_pulse;
	flag[index] = 0;
}
int fn_pulse(uint8_t index){
	return toltal_pulse[index];
}
