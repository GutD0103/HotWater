/*
 * ntc.c
 *
 *  Created on: Jul 27, 2023
 *      Author: ntdat
 */
#include "DEVICE/ntc.h"

float get_temp(uint8_t id)
{
	if(id < 0 || id > 2) return -1;

	uint8_t newid = (id == 0) ? 0 : 2;
	uint32_t temp = Read_ADC(newid);
	// TO DO
	return (float)(temp);
}
