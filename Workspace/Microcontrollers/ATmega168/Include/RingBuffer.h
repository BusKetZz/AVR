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

/**
 * @brief  Initialize ring buffer
 * 
 * @param1  (unsigned int) *descriptor: pointer to the index of an initialized
 *                                      ring buffer
 * @param2  (struct) *attributes: pointer to structure of ring buffer 
 *                                attributes
 * 
 * @return  (int) 0 if okey, -1 if error
 */
int RingBuffer_Init(ring_buffer_descriptor_t *descriptor, 
                    ring_buffer_attributes_t *attributes);



#endif /* RINGBUFFER_H */