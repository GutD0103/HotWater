/*
 * ntc.h
 *
 *  Created on: Jul 29, 2023
 *      Author: ntdat
 */

#ifndef INC_DEVICE_NTC_H_
#define INC_DEVICE_NTC_H_

#include <stdint.h>
#include <HAL/adc.h>

float TEMP_get_temp(uint8_t id);
void set_temp(uint32_t value);

#endif /* INC_DEVICE_NTC_H_ */
