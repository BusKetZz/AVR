/**
 * File: Timer.h
 *
 * Author: Jakub Standarski
 * 
 * Date: 21.11.2019
 */

#include <avr/io.h>



/*****************************************************************************/
/*                          PUBLIC OWN DATA TYPES                            */
/*****************************************************************************/



/*****************************************************************************/
/*                              PUBLIC DEFINES                               */
/*****************************************************************************/

/* Timer0 compare output modes */
#define TIMER0_NORMAL_PORT_OPERATION    (uint8_t)0x00

/* Timer0 clock prescalers */
#define TIMER0_CLOCK_PRESCALER_1        (1 << CS00)
#define TIMER0_CLOCK_PRESCALER_8        (1 << CS01)
#define TIMER0_CLOCK_PRESCALER_64       ((1 << CS01) | (1 << CS00))
#define TIMER0_CLOCK_PRESCALER_256      (1 << CS02)
#define TIMER0_CLOCK_PRESCALER_1024     ((1 << CS02) | (1 << CS00)
)

/* Timer1 compare output modes */
#define TIMER1_NORMAL_PORT_OPERATION    (uint8_t)0x00

/* Timer1 clock prescalers */
#define TIMER1_CLOCK_PRESCALER_1    (1 << CS10)
#define TIMER1_CLOCK_PRESCALER_8    (1 << CS11)
#define TIMER1_CLOCK_PRESCALER_64   ((1 << CS11) | (1 << CS10))
#define TIMER1_CLOCK_PRESCALER_256  (1 << CS12)
#define TIMER1_CLOCK_PRESCALER_1024 ((1 << CS12) | (1 << CS10))



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/

/**
 * @brief  Timer 0 (8-bit) initialization
 * 
 * @param1  Timer operation mode [compareOutputMode = NORMAL_PORT_OPERATION,
 *                                TOGGLE_OC0A_ON_COMPARE_MATCH, 
 *                                CLEAR_OC0A_ON_COMPARE_MATCH,
 *                                SET_OC0A_ON_COMPARE_MATCH]
 * 
 * @param2  Timer source clock prescaler: CLOCK_PRESCALER_x [x = 0, 8, 64,
 *          256, 1024] or EXTERNAL_CLOCK_SOURCE_T0_FALLING_EDGE, 
 *          EXTERNAL_CLOCK_SOURCE_T0_RISING_EDGE
 * 
 * @return  void
 */
void Timer0_Init(uint8_t compareOutputMode, uint8_t clockPrescaler);



/**
 * @brief  Timer 1 (16-bit) initialization
 * 
 * @param1
 * 
 * @param2
 * 
 * @return  void
 */
void Timer1_Init(uint8_t compareOutputMode, uint8_t clockPrescaler);
