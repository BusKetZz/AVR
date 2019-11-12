/**
 * File: USART.h
 * 
 * Author: Jakub Standarski
 * 
 * Date: 04.11.2019
 */


#include <avr/io.h>



/*****************************************************************************/
/*                              PUBLIC DEFINES                               */
/*****************************************************************************/

#define BAUD_9600   (uint16_t)6



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/

/**
 * @brief Initialize USART
 * 
 * @param1 baud rate: value placed into UBRR0H and UBRR0L registers, depends on
 *                    oscillator frequency
 * 
 * @return void 
 */ 
void USART_Init(uint16_t baudrate);



/**
 * @brief Send byte over USART (blocking mode)
 * 
 * @param1 byte to send over USART 
 * 
 * @return void 
 */
void USART_TransmitByte(char byteToTransmit);



/**
 * @brief Read byte from the USART data register 
 * 
 * @param void
 * 
 * @return one byte of type 'char'
 */ 
char USART_ReceiveByte(void);
