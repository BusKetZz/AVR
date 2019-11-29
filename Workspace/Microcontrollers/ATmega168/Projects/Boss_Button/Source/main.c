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
    Button_Init(PORT_B, BUTTON1);
    USART_Init(BAUD_4800);

    LED_Blink(PORT_B, LED0);
    USART_TransmitByte('0');

    while(1)
    {
        if(Button_ReadState(PORT_B, BUTTON1) == 0)
        {
            USART_TransmitByte('X');
            LED_Blink(PORT_B, LED0);
        } 
    }

    return 0;
}
