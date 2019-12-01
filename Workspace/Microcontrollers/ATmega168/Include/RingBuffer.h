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

typedef unsigned int ring_buffer_indexer_t;



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
 * @param1  (unsigned int) *indexer: pointer to the index of an initialized
 *                                      ring buffer
 * @param2  (struct) *attributes: pointer to structure of ring buffer 
 *                                attributes
 * 
 * @return  (int) 0 if okey, -1 if error
 */
int RingBuffer_Init(ring_buffer_indexer_t *indexer, 
                    ring_buffer_attributes_t *attributes);



/**
 * @brief  Add an element into the ring buffer
 * 
 * @param1  (unsigned int) indexer: index of ring buffer 
 * @param2  (const void) *data: data to put into the ring buffer
 * 
 * @return  (int) 0 if okey, -1 if error
 */
int RingBuffer_Put(ring_buffer_indexer_t indexer, const void *data);



/**
 * @brief  Get an element from the ring buffer
 * 
 * @param1  (unsigned int) indexer: index of ring buffer
 * @param2  (void) *data: pointer to the place where to copy data from the 
 *                        ring buffer
 * 
 * @return  (int) 0 if okey, -1 if error
 */
int RingBuffer_Get(ring_buffer_indexer_t indexer, void *data);



#endif /* RINGBUFFER_H */