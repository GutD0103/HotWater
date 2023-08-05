/*
 * timer.h
 *
 *  Created on: Jul 24, 2023
 *      Author: ntdat
 */

#ifndef INC_HAL_TIMER_H_
#define INC_HAL_TIMER_H_

#include "stdbool.h"
#include "scheduler.h"

typedef void (*TIMER_fn)(void);

bool TIM_init();
int isTimer_timeout(int index);
void setTimer(int index, int duration);

#endif /* INC_HAL_TIMER_H_ */
