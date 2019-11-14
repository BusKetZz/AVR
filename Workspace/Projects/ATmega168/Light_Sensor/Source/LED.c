/**
 * File: LED.c
 * 
 * Author: Jakub Standarski
 * 
 * Date: 04.11.2019
 */

#define __AVR_ATmega168__

#include "LED.h"
#include <util/delay.h>



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DEFINITIONS                        */
/*****************************************************************************/

void LED_Init(port_letter_t PORT_x, led_number_t LEDx)
{
    switch(PORT_x)
    {
        case 'B':
            DDRB |= LEDx;
            break;

        case 'C':
            DDRC |= LEDx;
            break;

        case 'D':
            DDRD |= LEDx;
            break;
    }
}



void LED_Blink(port_letter_t PORT_x, led_number_t LEDx)
{
    switch(PORT_x)
    {
        case 'B':
            PORTB |= LEDx;
            _delay_ms(500);
            PORTB &= ~LEDx;
            break;
        
        case 'C':
            PORTC |= LEDx;
            _delay_ms(500);
            PORTC &= ~LEDx;
            break;
        
        case 'D':
            PORTD |= LEDx;
            _delay_ms(500);
            PORTD &= ~LEDx;
            break;
    }
}



void LED_ON(port_letter_t PORT_x, led_number_t LEDx)
{
    switch(PORT_x)
    {
        case 'B':
            PORTB |= LEDx;
            break;
        
        case 'C':
            PORTC |= LEDx;
            break;
        
        case 'D':
            PORTD |= LEDx;
            break;
    }
}



void LED_OFF(port_letter_t PORT_x, led_number_t LEDx)
{
    switch(PORT_x)
    {
        case 'B':
            PORTB &= ~LEDx;
            break;
        
        case 'C':
            PORTC &= ~LEDx;
            break;
        
        case 'D':
            PORTD &= ~LEDx;
            break;
    }
}
