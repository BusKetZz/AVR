/**
 * File: main.c
 * 
 * Project: PWM_LED_Blink
 * 
 * Author: Jakub Standarski
 * 
 * Date: 26.11.2019
 */

#include "LED.h"

#include <avr/io.h>
#include <util/delay.h>



/*****************************************************************************/
/*                              PRIVATE DEFINES                              */
/*****************************************************************************/

#define LED_DELAY   20


/*****************************************************************************/
/*                      PRIVATE FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/

static void PWM_LEDs_Blink(uint8_t dutyCycle);


/*****************************************************************************/
/*                              MAIN PROGRAM                                 */
/*****************************************************************************/

int main(void)
{
    uint8_t dutyCycle = 0;
    uint8_t dutyCycleModifier = 1;

    LED_Init(PORT_B, ALL_LEDS);

    while(1)
    {
        if(dutyCycle == 0)
        {
            dutyCycleModifier = 1;
        }
        else if(dutyCycle == 255)
        {
            dutyCycleModifier = -1;
        }

        dutyCycle += dutyCycleModifier;
        PWM_LEDs_Blink(dutyCycle);
    }

    return 0;
}



/*****************************************************************************/
/*                       PRIVATE FUNCTIONS DEFINITIONS                       */
/*****************************************************************************/

static void PWM_LEDs_Blink(uint8_t dutyCycle)
{
    LED_ON(PORT_B, ALL_LEDS);

    for(uint8_t i = 0; i < 255; i++)
    {
        if(i >= dutyCycle)
        {
            LED_OFF(PORT_B, ALL_LEDS);
        }
        _delay_us(LED_DELAY);
    }
}
