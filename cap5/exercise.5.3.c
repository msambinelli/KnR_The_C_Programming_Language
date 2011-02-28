/*
 * Created: 2011-01-08T17:29:21
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 5-3: Write a poiter version of the function strcat that we showed in Chapter 2:
 * strcat (s, t) copies the string t to the end of s. */

#include <stdio.h>


void _strcat (char *s, char *t)
{
    while (*s != '\0') s++;
    while ((*s++ = *t++)) ;
}


int main(int argc, char *argv[])
{
    char first[50] = "maycon";
    char last[50] = " sambinelli";
    _strcat (first, last);
    printf ("%s\n", first);
    return 0;
}

