/*
 * Created: Qui 30 Dez 2010 00:03:27 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 2-8: Write a function rightrot(x, n) that returns the value
of the integer x rotated to the right by n positions. */

#include <stdio.h>

unsigned rightrot(unsigned x, unsigned n){
    unsigned fall = ((~(~0 << n)) & x) << (32 - n);    
    x = x >> n;
    return fall | x;
}

int main ()
{
    printf("%x\n", rightrot(0xbcd0000a, 24));
    return 0;
}
