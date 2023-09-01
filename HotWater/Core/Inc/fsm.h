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
#include "DEVICE/port.h"


#define INIT 			0
#define GET				1

void fsm_run(void);

#endif /* INC_FSM_H_ */
