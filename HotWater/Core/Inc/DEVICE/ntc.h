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

float get_temp(uint8_t id);

#endif /* INC_DEVICE_NTC_H_ */
