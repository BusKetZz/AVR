/**
 * File: ADC.c
 * 
 * Author: Jakub Standarski
 * 
 * Date: 13.11.2019
 */

#define __AVR_ATmega168__

#include "ADC.h"



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DEFINITIONS                        */
/*****************************************************************************/

void ADC_Init_SingleConversion(uint8_t channel, uint8_t clockPrescaler)
{
    ADMUX  |= (1 << REFS0);
    ADMUX   = (0xF0 & ADMUX) | channel;

    ADCSRA |= clockPrescaler;
    ADCSRA |= (1 << ADEN);
}



void ADC_Init_Freerunning(uint8_t channel, uint8_t clockPrescaler)
{
    ADMUX  |= (1 << REFS0);
    ADMUX  |= (1 << ADLAR);
    ADMUX   = (0xF0 & ADMUX) | channel;

    ADCSRA |= clockPrescaler;
    ADCSRA |= (1 << ADEN);
    ADCSRA |= (1 << ADATE);
    ADCSRA |= (1 << ADSC);
}



void ADC_MakeSingleConversion(void)
{
    ADCSRA |= (1 << ADSC);
    loop_until_bit_is_clear(ADCSRA, ADSC);
}
