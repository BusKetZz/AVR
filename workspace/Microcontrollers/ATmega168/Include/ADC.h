/**
 * File: ADC.h
 * 
 * Author: Jakub Standarski
 * 
 * Date: 13.11.2019
 */

#include <avr/io.h>



/*****************************************************************************/
/*                          PUBLIC OWN DATA TYPES                            */
/*****************************************************************************/



/*****************************************************************************/
/*                              PUBLIC DEFINES                               */
/*****************************************************************************/

#define ADC_CHANNEL_0   (uint8_t)0
#define ADC_CHANNEL_1   (uint8_t)1
#define ADC_CHANNEL_2   (uint8_t)2
#define ADC_CHANNEL_3   (uint8_t)3
#define ADC_CHANNEL_4   (uint8_t)4
#define ADC_CHANNEL_5   (uint8_t)5
#define ADC_CHANNEL_6   (uint8_t)6
#define ADC_CHANNEL_7   (uint8_t)7

#define CLOCK_PRESCALER_4   (uint8_t)(1 << ADPS1)
#define CLOCK_PRESCALER_8   (uint8_t)((1 << ADPS1) | (1 << ADPS0))
#define CLOCK_PRESCALER_16  (uint8_t)(1 << ADPS2)
#define CLOCK_PRESCALER_32  (uint8_t)((1 << ADPS2) | (1 << ADPS0))



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/

/**
 * @brief Initialize ADC on selected channel with given clock prescaler and 
 *        AVCC reference voltage
 * 
 * @param channel:        ADC conversion channel - ADC_CHANNEL_x [x = 0...7]
 * @oaram clockPrescaler: ADC clock divider - CLOCK_PRESCALER_x [x = 4, 8, 16,
 *                        32]
 * 
 * @return void
 */ 
void ADC_Init_SingleConversion(uint8_t channel, uint8_t clockPrescaler);



/**
 * @brief Initialize ADC on selected channel with given clock prescaler, 
 *        AVCC reference voltage, ADC left adjust result
 *        in the 'freerunning' (continuous) mode
 * 
 * @param channel:        ADC conversion channel - ADC_CHANNEL_x [x = 0...7]
 * @oaram clockPrescaler: ADC clock divider - CLOCK_PRESCALER_x [x = 4, 8, 16,
 *                        32]
 * 
 * @return void
 */
void ADC_Init_Freerunning(uint8_t channel, uint8_t clockPrescaler); 



/**
 * @brief Make ADC0 single conversion (blocking mode)
 * 
 * @param void
 * 
 * @return void
 */
void ADC_MakeSingleConversion(void); 
