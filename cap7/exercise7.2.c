/*
 * Created: 2011-01-23T20:58:07
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 7-2: Write a program that will print arbitray input in in a sesible
 * way. As minimum, it should print non-graphic characters in octal or hexadecimal
 * according to local custom, and break long text lines */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


char form[] = "0x%x";
int wrapcol = 80;

void parseop(int argc, char *argv[])
{
    int c;

    while (--argc > 0) {
	if ((*++argv)[0] == '-') {
	    while ((c = *++argv[0])) {
		switch (c) {
		case 'o':
		    sprintf (form, "0%%%c", c);
		    break;
		case 'x':
		    sprintf (form, "0x%%%c", c);
		    break;
		case 'w':
		    wrapcol = atoi(*++argv);
		    argc--;
		    break;
		default:
		    printf ("error: unknow parameter -%c\n", c);
		    break;
		}
	    }
	} else
	    printf ("error: unknow parameter %s\n", *argv);
    }
}


int main(int argc, char *argv[])
{
    int col, c;

    parseop(argc, argv);

    col = 0;
    while ((c = getchar()) != EOF) {

	if(isalnum(c) || ispunct(c))
	    putchar(c);
	else if (isspace(c)) {
	    col = (c == '\n') ? 0 : col;
	    putchar (c);
	} else
	    printf (form, c);
	if (col >= wrapcol) {
	    printf ("\n»");
	    col = 0;
	}
	col++;
    }
    return 0;
}
