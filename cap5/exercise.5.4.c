/*
 * Created: 2011-01-08T17:48:16
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 5.4: Write the function strend(s, t), which returns 1 if the  string
 * t occurs at the end of the string s, and zero otherwise. */

#include <stdio.h>

int strend(char *s, char *t)
{
    char *p = t;
    int nchar;
    
    while (*p != '\0') p++;
    nchar = p - t;
    p = s;
    while (*p != '\0')
	p++;
    p = p - nchar;
    if ( p < s )
	return 0;
    for ( ; *t != '\0'; t++, p++)
	if (*t != *p)
	    return 0;
    return 1;
}

int main(int argc, char *argv[])
{
    if (strend("maycon", "maycon"))
	printf ("ocorre\n");
    else
	printf ("nao ocorre\n");
    return 0;
}
