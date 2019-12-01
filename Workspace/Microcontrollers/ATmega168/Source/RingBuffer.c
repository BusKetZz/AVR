/**
 * File: RingBuffer.c
 * 
 * Author: Jakub Standarski
 * 
 * Date: 01.12.2019
 */

#include "RingBuffer.h"

#include <stdint.h>



/*****************************************************************************/
/*                             PRIVATE DEFINES                               */
/*****************************************************************************/

#define RING_BUFFERS_AMOUNT     1


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
             ringBuffer->numberOfElements) ? 1 : 0;
}



static inline int RingBuffer_IsEmpty(struct ring_buffer_t *ringBuffer)
{
    return ((ringBuffer->head - ringBuffer->tail) == 0U) ? 1 : 0;
}



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DEFINITIONS                        */
/*****************************************************************************/

int RingBuffer_Init(ring_buffer_descriptor_t *descriptor, 
                    ring_buffer_attributes_t *attributes)
{
    static uint8_t usedRingBuffers = 0;
    int error = -1;

    if((usedRingBuffers < RING_BUFFERS_AMOUNT) && (descriptor != NULL) && 
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

                *descriptor = usedRingBuffers++;
                error = 0;
            }
        }
    }

    return error;
}



