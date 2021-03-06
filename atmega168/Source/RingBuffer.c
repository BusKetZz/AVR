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

static struct ring_buffer_t arrayOfRingBuffers[RING_BUFFERS_AMOUNT];



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
                arrayOfRingBuffers[usedRingBuffers].head = 0;
                arrayOfRingBuffers[usedRingBuffers].tail = 0;
                arrayOfRingBuffers[usedRingBuffers].buffer = 
                attributes->buffer;
                arrayOfRingBuffers[usedRingBuffers].sizeOfElement = 
                attributes->sizeOfElement;
                arrayOfRingBuffers[usedRingBuffers].numberOfElements =
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
        (RingBuffer_IsFull(&arrayOfRingBuffers[indexer]) == 0))
    {
        const uint8_t offset = (arrayOfRingBuffers[indexer].head & 
                               (arrayOfRingBuffers[indexer].numberOfElements-1) 
                               ) * arrayOfRingBuffers[indexer].sizeOfElement;

        memcpy(&(arrayOfRingBuffers[indexer].buffer[offset]), data, 
               arrayOfRingBuffers[indexer].sizeOfElement);

        arrayOfRingBuffers[indexer].head++;
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
       (RingBuffer_IsEmpty(&arrayOfRingBuffers[indexer]) == 0))
    {
        const uint8_t offset = (arrayOfRingBuffers[indexer].tail & 
                               (arrayOfRingBuffers[indexer].numberOfElements-1)
                               ) * arrayOfRingBuffers[indexer].sizeOfElement;
                                
        memcpy(data, &(arrayOfRingBuffers[indexer].buffer[offset]), 
               arrayOfRingBuffers[indexer].sizeOfElement);

        arrayOfRingBuffers[indexer].tail++;
    }
    else
    {
        error = -1;
    }

    return error;
}
