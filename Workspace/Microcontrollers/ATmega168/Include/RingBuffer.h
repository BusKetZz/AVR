/**
 * File: RingBuffer.h
 * 
 * Author: Jakub Standarski
 * 
 * Date: 01.12.2019
 */

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <stdint.h>
#include <stdbool.h>



/*****************************************************************************/
/*                              PUBLIC DEFINES                               */
/*****************************************************************************/



/*****************************************************************************/
/*                          PUBLIC OWN DATA TYPES                            */
/*****************************************************************************/

typedef unsigned int ring_buffer_descriptor_t;



/*****************************************************************************/
/*                            PUBLIC STRUCTURES                              */
/*****************************************************************************/

typedef struct
{
    uint8_t sizeOfElement;
    uint8_t numberOfElements;
    void *buffer;
}ring_buffer_attributes_t;



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/




#endif /* RINGBUFFER_H */