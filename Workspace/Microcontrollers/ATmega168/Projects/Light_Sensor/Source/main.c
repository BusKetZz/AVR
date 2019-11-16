/**
 * File: main.c
 * 
 * Author: Jakub Standarski
 * 
 * Date: 13.11.2019
 */

#include <avr/io.h>
#include <util/delay.h>
#include "LED.h"
#include "ADC.h"



int main(void)
{
    uint8_t ledValue = 0;
    uint16_t adcValue = 0;

    ADC0_Init();
    LED_Init(PORT_B, ALL_LEDS);

    while(1)
    {
        ADC0_MakeSingleConversion();
        adcValue = ADC;

        ledValue = (adcValue >> 7);
        LED_OFF(PORT_B, ALL_LEDS);
        
        for(uint8_t i = 0; i <= ledValue; i++)
        {
            LED_ON(PORT_B, (1 << i));
        }
        _delay_ms(50);
    }

    return 0;
}
