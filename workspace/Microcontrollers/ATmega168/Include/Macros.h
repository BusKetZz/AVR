/**
 * File: Macros.h
 * 
 * Author: Jakub Standarski
 * 
 * Date: 29.11.2019
 */



/*****************************************************************************/
/*                              GENERIC MACROS                               */
/*****************************************************************************/

#define SET_BIT(register, bit)      (register |= (1 << bit))
#define CLEAR_BIT(register, bit)    (register &= ~(1 << bit))
#define TOGGLE_BIT(register, bit)   (register ^= (1 << bit))
#define CLEAR_FLAG(register, bit)   (register |= (1 << bit))
