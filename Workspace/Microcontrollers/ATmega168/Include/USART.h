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

#define BAUD_9600   (unsigned int)6



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/

/**
 * @brief  Initialize USART
 * 
 * @param1  Baud rate: value placed into UBRR0H and UBRR0L registers, depends on
 *                     oscillator frequency
 * 
 * @return  void 
 */ 
void USART_Init(unsigned int baudRate);



/**
 * @brief  Send byte over USART (blocking mode)
 * 
 * @param1  Byte to send over USART 
 * 
 * @return void 
 */
void USART_TransmitByte(char byteToTransmit);



/**
 * @brief  Send string over USART (blocking mode)
 * 
 * @param1  String (array) to send over USART
 * 
 * @return  void
 */
void USART_TransmitString(const char *stringToTransmit);



/**
 * @brief  Read byte from the USART data register 
 * 
 * @param  void
 * 
 * @return  One byte of type 'char'
 */ 
char USART_ReceiveByte(void);
