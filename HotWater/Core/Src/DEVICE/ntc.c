/*
 * ntc.c
 *
 *  Created on: Jul 27, 2023
 *      Author: ntdat
 */
#include "DEVICE/ntc.h"

static float _temp = 0;

float TEMP_get_temp(uint8_t id)
{
	if(id < 0 || id > 1) return -1;

//	uint32_t temp = Read_ADC(id);
	// TO DO

//	return (float)(temp);
	return (float)(_temp);
}

void set_temp(uint32_t value){
	_temp = value;
}
