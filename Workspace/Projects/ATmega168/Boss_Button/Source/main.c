/**
 * File: main.c
 * 
 * Author: Jakub Standarski
 * 
 * Date: 04.11.2019
 */ 

#include <avr/io.h>
#include <util/delay.h>

#include "LED.h"
#include "Button.h"
#include "USART.h"



/*****************************************************************************/
/*                               MAIN PROGRAM                                */
/*****************************************************************************/

int main(void)
{
    LED_Init(PORT_B, LED0);
    Button_Init(PORT_C, BUTTON5);
    USART_Init(BAUD_9600);

    USART_TransmitByte('0');

    while(1)
    {
        if(Button_ReadState(PORT_C, BUTTON5) == 0)
        {
            USART_TransmitByte('X');
            LED_Blink(PORT_B, LED0, 250);
        } 
    }

    return 0;
}

