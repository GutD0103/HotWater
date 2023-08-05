/*
 * fsm.h
 *
 *  Created on: Jul 23, 2023
 *      Author: ntdat
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "HAL/uart.h"
#include "HAL/timer.h"
#include "DEVICE/hotwater.h"
#include "scheduler.h"

#define START 			0x21
#define END   			0x23
#define INIT 			0
#define GET				1

void fsm_run(void);

#endif /* INC_FSM_H_ */
