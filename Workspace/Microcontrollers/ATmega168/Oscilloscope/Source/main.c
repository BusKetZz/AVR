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
    USART_Init(BAUD_9600);
    ADC0_Init_Freerunning();

    while(1)
    {
        USART_TransmitByte(ADCH);
        _delay_ms(SAMPLE_DELAY);
    }

    return 0;
}
