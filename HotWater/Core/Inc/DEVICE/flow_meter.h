/*
 * flow_meter.h
 *
 *  Created on: Jul 31, 2023
 *      Author: ntdat
 */

#ifndef INC_DEVICE_FLOW_METER_H_
#define INC_DEVICE_FLOW_METER_H_

#include <stdint.h>
#include <HAL/adc.h>
#include "port.h"

void FLOW_get_pulse();
void FLOW_set_liter(uint8_t id, uint64_t milliliter);
bool FLOW_is_enough_water(uint8_t id);
bool FLOW_is_flowing(uint8_t id);
int fn_pulse(uint8_t id);
#endif /* INC_DEVICE_FLOW_METER_H_ */
