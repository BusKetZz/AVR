/**
 * File: 7-Segment_Display.c
 * 
 * Author: Jakub Standarski
 * 
 * Date: 17.11.2019
 */

#define __AVR_ATmega168__

#include "7-Segment_Display.h"



/*****************************************************************************/
/*                          PRIVATE OWN DATA TYPES                           */
/*****************************************************************************/



/*****************************************************************************/
/*                             PRIVATE DEFINES                               */
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



/*****************************************************************************/
/*                       PRIVATE FUNCTIONS DEFINITIONS                       */
/*****************************************************************************/



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DEFINITIONS                        */
/*****************************************************************************/

void SegmentDisplay_Init(port_letter_t PORT_x)
{
    switch(PORT_x)
    {
        case 'B':
            DDRB |= 0xFF;
            break;

        case 'C':
            DDRC |= 0xFF;
            break;

        case 'D':
            DDRD |= 0xFF;
            break;
    }
}
