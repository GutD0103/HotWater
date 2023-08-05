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

float get_flow_meter(uint8_t id);

#endif /* INC_DEVICE_FLOW_METER_H_ */
