/**
 * File: USART.c
 * 
 * Author: Jakub Standarski
 * 
 * Date: 04.11.2019
 */

#include "USART.h"
#include "Macros.h"

#include <avr/io.h>




/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DEFINITIONS                        */
/*****************************************************************************/

void USART_Init(unsigned int baudRate)
{
    /* Set baud rate */
    UBRR0H = (unsigned char)(baudRate >> 8);
    UBRR0L = (unsigned char)baudRate;

    CLEAR_BIT(UCSR0A, U2X0);       /* Double Transmission Speed disabled     */
    CLEAR_BIT(UCSR0A, MPCM0);      /* Multi-processor Communication Mode  
                                      disabled                               */

    CLEAR_BIT(UCSR0C, UMSEL00);    /* Asynchronous USART Mode                */
    CLEAR_BIT(UCSR0C, UMSEL01);    /* Asynchronous USART Mode                */
    CLEAR_BIT(UCSR0C, UPM00);      /* Parity Mode disabled                   */
    CLEAR_BIT(UCSR0C, UPM01);      /* Parity Mode disabled                   */
    CLEAR_BIT(UCSR0C, USBS0);      /* 1 Stop Bit                             */
    SET_BIT(UCSR0C, UCSZ01);       /* 8-bit Character Size                   */
    SET_BIT(UCSR0C, UCSZ00);       /* 8-bit Character Size                   */

    CLEAR_BIT(UCSR0B, UCSZ02);     /* 8-bit Character Size                   */
    SET_BIT(UCSR0B, RXEN0);        /* Receiver enabled                       */
    SET_BIT(UCSR0B, TXEN0);        /* Transmitter enabled                    */
}



void USART_Interrupt_RX_Init(void)
{
    SET_BIT(UCSR0B, RXCIE0);
}



void USART_Interrupt_TX_Init(void)
{
    SET_BIT(UCSR0B, TXCIE0);
}



void USART_TransmitByte(uint8_t byteToTransmit)
{
    /* Wait for empty transmit buffer */
    while(!(UCSR0A & (1 << UDRE0)));

    /* Put the data into buffer and send it */
    UDR0 = byteToTransmit;
}



void USART_TransmitString(const char *stringToTransmit)
{
    uint8_t i = 0;

    while(stringToTransmit[i])
    {
        USART_TransmitByte(stringToTransmit[i]);
        i++;
    }
}



uint8_t USART_ReceiveByte(void)
{
    /* Wait for data to be received */
    while(!(UCSR0A & (1 << RXC0)));

    /* Get and return received data from the buffer */
    return UDR0;
}



uint8_t USART_GetNumber(void) 
{
  char hundreds = '0';
  char tens     = '0';
  char ones     = '0';
  char thisChar = '0';

  do {
    hundreds = tens;
    tens     = ones;
    ones     = thisChar;
    thisChar = USART_ReceiveByte();
    USART_TransmitByte(thisChar);
  } while (thisChar != '\r');

  return (100 * (hundreds - '0') + 10 * (tens - '0') + ones - '0');
}
