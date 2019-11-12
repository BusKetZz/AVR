/**
 * File: Button.c
 * 
 * Author: Jakub Standarski
 * 
 * Date: 04.11.2019
 */

#define __AVR_ATmega168__

#include "Button.h"



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DEFINITIONS                        */
/*****************************************************************************/

void Button_Init(port_letter_t PORT_x, button_number_t BUTTONx)
{
    switch(PORT_x)
    {
        case 'B':
            DDRB &= ~BUTTONx;
            PORTB |= BUTTONx;
            break;

        case 'C':
            DDRC &= ~BUTTONx;
            PORTC |= BUTTONx;
            break;

        case 'D':
            DDRD &= ~BUTTONx;
            PORTD |= BUTTONx;
            break;
    }
}



uint8_t Button_ReadState(port_letter_t PORT_x, button_number_t BUTTONx)
{
    uint8_t buttonState;

    switch(PORT_x)
    {
        case 'B':
            buttonState = (PINB & BUTTONx);
            break;
            
        case 'C':
            buttonState = (PINC & BUTTONx);
            break;

        case 'D':
            buttonState = (PIND & BUTTONx);
            break;

        default:
            buttonState = -1;
            break;
    }

    return buttonState;
}
