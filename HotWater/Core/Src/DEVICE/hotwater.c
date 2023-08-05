/*
 * hotwater.c
 *
 *  Created on: Jul 26, 2023
 *      Author: ntdat
 */


#include "DEVICE/hotwater.h"

water_out1 out1 ={
		.flow = 0,
		.relay = 0,
		.solenoid = 0,
		.temp = 0,
		.water_level = 0
};

water_out2 out2 ={
		.flow = &get_flow_meter,
		.relay = 0,
		.solenoid = 0,
		.temp = &get_temp,
		.water_level = &get_water_level
};
