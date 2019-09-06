/**
 *  Project: LED_Blink
 * 
 *  File: main.c
 * 
 *  Author: Jakub Standarski 
 *
 *  Date: 06.09.2019
 */


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= _BV(PB0);

    while(1)
    {
        _delay_ms(1000);
        PORTB |= _BV(PB0);
        _delay_ms(1000);
        PORTB &= ~_BV(PB0);
    }

    return 0;
}

