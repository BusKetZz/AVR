/**
 * File: Timer.c
 * 
 * Author: Jakub Standarski
 * 
 * Date: 21.11.2019
 */

#define __AVR_ATmega168__

#include "Timer.h"

#include <util/delay.h>



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DEFINITIONS                        */
/*****************************************************************************/

void Timer0_Init(uint8_t compareOutputMode, uint8_t clockPrescaler)
{
    TCCR0A |= compareOutputMode;
    TCCR0B |= clockPrescaler;
}



void Timer1_Init(uint8_t compareOutputMode, uint8_t clockPrescaler)
{
    TCCR1A |= compareOutputMode;
    TCCR1B |= clockPrescaler;
}



void Timer1_RandomDelay(void)
{
    uint8_t randomTime;

    _delay_ms(1000);
    randomTime = (uint8_t)TCNT1;

    while(--randomTime)
    {
        _delay_ms(10);
    }
}
