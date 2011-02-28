/*
 * Created: Qua 29 Dez 2010 23:17:34 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 2-7: Write a function invert(x, p, n) that returns x with the n bits that begin
 * at position p inverted (i.e. 1 canged into 0 and vice versa), leaving the others unchanged */

#include <stdio.h>

unsigned invert(unsigned x, unsigned p, unsigned n){
    int newbits;

    newbits = (~x >> (p + 1 - n) & ~(~0 << n)) << (p + 1 -n);
    x = ~(~(~0 << n) << (p + 1 - n)) & x;

    return x | newbits;
}

int main ()
{
    printf("%x\n", invert(0xfbf, 7, 8));
    return 0;
}
