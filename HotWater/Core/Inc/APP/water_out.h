/*
 * water_out.h
 *
 *  Created on: Aug 18, 2023
 *      Author: ntdat
 */

#ifndef INC_APP_WATER_OUT_H_
#define INC_APP_WATER_OUT_H_

#include "HAL/uart.h"
#include "HAL/timer.h"
#include "DEVICE/hotwater.h"
#include "scheduler.h"
#include "DEVICE/port.h"

void SYSTEM_init();
void SYSTEM_check();
void SYSTEM_run();
void SYSTEM_output_water(uint8_t _liter, uint8_t id);

#endif /* INC_APP_WATER_OUT_H_ */
