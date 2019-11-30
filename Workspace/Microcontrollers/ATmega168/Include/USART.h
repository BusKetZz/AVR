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

#define BAUD_4800   (unsigned int)12
#define BAUD_9600   (unsigned int)6



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/

/**
 * @brief  Initialize generic USART functionalities
 * 
 * @param1  Baud rate: value placed into UBRR0H and UBRR0L registers, depends on
 *                     oscillator frequency
 * 
 * @return  void 
 */ 
void USART_Init(unsigned int baudRate);



/**
 * @brief Initialize USART RX and TX interrupts 
 * 
 * @param  void
 * 
 * @return  void
 */
void USART_Interrupt_RX_TX_Init(void);



/**
 * @brief  Send byte over USART (blocking mode)
 * 
 * @param1  Byte to send over USART 
 * 
 * @return void 
 */
void USART_TransmitByte(uint8_t byteToTransmit);



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
uint8_t USART_ReceiveByte(void);



/**
 * @brief  Get a number between 0-255 from the user input
 * 
 * @param  void
 * 
 * @return (uint8_t) number between 0-255
 */
uint8_t USART_GetNumber(void);
