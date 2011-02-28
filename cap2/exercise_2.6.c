/*
 * Created: Qua 29 Dez 2010 22:45:29 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 2-6: Write a function setbits (x, p, n, y) that returns x with
 * the n bits that begin at position p set to the rightmost n bits of y, leaving
 * the other bits unchanged. */

#include <stdio.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y){
    return (x & ~(~(~0 << n) << (p -n + 1))) | ((y & ~(~0 << n)) << (p - n + 1));
}

int main ()
{
    printf ("%x\n", setbits(0xff, 4, 5, 0x0c)); 
    return 0;
}
