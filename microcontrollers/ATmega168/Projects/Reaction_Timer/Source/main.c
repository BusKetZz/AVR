/**
 * File: main.c
 * 
 * Project: Reaction_Timer
 * 
 * Author: Jakub Standarski
 * 
 * Date: 25.11.2019
 */

#include "Button.h"
#include "LED.h"
#include "Timer.h"
#include "USART.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



/*****************************************************************************/
/*                      PRIVATE FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/

static void PrintMilliseconds(uint16_t timerValue);



/*****************************************************************************/
/*                              MAIN PROGRAM                                 */
/*****************************************************************************/

int main(void)
{
    uint16_t timerValue;


    Button_Init(PORT_C, BUTTON5);
    LED_Init(PORT_B, ALL_LEDS);
    Timer1_Init(TIMER1_NORMAL_PORT_OPERATION, TIMER1_CLOCK_PRESCALER_64);
    USART_Init(BAUD_4800);
    

    USART_TransmitString("\r\n!!!REACTION TIMER!!!\r\n");
    USART_TransmitString("--------------------\r\n");
    USART_TransmitString("Press any key to start...\r\n");


    while(1)
    {
        USART_ReceiveByte();
        USART_TransmitString("\r\nBe ready...");
        Timer1_RandomDelay();

        USART_TransmitString("\r\nStart!\r\n");
        LED_ON(PORT_B, ALL_LEDS);
        TCNT1 = 0;

        if(Button_ReadState(PORT_C, BUTTON5) == 0)
        {
            USART_TransmitString("You cheat only yourself...\r\n");
        }
        else
        {
            loop_until_bit_is_clear(BUTTON_PIN_C, BUTTON_PC5);
            timerValue = (TCNT1 >> 4);

            PrintMilliseconds(timerValue);
        }

        LED_OFF(PORT_B, ALL_LEDS);
        USART_TransmitString("Press any key, to try again...\r\n");
    }

    return 0;
}



/*****************************************************************************/
/*                      PRIVATE FUNCTIONS DEFINITIONS                        */
/*****************************************************************************/

static void PrintMilliseconds(uint16_t timerValue)
{
    uint8_t digit;

    USART_TransmitString("\r\nYour reaction time: ");

    digit = 0;
    while(timerValue >= 10000)
    {
        digit++;
        timerValue -= 10000;
    }
    if(digit)
    {
        USART_TransmitByte('0' + digit);
    }

    digit = 0;
    while(timerValue >= 1000)
    {
        digit++;
        timerValue -= 1000;
    }
    USART_TransmitByte('0' + digit);
    USART_TransmitByte('.');

    digit = 0;
    while(timerValue >= 100)
    {
        digit++;
        timerValue -= 100;
    }
    USART_TransmitByte('0' + digit);

    digit = 0;
    while(timerValue >= 10)
    {
        digit++;
        timerValue -= 10;
    }
    USART_TransmitByte('0' + digit);

    USART_TransmitByte('0' + timerValue);

    USART_TransmitString(" seconds.\r\n");
}
