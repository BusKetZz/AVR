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



/*****************************************************************************/
/*                           PRIVATE VARIABLES                               */
/*****************************************************************************/

static const uint8_t numberToDisplay[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE,
                                            SIX, SEVEN, EIGHT, NINE};
volatile static uint8_t numbersCounter;

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



void PORTD_Init(void)
{
    /* Set all the pins of Port D as an output */ 
    DDRD |= 0xFF;
}



/*****************************************************************************/
/*                              MAIN PROGRAM                                 */
/*****************************************************************************/

int main(void)
{   
    TIMER1_Init();

    PORTD_Init();

    /* Enable global interrupts */
    sei();

    /* Turn on 7-Segment display with default '0' value */
    PORTD = numberToDisplay[0];
    
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
    if(timerCounter == 1)
    {
        if(++numbersCounter > 9)
        {
            numbersCounter = 0;
        }
        PORTD = numberToDisplay[numbersCounter];

        timerCounter = 0;
    }
    else
    {
        timerCounter++;
    } 
}