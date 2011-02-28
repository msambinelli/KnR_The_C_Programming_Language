/*
 * Created: Seg 27 Dez 2010 19:22:03 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 1-12. Write a program that prints its input one word per line. */

#include <stdio.h>

#define OUT 0
#define IN  1

main ()
{
    int c, state;

    state == OUT;
    while ((c = getchar()) != EOF){
        if (state == IN){
            if (c == ' ' || c == '\t' || c == '\n'){
                state = OUT;
                putchar ('\n');    
            } else 
                putchar(c);
        } else {
            if (c != ' ' && c != '\t' && c != '\n'){
                state = IN;
                putchar(c);
            }
        }
    }
}
