/**
 * File: LED.h
 * 
 * Author: Jakub Standarski
 * 
 * Date: 04.11.2019
 */

#include <avr/io.h>



/*****************************************************************************/
/*                          PUBLIC OWN DATA TYPES                            */
/*****************************************************************************/

typedef uint8_t led_number_t;
typedef char port_letter_t;



/*****************************************************************************/
/*                              PUBLIC DEFINES                               */
/*****************************************************************************/

#define LED0     (led_number_t)(1 << 0)
#define LED1     (led_number_t)(1 << 1)
#define LED2     (led_number_t)(1 << 2)
#define LED3     (led_number_t)(1 << 3)
#define LED4     (led_number_t)(1 << 4)
#define LED5     (led_number_t)(1 << 5)
#define LED6     (led_number_t)(1 << 6)
#define LED7     (led_number_t)(1 << 7)
#define ALL_LEDS (led_number_t)0xFF

#define PORT_B  (port_letter_t)('B')
#define PORT_C  (port_letter_t)('C')
#define PORT_D  (port_letter_t)('D')



/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/

/**
 * @brief Initialize LED/LEDs at given port's pin/pins
 * 
 * @param1  Microcontroller port letter: PORT_x [x = 'A', 'B' or 'C']
 * @param2  LED number: LEDx [x = 0...7]
 * 
 * @return void 
 */ 
void LED_Init(port_letter_t PORT_x, led_number_t LEDx);



/**
 * @brief Blink given LED/LEDs
 * 
 * @param1  Microcontroller port letter: PORT_x [x = 'A', 'B' or 'C']
 * @param2  LED number: LEDx [x = 0...7]
 * 
 * @return void 
 */
void LED_Blink(port_letter_t PORT_x, led_number_t LEDx);



/**
 * @brief Turn ON given LED/LEDs
 * 
 * @param1  Microcontroller port letter: PORT_x [x = 'A', 'B' or 'C']
 * @param2  LED number: LEDx [x = 0...7]
 * 
 * @return void
 */ 
void LED_ON(port_letter_t PORT_x, led_number_t LEDx);



/**
 * @brief Turn OFF given LED/LEDs
 * 
 * @param1  Microcontroller port letter: PORT_x [x = 'A', 'B' or 'C']
 * @param2  LED number: LEDx [x = 0...7] 
 * 
 * @return void
 */ 
void LED_OFF(port_letter_t PORT_x, led_number_t LEDx); 
