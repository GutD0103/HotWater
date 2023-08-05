/*
 * uart.h
 *
 *  Created on: Jul 23, 2023
 *      Author: ntdat
 */

#ifndef INC_HAL_UART_H_
#define INC_HAL_UART_H_

#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "RingBuffer.h"

typedef enum {
	UART_1,
	UART_2,
	UART_3,
	UART_4,
	UART_MAX
}UART_id_t;

extern int flag_uart[UART_MAX];

bool UART_init();
bool UART_send(UART_id_t id, uint8_t *data , size_t len);
bool UART_receive_available(UART_id_t id);
uint8_t UART_receive_data(UART_id_t id);
void UART_clear_buffer(UART_id_t id);

#endif /* INC_HAL_UART_H_ */
