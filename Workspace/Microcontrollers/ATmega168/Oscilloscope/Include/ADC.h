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



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/

/**
 * @brief Initialize ADC0 with /16 clock prescaler and AVCC reference voltage
 * 
 * @param void
 * 
 * @return void
 */ 
void ADC0_Init(void);



/**
 * @brief Initialize ADC0 with /8 clock prescaler, AVCC reference voltage,
 *        ADC left adjust result in the 'freerunning' (continuous) mode
 * 
 * @param void
 * 
 * @return void
 */
void ADC0_Init_Freerunning(void); 



/**
 * @brief Make ADC0 single conversion (blocking mode)
 * 
 * @param void
 * 
 * @return void
 */
void ADC0_MakeSingleConversion(void); 
