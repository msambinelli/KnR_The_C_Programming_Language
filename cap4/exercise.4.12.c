/*
 * Created: 2011-01-06T23:28:34
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 4-12: Adapt the ideas of printd to write a recusive version of itoa;
 * that is, covert an integer into a string by calling a recursive routine */

#include <stdio.h>

int do_itoa(char s[], int n, int index)
{
     if (n < 0) {
	  s[index++] = '-';
	  n = -n;
     }

     if ( n / 10 ) {
	  index = do_itoa(s, n / 10, index);
     }
     s[index++] = (n % 10) + '0';
     return index;
}

void itoa(char s[], int n)
{
    int i = do_itoa (s, n, 0);
    s[i] = '\0';
}

int main(int argc, char *argv[])
{
     char s[255];
     itoa(s, -7845);
     printf ("%s\n", s);
     return 0;
}
