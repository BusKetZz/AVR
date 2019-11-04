/**
 * File: USART.c
 * 
 * Author: Jakub Standarski
 * 
 * Date: 04.11.2019
 */

#define __AVR_ATmega168__

#include "USART.h"



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DEFINITIONS                        */
/*****************************************************************************/

void USART_Init(uint16_t baudrate)
{
    /* Set baud rate */
    UBRR0H |= (uint8_t)(baudrate >> 8);
    UBRR0L |= (uint8_t)baudrate;

    /* Enable receiver and transmitter */
    UCSR0B |= ((1 << RXEN0) | (1 << TXEN0));

    /* Set frame format: 8 data bits, 1 stop bit */
    UCSR0B &= ~(1 << UCSZ02);
    UCSR0C |= ((1 << UCSZ00) | (1 << UCSZ01));
    UCSR0C &= ~(1 << USBS0);  
}



void USART_TransmitByte(char byteToTransmit)
{
    /* Wait for empty transmit buffer */
    while(!(UCSR0A & (1 << UDRE0)));

    /* Put the data into buffer and send it */
    UDR0 = byteToTransmit;
}



char USART_ReceiveByte(void)
{
    /* Wait for data to be received */
    while(!(UCSR0A & (1 << RXC0)));

    /* Get and return received data from the buffer */
    return UDR0;
}