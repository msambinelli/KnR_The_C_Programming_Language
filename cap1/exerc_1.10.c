/*
 * Created: Seg 27 Dez 2010 18:50:44 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercises 1-10: Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and
 * backslash by \\. This makes tabs and backspaces visible in an unambiguous way
 */

#include <stdio.h>

main () {
    int c;
    while ((c = getchar()) != EOF){
        if (c == '\t')
            printf ("\\t");
        else if (c == '\b')
            printf ("\\b");
        else if (c == '\\')
            printf ("\\");
        else
            putchar(c);
    }
}
