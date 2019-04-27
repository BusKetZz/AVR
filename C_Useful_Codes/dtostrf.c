/*
 *  Function which converts number of type double (float as well) into string
 *  in such a format:   [-]x.y
 * 
 *  @function prototype   :   char* dtostrf (double __val, signed char __width, unsigned char __prec, char* __s);
 * 
 *  @param        __val   :   number to convert
 *  @param        __s     :   pointer to buffer in which conversion result will be placed
 *  @param        __prec  :   decimal precision
 *
 *  @return               :   buffer address in which conversion result resides (equal to address given in __s)
 * 
 *  @note                 :   it is important, that buffer, which stores result, has sufficient size
 * 
 */

#include <stdlib.h>

int main(void)
{
    char buffer[20];
    float z = 12.345678;
    dtostre(z, 0, 2, buffer);   // result: buffer stores string '12.35'

    return 0;
}