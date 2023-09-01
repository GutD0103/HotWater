/*
 * water_level.c
 *
 *  Created on: Jul 31, 2023
 *      Author: ntdat
 */
#include "DEVICE/water_level.h"

bool level0[2] = {0};
bool level1[2] = {0};


float WATER_get_water_level(uint8_t id)
{
	if(id < 0 || id > 2) return -1;

	uint8_t newid = (id == 0) ? 1 : 3;
	uint32_t temp = Read_ADC(newid);
		// TO DO
	return (float)(temp);
}
