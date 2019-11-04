/**
 * File: Button.h
 * 
 * Author: Jakub Standarski
 * 
 * Date: 04.11.2019
 */

#include <avr/io.h>



/*****************************************************************************/
/*                          PUBLIC OWN DATA TYPES                            */
/*****************************************************************************/

typedef uint8_t button_number_t;
typedef uint8_t port_letter_t;



/*****************************************************************************/
/*                              PUBLIC DEFINES                               */
/*****************************************************************************/

#define BUTTON0 (button_number_t)(1 << 0)
#define BUTTON1 (button_number_t)(1 << 1)
#define BUTTON2 (button_number_t)(1 << 2)
#define BUTTON3 (button_number_t)(1 << 3)
#define BUTTON4 (button_number_t)(1 << 4)
#define BUTTON5 (button_number_t)(1 << 5)
#define BUTTON6 (button_number_t)(1 << 6)
#define BUTTON7 (button_number_t)(1 << 7)


#define PORT_B  (port_letter_t)('B')
#define PORT_C  (port_letter_t)('C')
#define PORT_D  (port_letter_t)('D')


#define BAUD_9600   6U


/*****************************************************************************/
/*                       PUBLIC FUNCTIONS DECLARATIONS                       */
/*****************************************************************************/

/**
 * @brief Initialize button/buttons port's pin/pins
 * 
 * @param1 Microcontroller port letter: PORT_x [x = 'A', 'B' or 'C']
 * @param2 Button number: BUTTONx [x = 0...7]
 * 
 * @return void
 */ 
void Button_Init(port_letter_t PORT_x, button_number_t BUTTONx);



/**
 * @brief Read button/buttons port's pin/pins state
 * 
 * @param1 Microcontroller port letter: PORT_x [x = 'A', 'B' or 'C']
 * @param2 Button number: BUTTONx [x = 0...7]
 * 
 * @return 0 if GND, other value if Vcc  
 */
uint8_t Button_ReadState(port_letter_t PORT_x, button_number_t BUTTONx);
