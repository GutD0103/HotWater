/*
 * RingBuffer.h
 *
 *  Created on: Jul 23, 2023
 *      Author: ntdat
 */

#ifndef INC_RINGBUFFER_H_
#define INC_RINGBUFFER_H_

#include "stdio.h"
#include "stdbool.h"
#include "stdint.h"

#define BUFFER_MAX_SIZE     2048

typedef struct {
	uint8_t buffer[BUFFER_MAX_SIZE];
	size_t head;
	size_t tail;
	size_t count;
	uint16_t size;
}ring_buffer_t;

/**
 * @brief Initialize Buffer
 *
 * @param buffer Pointer to Buffer Object
 * @param sizeOfObject Size of Object
 * @return true if OK
 * @return false if Failed
 */
bool ring_buffer_init(ring_buffer_t * buffer, uint16_t sizeOfObject);

/**
 * @brief Push data to Buffer
 *
 * @param buffer Pointer to Buffer
 * @param data Pointer to data in
 * @param data_size Data Size
 * @return true if OK
 * @return false if Failed
 */
bool ring_buffer_push(ring_buffer_t * buffer, void * object);

/**
 * @brief Pop data from Buffer
 *
 * @param buffer Pointer to Buffer
 * @param data Pointer to data out
 * @param data_size Data size
 * @return true If OK
 * @return false If failed
 */
bool ring_buffer_pop(ring_buffer_t  * buffer, void *object);


/**
 * @brief Check Buffer is available or not
 *
 * @param buffer Pointer to buffer
 * @return true if buffer available
 * @return false if buffer not available
 */
bool ring_buffer_is_available(ring_buffer_t * buffer);

/**
 * @brief Peek Element at Index
 *
 * @param buffer Pointer to Netif Buffer Object
 * @param idx Index of Data in buffer->buffer
 * @return uint8_t* Pointer to Data[index]
 */
bool ring_buffer_peek_idx(ring_buffer_t * buffer, size_t idx, void *object);

bool ring_buffer_is_full(ring_buffer_t * buffer);

bool ring_buffer_drop_all(ring_buffer_t * buffer);


#endif /* INC_RINGBUFFER_H_ */
