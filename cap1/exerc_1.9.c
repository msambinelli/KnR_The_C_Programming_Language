/*
 * Created: Seg 27 Dez 2010 15:25:14 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
#include <stdio.h>

#define BLANK   0
#define NOBLANK 1

main ()
{
    int c, state;

    state = NOBLANK;
    while ((c = getchar()) != EOF){
        if (state == BLANK){
            if (c != ' ') {
                putchar(c);
                state = NOBLANK;
            }
        } else {
            putchar (c);
            if (c == ' ')
                state = BLANK;
        }
    }
}

