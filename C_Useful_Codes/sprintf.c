/*
 *  Function which allows universal formatting of strings, additionally providing 
 *  conversion of float type into string.
 *  This function is slow and takes quite a lot of memory space.
 * 
 *  @REMEMBER   :   Using sprintf function (and others similar) it is necessary to provide
 *                  enough size of the buffer in which resides converted string.
 *                  These functions do not check whether buffer has enough space. 
 *                  If buffer is too small, neighboring memory fields will be overwritten,
 *                  it can cause unpredictable behaviour of the program.
 * 
 */

#include <stdio.h>

int main(void)
{
    char buffer[20];
    double z = 12.345678;
    sprintf(buffer, "%+12.3e", z);  // result: buffer includes '<space><space>+1.235e+01'

    return 0;
}

