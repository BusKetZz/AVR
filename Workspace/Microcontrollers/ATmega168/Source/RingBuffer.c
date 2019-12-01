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
/*                       PUBLIC FUNCTIONS DEFINITIONS                        */
/*****************************************************************************/

