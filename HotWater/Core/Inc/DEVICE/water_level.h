/*
 * water_level.h
 *
 *  Created on: Jul 31, 2023
 *      Author: ntdat
 */

#ifndef INC_DEVICE_WATER_LEVEL_H_
#define INC_DEVICE_WATER_LEVEL_H_

#include <stdint.h>
#include <HAL/adc.h>


float WATER_get_water_level(uint8_t id);

#endif /* INC_DEVICE_WATER_LEVEL_H_ */
