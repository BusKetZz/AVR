/**
 * File: main.c
 * 
 * Project: Voltmeter
 * 
 * Author: Jakub Standarski
 * 
 * Date: 03.12.2019
 */

#include "Macros.h"
#include "USART.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <math.h>



/*****************************************************************************/
/*                              PRIVATE DEFINES                              */
/*****************************************************************************/

#define REFERENCE_VCC       4.97
#define VOLTAGE_DIV_FACTOR  3.114



/*****************************************************************************/
/*                      PRIVATE FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/

void ADC_Init(void);
void ADC_SleepModeSetup(void);
uint16_t ADC_Oversample16x(void);

void USART_PrintFloat(float number);



/*****************************************************************************/
/*                              MAIN PROGRAM                                 */
/*****************************************************************************/

int main(void)
{
    float voltage;

    USART_Init(BAUD_4800);
    ADC_Init();
    ADC_SleepModeSetup();

    sei();

    while(1)
    {
        voltage = ADC_Oversample16x() * VOLTAGE_DIV_FACTOR * REFERENCE_VCC /
                  4096;
                  
        USART_PrintFloat(voltage);
        _delay_ms(500);
    }

    return 0;
}



/*****************************************************************************/
/*                       PRIVATE FUNCTIONS DEFINITIONS                       */
/*****************************************************************************/

void ADC_Init(void)
{
    ADMUX |= (0x0F & PC5);
    SET_BIT(ADMUX, REFS0);
    SET_BIT(ADCSRA, ADPS1);
    SET_BIT(ADCSRA, ADPS2);
    SET_BIT(ADCSRA, ADEN);
}



void ADC_SleepModeSetup(void)
{
    set_sleep_mode(SLEEP_MODE_ADC);
    SET_BIT(ADCSRA, ADIE);
}



uint16_t ADC_Oversample16x(void)
{
    uint16_t oversampledValue = 0;

    for(uint8_t i = 0; i < 16; i++)
    {
        sleep_mode();
        oversampledValue += ADC;
    }

    return (oversampledValue >> 2);
}



void USART_PrintFloat(float number)
{
    number = round(number * 100) / 100;
    USART_TransmitByte('0' + number/10);
    USART_TransmitByte('0' + number - 10*floor(number/10));
    USART_TransmitByte('.');
    USART_TransmitByte('0' + (number*10) - floor(number)*10);
    USART_TransmitByte('0' + (number*100) - floor(number*10)*10);
    USART_TransmitString("\r\n");
}



/*****************************************************************************/
/*                             ISRs DEFINITIONS                              */
/*****************************************************************************/

EMPTY_INTERRUPT(ADC_vect);
