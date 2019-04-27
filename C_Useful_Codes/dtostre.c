/*
 *  Function which converts number of type double (float as well) into string
 *  in such a format:   [-]z.zzze±zz
 * 
 *  @function prototype   :   char* dtostre (double __val, char* __s, unsigned char __prec, unsigned char __flags);
 * 
 *  @param        __val   :   number to convert
 *  @param        __s     :   pointer to buffer in which conversion result will be placed
 *  @param        __prec  :   decimal precision
 *  @param        __flags :   conversion parameters:
 *                            - DTOSTRE_UPPERCASE   - E instead of e
 *                            - DTOSTRE_ALWAYS_SIGN - space before positive numbers
 *                            - DTOSTRE_PLUS_SIGN   - '+' will be added before positive numbers
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
    dtostre(z, buffer, 2, 0);   // result: buffer stores string '1.23e+01'

    return 0;
}


