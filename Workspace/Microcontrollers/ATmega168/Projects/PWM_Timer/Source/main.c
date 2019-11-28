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

#define LED_DDRB    DDRB
#define LED1        (1 << PB1)
#define LED2        (1 << PB2)
#define LED3        (1 << PB3)



/*****************************************************************************/
/*                      PRIVATE FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/

static void Timer1_Timer2_Init(void);
static inline void LED_DDRB_Init(void);



/*****************************************************************************/
/*                              MAIN PROGRAM                                 */
/*****************************************************************************/

int main(void)
{
    uint8_t pwmDutyCycle;

    LED_DDRB_Init();
    Timer1_Timer2_Init();
    USART_Init(BAUD_9600);

    USART_TransmitString("-- PWM Timer example with LEDs --\r\n");

    while(1)
    {
        USART_TransmitString("\r\nEnter PWM duty cycle (0-255): ");
        pwmDutyCycle = (uint8_t)USART_ReceiveByte();
        OCR2A = OCR1B;
        OCR1B = OCR1A;
        OCR1A = pwmDutyCycle;
    }

    return 0;
}



/*****************************************************************************/
/*                       PRIVATE FUNCTIONS DEFINITIONS                       */
/*****************************************************************************/

static void Timer1_Timer2_Init(void)
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
}



static inline void LED_DDRB_Init(void)
{
    LED_DDRB |= (LED1 | LED2 | LED3);
}
