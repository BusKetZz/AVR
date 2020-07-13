/**
 * File: main.c
 * 
 * Author: Jakub Standarski
 * 
 * Date: 13.11.2019
 */

#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"
#include "USART.h"



#define SAMPLE_DELAY 20



int main(void)
{
    USART_Init(BAUD_4800);
    ADC_Init_Freerunning(ADC_CHANNEL_0, CLOCK_PRESCALER_8);

    while(1)
    {
        USART_TransmitByte(ADCH);
        _delay_ms(SAMPLE_DELAY);
    }

    return 0;
}
