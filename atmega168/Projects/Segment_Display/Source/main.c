/**
 *  Project: 7-Segment Display
 * 
 *  File: main.c
 * 
 *  Author: Jakub Standarski 
 *
 *  Date: 08.10.2019
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "SegmentDisplay.h"



/*****************************************************************************/
/*                            PRIVATE DEFINES                                */
/*****************************************************************************/



/*****************************************************************************/
/*                           PRIVATE VARIABLES                               */
/*****************************************************************************/

volatile static uint8_t timerCounter; 



/*****************************************************************************/
/*                           PRIVATE FUNCTIONS                               */
/*****************************************************************************/

void TIMER1_Init(void)
{  
    TCNT1 = 0;

    /* Normal port operation */
    TCCR1A = 0x00;

    /* Clock source / 64 (prescaler)                                 */
    /* 1 000 000 [Hz] / 8 = 125 000 [Hz]                             */
    /* Time period = 1 / frequency = 1 / 125 000 [Hz] = 0,000008 [s] */
    /* Overflow occurs every 65 535 * 0,000008 = 0.5 [s]             */
    TCCR1B = (1 << CS11);

    /* Set Overflow Interrupt Enable */
    TIMSK1 |= (1 << TOIE1);
}



/*****************************************************************************/
/*                              MAIN PROGRAM                                 */
/*****************************************************************************/

int main(void)
{   
    TIMER1_Init();
    SegmentDisplay_Init(PORT_B);
    

    /* Enable global interrupts */
    sei();

    /* Turn on 7-Segment display with default '0' value */
    SegmentDisplay_SetDigit(PORT_B, 0);
    
    while(1)
    {
        /* Do nothing, wait for interrupt from the timer */
    }

    return 0;
}



/*****************************************************************************/
/*                        INTERRUPT SERVICE ROUTINES                         */
/*****************************************************************************/

ISR(TIMER1_OVF_vect)
{
    static uint8_t digitToDisplay = 0;

    if(timerCounter == 1)
    {
        if(++digitToDisplay > 9)
        {
            digitToDisplay = 0;
        }
        SegmentDisplay_SetDigit(PORT_B, digitToDisplay);

        timerCounter = 0;
    }
    else
    {
        timerCounter++;
    } 
}