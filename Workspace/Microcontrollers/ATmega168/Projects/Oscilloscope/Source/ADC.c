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

void ADC0_Init(void)
{
    ADMUX  |= (1 << REFS0);
    ADCSRA |= (1 << ADPS2);
    ADCSRA |= (1 << ADEN);
}



void ADC0_Init_Freerunning(void)
{
    ADMUX  |= (1 << REFS0);
    ADMUX  |= (1 << ADLAR);

    ADCSRA |= ((1 << ADPS0) | (1 << ADPS1));
    ADCSRA |= (1 << ADEN);
    ADCSRA |= (1 << ADATE);
    ADCSRA |= (1 << ADSC);
}



void ADC0_MakeSingleConversion(void)
{
    ADCSRA |= (1 << ADSC);
    loop_until_bit_is_clear(ADCSRA, ADSC);
}
