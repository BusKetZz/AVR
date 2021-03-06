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
typedef char port_letter_t;



/*****************************************************************************/
/*                              PUBLIC DEFINES                               */
/*****************************************************************************/

#define PORT_B  (port_letter_t)('B')
#define PORT_C  (port_letter_t)('C')
#define PORT_D  (port_letter_t)('D')

#define BUTTON0 (button_number_t)(1 << 0)
#define BUTTON1 (button_number_t)(1 << 1)
#define BUTTON2 (button_number_t)(1 << 2)
#define BUTTON3 (button_number_t)(1 << 3)
#define BUTTON4 (button_number_t)(1 << 4)
#define BUTTON5 (button_number_t)(1 << 5)
#define BUTTON6 (button_number_t)(1 << 6)
#define BUTTON7 (button_number_t)(1 << 7)


#define BUTTON_PORT_B   PORTB
#define BUTTON_PORT_C   PORTC
#define BUTTON_PORT_D   PORTD

#define BUTTON_PIN_B    PINB
#define BUTTON_PIN_C    PINC
#define BUTTON_PIN_D    PIND

#define BUTTON_PC0      PC0
#define BUTTON_PC1      PC1
#define BUTTON_PC2      PC2
#define BUTTON_PC3      PC3
#define BUTTON_PC4      PC4
#define BUTTON_PC5      PC5
#define BUTTON_PC6      PC6




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
