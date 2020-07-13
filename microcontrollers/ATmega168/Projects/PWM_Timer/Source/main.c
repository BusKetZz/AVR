/**
 * File: main.c
 * 
 * Project: PWM_Timer
 * 
 * Author: Jakub Standarski
 * 
 * Date: 28.11.2019
 */

#include "USART.h"

#include <avr/io.h>
#include <util/delay.h>



/*****************************************************************************/
/*                              PRIVATE DEFINES                              */
/*****************************************************************************/

#define PWM_DUTY_CYCLE    10U

#define LED_DDRB    DDRB
#define LED1        (1 << PB1)
#define LED2        (1 << PB2)
#define LED3        (1 << PB3)



/*****************************************************************************/
/*                      PRIVATE FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/

static void Timer1_Timer2_PWM_Init(void);
static inline void LED_DDRB_Init(void);



/*****************************************************************************/
/*                              MAIN PROGRAM                                 */
/*****************************************************************************/

int main(void)
{
    LED_DDRB_Init();
    Timer1_Timer2_PWM_Init();

    while(1)
    {
        
    }

    return 0;
}



/*****************************************************************************/
/*                       PRIVATE FUNCTIONS DEFINITIONS                       */
/*****************************************************************************/

static void Timer1_Timer2_PWM_Init(void)
{
    /* Timer1 - channels: A, B */
    TCCR1A |= (1 << WGM10);         /* Fast PWM, 8-bit              */
    TCCR1B |= (1 << WGM12);         /* Fast PWM, 8-bit              */
    TCCR1B |= (1 << CS11);          /* PWM frequency = F_CPU/8/256  */
    TCCR1A |= (1 << COM1A1);        /* PWM output on OC1A - PB1     */
    TCCR1A |= (1 << COM1B1);        /* PWM output on OC1B - PB2     */

    /* Timer2 - channel: A */
    TCCR2A |= (1 << WGM20);         /* Fast PWM                     */
    TCCR2A |= (1 << WGM21);         /* Fast PWM                     */
    TCCR2B |= (1 << CS21);          /* PWM frequency = F_CPU/8/256  */
    TCCR2A |= (1 << COM2A1);        /* PWM output on OC2A - PB3     */

    OCR2A = PWM_DUTY_CYCLE;
    OCR1B = PWM_DUTY_CYCLE;
    OCR1A = PWM_DUTY_CYCLE;
}



static inline void LED_DDRB_Init(void)
{
    LED_DDRB |= (LED1 | LED2 | LED3);
}
