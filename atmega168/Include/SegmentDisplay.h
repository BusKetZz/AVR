/**
 * File: 7-Segment_Display.h
 * 
 * Author: Jakub Standarski
 * 
 * Date: 17.11.2019
 */

#include <avr/io.h>



/*****************************************************************************/
/*                          PUBLIC OWN DATA TYPES                            */
/*****************************************************************************/

typedef char port_letter_t;


/*****************************************************************************/
/*                              PUBLIC DEFINES                               */
/*****************************************************************************/

#define PORT_B  (port_letter_t)('B')
#define PORT_C  (port_letter_t)('C')
#define PORT_D  (port_letter_t)('D')



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/

/**
 * @brief  Initialize 7-segment display on a given microcontroller port
 * 
 * @param  Microcontroller port letter: PORT_x [x = 'A', 'B' or 'C']
 * 
 * @return  void
 */
void SegmentDisplay_Init(port_letter_t PORT_x);



/**
 * @brief  Display a given digit on a 7-segment display
 * 
 * @param1  Microcontroller port letter: PORT_x [x = 'A', 'B' or 'C']
 * @param2  Digit to display: 0...9
 * 
 * @return  void
 */
void SegmentDisplay_SetDigit(port_letter_t PORT_x, uint8_t digit);
