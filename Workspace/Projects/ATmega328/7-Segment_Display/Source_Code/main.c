/**
 *  Project: 8-segment Display
 * 
 *  File: main.c
 * 
 *  Author: Jakub Standarski 
 *
 *  Date: 08.10.2019
 */

#include <avr/io.h>



int main(void)
{   
    /* Set Port B, Pin 1 and Pin 2 as an input */
    DDRB &= ~((1 << PIN1) | (1 << PIN2));

    /* Set Port B, 
}