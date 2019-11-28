/**
 * File: USART.c
 * 
 * Author: Jakub Standarski
 * 
 * Date: 04.11.2019
 */

#define __AVR_ATmega168__

#include "USART.h"

#include <avr/io.h>




/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DEFINITIONS                        */
/*****************************************************************************/

void USART_Init(unsigned int baudRate)
{
    /* Set baud rate */
    UBRR0H |= (unsigned char)(baudRate >> 8);
    UBRR0L |= (unsigned char)baudRate;

    /* Enable receiver and transmitter */
    UCSR0B = ((1 << RXEN0) | (1 << TXEN0));

    /* Set frame format: 8 data bits, 1 stop bit, no parity */
    UCSR0C = ((1 << UCSZ01) | (1 << UCSZ00));
}



void USART_TransmitByte(char byteToTransmit)
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



char USART_ReceiveByte(void)
{
    /* Wait for data to be received */
    while(!(UCSR0A & (1 << RXC0)));

    /* Get and return received data from the buffer */
    return UDR0;
}
