/**
 *  Project: MorAmp Interview
 * 
 *  File: main.c
 * 
 *  Author: Jakub Standarski 
 *
 *  Date: 04.10.2019
 */

#ifndef F_CPU
    #define F_CPU 1000000
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



/*****************************************************************************/
/*                             LOCAL DIRECTIVES                              */
/*****************************************************************************/

/* UART settings */
#define FOSC        1000000
#define BAUDRATE    2400
#define UBRR        ((FOSC/(BAUDRATE<<4))-1)

/* Iteration state */
#define FINISHED     1
#define NOT_FINISHED 0

/* Button state */
#define BUTTON_PRESSED  (((PINB & (1 << PIN0)) == 0)) 

/* LED state */
#define LED1_ON   (1 << PIN1)
#define LED1_OFF ~(1 << PIN1)



/*****************************************************************************/
/*                      LOCAL FUNCTIONS DECLARATIONS                         */
/*****************************************************************************/

void USART_Init(unsigned int ubrr);
void USART_Transmit(char *data);
void System_Test(void);



/*****************************************************************************/
/*                      LOCAL VARIABLES DECLARATIONS                         */
/*****************************************************************************/

unsigned char rxData;



/*****************************************************************************/
/*                               MAIN PROGRAM                                */
/*****************************************************************************/

int main(void)
{
    volatile uint8_t loopCounter = 0;
    volatile uint8_t iterationState = NOT_FINISHED;

    USART_Init(UBRR);

    DDRB &= ~(1 << PIN0);      /* Port B, Pin 0 - input  */
    DDRB |=  (1 << PIN1);      /* Port B, Pin 1 - output */

    sei();

    while(1)
    {
        /* If button pressed  and iteration not finished */
        if(BUTTON_PRESSED && iterationState == NOT_FINISHED) 
        {
            _delay_ms(20);   /* Debounce push button */

            /* Ensure button is pressed and loop iterates less than 3 times */
            if(BUTTON_PRESSED && loopCounter < 3)   
            {
                PORTB |= LED1_ON;       
                _delay_ms(500);
                PORTB &= LED1_OFF;      
                _delay_ms(250);
            }
            loopCounter++;
            if(loopCounter == 3)
            {
                iterationState = FINISHED;
                while(BUTTON_PRESSED); /* Wait for button release */
            }
        }
        else
        {
            PORTB &= LED1_OFF;  
            iterationState = NOT_FINISHED;
            loopCounter = 0;  /* Reset counter */
        } 
    }   /* End of while(1) */

    return 0;
}



/*****************************************************************************/
/*                       LOCAL FUNCTIONS DEFINITIONS                         */
/*****************************************************************************/

void USART_Init(unsigned int ubrr)
{
    /* Set asynchronous mode */
    UCSR0C |= ((1 << UMSEL01) | (1 << UMSEL00));

    /* Disable parity mode */
    UCSR0C &= ~((1 << UPM01) | (1 << UPM00));

    /* Set 1 stop bit */
    UCSR0C &= ~(1 << USBS0);

    /* Set 8-bit data format */
    UCSR0B &= ~(1 << UCSZ02);
    UCSR0C |= ((1 << UCSZ01) | (1 << UCSZ00));

    /* Set baud rate */
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;

    /* Enable receiver, transmitter and receiver interrupt */
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
}



void USART_Transmit(char *data)
{
    while((*data) != '\0')
    {
        /* Wait for empty transmit buffer */
        while(!(UCSR0A & (1 << UDRE0)));
        /* Put data into buffer, send the data */
        UDR0 = (*data);
        /* Step through the buffer */
        data++;
    }
}



void System_Test(void)
{
    /* Check whether Port B, Pin 0 is configured properly */
    if((DDRB & (1 << PIN0)) == 0)
    {
        USART_Transmit("Port B, Pin 0 configured as an input\n\r");
    }
    else
    {
        USART_Transmit("ERROR: Port B, Pin 0 configured not properly\n\r");
    }

    /* Check whether Port B, Pin 1 is configured properly */
    if((DDRB & (1 << PIN1)) != 0)
    {
        USART_Transmit("Port B, Pin 1 configured as an output\n\r");
    }
    else
    {
        USART_Transmit("ERROR: Port B, Pin 1 configured not properly\n\r");
    }
}


/*****************************************************************************/
/*                   INTERRUPT SERVICE ROUTINES DEFINITIONS                  */
/*****************************************************************************/

ISR(USART_RX_vect)
{
    /* Read UDR0 register to reset flag */
    rxData = UDR0;

    if(rxData == 't')
    {
        System_Test();
    }
}
