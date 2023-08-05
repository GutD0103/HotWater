/*
 * RingBuffer.c
 *
 *  Created on: Jul 23, 2023
 *      Author: ntdat
 */




#include "RingBuffer.h"

#include "string.h"


bool ring_buffer_init(ring_buffer_t * buffer, uint16_t sizeOfObject)
{
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;
    buffer->size = sizeOfObject;
    memset(buffer->buffer , 0, sizeof(buffer->buffer));
    return true;
}

bool ring_buffer_push(ring_buffer_t * buffer, void * object)
{
	uint8_t *data = (uint8_t *)(object);

	if(ring_buffer_is_full(buffer)){
			return false;
	}

	for(size_t index = 0; index < buffer -> size; index++)
	{
		buffer->buffer[buffer->head] = data[index];
		buffer->head = (buffer->head + 1) % BUFFER_MAX_SIZE;
	}
	return true;
}

bool ring_buffer_pop(ring_buffer_t  * buffer, void *object)
{
	uint8_t *data = (uint8_t *)(object);

	if(!ring_buffer_is_available(buffer)){
			return false;
	}

	for(size_t index = 0; index < buffer -> size; index++)
	{
		data[index] = buffer->buffer[buffer->tail];
		buffer->tail = (buffer->tail + 1) % BUFFER_MAX_SIZE;
	}
	return true;
}

bool ring_buffer_is_available(ring_buffer_t * buffer)
{
	if(buffer->head >= buffer->tail)
	{
		return ((buffer->head - buffer->tail) >= buffer->size);
	}
	else
	{
		return (BUFFER_MAX_SIZE - (buffer->tail - buffer->head) >= buffer->size);
	}
}

bool ring_buffer_peek_idx(ring_buffer_t * buffer, size_t idx, void *object)
{
	if(idx*buffer->size > buffer->head || idx*buffer->size < buffer->tail || idx*buffer->size < 0 || idx*buffer->size >= BUFFER_MAX_SIZE)
	{
		return false;
	}

	memcpy(object, buffer->buffer + idx*buffer->size, buffer->size);
	return true;
}

bool ring_buffer_is_full(ring_buffer_t * buffer)
{
	if(buffer->head >= buffer->tail)
	{
		return (BUFFER_MAX_SIZE - (buffer->head - buffer->tail) <= buffer->size);
	}
	else
	{
		return ((buffer->tail - buffer->head) <= buffer->size);
	}
}

bool ring_buffer_drop_all(ring_buffer_t * buffer)
{
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;
    memset(buffer->buffer , 0, sizeof(buffer->buffer));
    return true;
}
