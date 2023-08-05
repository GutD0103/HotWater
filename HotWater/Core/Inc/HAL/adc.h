/*
 * adc.h
 *
 *  Created on: Aug 1, 2023
 *      Author: ntdat
 */

#ifndef INC_HAL_ADC_H_
#define INC_HAL_ADC_H_

#include "main.h"
#include <stdint.h>
#include <stdbool.h>

bool ADC_init(void);
uint32_t Read_ADC(int id);

#endif /* INC_HAL_ADC_H_ */
