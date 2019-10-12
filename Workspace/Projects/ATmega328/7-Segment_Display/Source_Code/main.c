/**
 *  Project: 7-Segment Display
 * 
 *  File: main.c
 * 
 *  Author: Jakub Standarski 
 *
 *  Date: 08.10.2019
 */

#define __AVR_ATmega168P__

#include <avr/io.h>
#include <avr/interrupt.h>



/*****************************************************************************/
/*                            PRIVATE DEFINES                                */
/*****************************************************************************/

/* 7-Segment display literal-pin equivalent */
#define A   (1 << PIN0)
#define B   (1 << PIN1)
#define C   (1 << PIN2)
#define D   (1 << PIN3)
#define E   (1 << PIN4)
#define F   (1 << PIN5)
#define G   (1 << PIN6)
#define H   (1 << PIN7)


/* Numbers to display */
#define ZERO    (A | B | C | D | E | F)
#define ONE     (B | C)
#define TWO     (A | B | G | E | D)
#define THREE   (A | B | C | D | G)
#define FOUR    (B | C | F | G)
#define FIVE    (A | F | G | C | D)
#define SIX     (A | F | E | D | C | G)
#define SEVEN   (A | B | C)
#define EIGHT   (A | B | C | D | E | F | G)
#define NINE    (A | F | G | B | C | D)
#define DOT     (H)


/* Switches */
#define SW1   (1 << PIN4)
#define SW2   (1 << PIN5)



/*****************************************************************************/
/*                             PRIVATE ENUMS                                 */
/*****************************************************************************/

/* SW1 and SW2 state */
enum button_state_t
{
    CAPTURED,
    NON_CAPTURED
}buttonState = NON_CAPTURED;



/*****************************************************************************/
/*                           PRIVATE VARIABLES                               */
/*****************************************************************************/

static const uint8_t numberToDisplay[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE,
                                            SIX, SEVEN, EIGHT, NINE};
static int numbersCounter;



/*****************************************************************************/
/*                              MAIN PROGRAM                                 */
/*****************************************************************************/

int main(void)
{   
    /* Set Port C, switch 1 and switch 2 as an input */
    DDRC &= ~(SW1 | SW2);

    /* Set pull-up resistors for switch 1 and switch 2 */
    PORTC |= (SW1 | SW2);

    /* Set all the pins of Port D as an output */ 
    DDRD |= 0xFF;

    /* Enable Pin Change Interrupt for pin 12 and pin 13 */
    PCICR |= PCIE1;

    /* Set Pin Change Enable Mask for pin 12 and pin 13 */
    PCMSK1 |= (PCINT12 | PCINT13);

    /* Enable global interrupts */
    sei();

    /* Turn on 7-Segment display with default '0' value */
    PORTD = numberToDisplay[0];
    
    while(1)
    {
        /* Do nothing, wait for interrupt from the buttons */
    }

    return 0;
}



/*****************************************************************************/
/*                        INTERRUPT SERVICE ROUTINES                         */
/*****************************************************************************/

/* SW1 interrupt - increment display number */
ISR(PCINT1_vect)
{
    uint8_t whichButton = PINC;

    if(buttonState == NON_CAPTURED)
    {
        if((whichButton & SW1) != 0)
        {
            if(++numbersCounter == 10)
            {   
                numbersCounter = 0;
            }

            PORTD = numberToDisplay[numbersCounter];
            buttonState = CAPTURED; 
        }
        else if((whichButton & SW2) != 0)
        {
            if(--numbersCounter < 0)
            {
                numbersCounter = 9;
            }

            PORTD = numberToDisplay[numbersCounter];
            buttonState = CAPTURED; 
        }
    }
    else if(buttonState == CAPTURED)
    {
        buttonState = NON_CAPTURED;
    }
}