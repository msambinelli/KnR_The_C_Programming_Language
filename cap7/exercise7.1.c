/*
 * Created: 2011-01-23T20:03:06
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 7.1: Write a program that converts upper case to lower or lower
 * case to upper, depending on the name it is invoked with, as found in argv[0] */

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    int (*func)(int);
    int c;

    if (!strcmp(*argv, "tolower")) {
	func = tolower;
    } else if (!strcmp(*argv, "toupper")) {
	func = toupper;
    } else {
	printf ("error: name %s invalid\n", *argv);
	return 1;
    }

    while ((c = getchar()) != EOF)
	putchar(func(c));

    return 0;
}
