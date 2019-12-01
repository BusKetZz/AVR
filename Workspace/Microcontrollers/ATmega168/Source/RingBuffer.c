/**
 * File: RingBuffer.c
 * 
 * Author: Jakub Standarski
 * 
 * Date: 01.12.2019
 */

#include "RingBuffer.h"

#include <stdint.h>
#include <string.h>



/*****************************************************************************/
/*                             PRIVATE DEFINES                               */
/*****************************************************************************/

#define RING_BUFFERS_AMOUNT     1

#define FULL        1
#define NOT_FULL    0

#define EMPTY       1
#define NOT_EMPTY   0



/*****************************************************************************/
/*                           PRIVATE STRUCTURES                              */
/*****************************************************************************/

struct ring_buffer_t
{
    uint8_t sizeOfElement;
    uint8_t numberOfElements;
    uint8_t *buffer;
    volatile uint8_t head;
    volatile uint8_t tail;
};



/*****************************************************************************/
/*                           PRIVATE VARIABLES                               */
/*****************************************************************************/

static struct ring_buffer_t ringBuffer[RING_BUFFERS_AMOUNT];



/*****************************************************************************/
/*                       PRIVATE FUNCTIONS DEFINITIONS                       */
/*****************************************************************************/

static inline int RingBuffer_IsFull(struct ring_buffer_t *ringBuffer)
{
    return ((ringBuffer->head - ringBuffer->tail) == 
             ringBuffer->numberOfElements) ? FULL : NOT_FULL;
}



static inline int RingBuffer_IsEmpty(struct ring_buffer_t *ringBuffer)
{
    return ((ringBuffer->head - ringBuffer->tail) == 0U) ? EMPTY : NOT_EMPTY;
}



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DEFINITIONS                        */
/*****************************************************************************/

int RingBuffer_Init(ring_buffer_indexer_t *indexer, 
                    ring_buffer_attributes_t *attributes)
{
    static uint8_t usedRingBuffers = 0;
    int error = -1;

    if((usedRingBuffers < RING_BUFFERS_AMOUNT) && (indexer != NULL) && 
       (attributes != NULL))
    {
        if((attributes->buffer != NULL) && (attributes->sizeOfElement > 0))
        {
            /* Check that number of elements in a ring buffer is power of 2 */
            if(((attributes->numberOfElements - 1) & 
                 attributes->numberOfElements) == 0)
            {
                ringBuffer[usedRingBuffers].head = 0;
                ringBuffer[usedRingBuffers].tail = 0;
                ringBuffer[usedRingBuffers].buffer = attributes->buffer;
                ringBuffer[usedRingBuffers].sizeOfElement = 
                attributes->sizeOfElement;
                ringBuffer[usedRingBuffers].numberOfElements =
                attributes->numberOfElements;

                *indexer = usedRingBuffers++;
                error = 0;
            }
        }
    }

    return error;
}



int RingBuffer_Put(ring_buffer_indexer_t indexer, const void *data)
{
    int error = 0;

    if((indexer < RING_BUFFERS_AMOUNT) && 
        (RingBuffer_IsFull(&ringBuffer[indexer]) == 0))
    {
        const uint8_t offset = (ringBuffer[indexer].head & 
                               (ringBuffer[indexer].numberOfElements - 1)) *
                                ringBuffer[indexer].sizeOfElement;
        memcpy(&(ringBuffer[indexer].buffer[offset]), data, 
                 ringBuffer[indexer].sizeOfElement);
        ringBuffer[indexer].head++;
    }
    else
    {
        error = -1;
    }

    return error;
}



int RingBuffer_Get(ring_buffer_indexer_t indexer, void *data)
{
    int error = 0;

    if((indexer < RING_BUFFERS_AMOUNT) && 
       (RingBuffer_IsEmpty(&ringBuffer[indexer]) == 0))
    {
        const uint8_t offset = (ringBuffer[indexer].tail & 
                               (ringBuffer[indexer].numberOfElements - 1)) * 
                                ringBuffer[indexer].sizeOfElement;
        memcpy(data, &(ringBuffer[indexer].buffer[offset]), 
               ringBuffer[indexer].sizeOfElement);
        ringBuffer[indexer].head++;
    }
    else
    {
        error = -1;
    }

    return error;
}
