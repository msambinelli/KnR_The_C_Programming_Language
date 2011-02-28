/*
 * Created: 2011-01-23T23:15:37
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 7.3: Revise minprintf to handle more of the other facilities of printf */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#define MAXFMT 500

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
    va_list ap; /* pointer to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;
    char outfmt[MAXFMT], buftmp[MAXFMT];
    int minlen, prec;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */

    for (p = fmt; *p ; p++) {
	if (*p != '%') {
	    putchar(*p);
	    continue;
	}

	strcpy(outfmt, "%");

	if (*++p == '-'){
	    strcat(outfmt, "-");
	    p++;
	}

	minlen = -1;
	if (isdigit(*p) || *p == '*') {
	    if (*p == '*') {
		minlen = va_arg(ap, int);
		p++;
	    } else {
		sscanf (p, "%d", &minlen);
		while (isdigit(*++p)) ;
	    }
	}

	prec = -1;
	if (*p == '.') {
	    if (*p == '*') {
		prec = va_arg(ap, int);
		p++;
	    } else {
		p++;
		sscanf (p, "%d", &prec);
		while (isdigit(*++p)) ;
	    }
	}

	if (minlen != -1) {
	    sprintf (buftmp, "%d", minlen);
	    strcat(outfmt, buftmp);
	}

	if (prec != -1) {
	    sprintf (buftmp, ".%d", prec);
	    strcat (outfmt, buftmp);
	}

	switch (*p) {
	case 'd':
	    ival = va_arg(ap, int);
	    strcat(outfmt, "d");
	    printf(outfmt, ival);
	    break;
	case 'f':
	    dval = va_arg(ap, double);
	    strcat(outfmt, "f");
	    printf(outfmt, dval);
	    break;
	case 's':
	    sval = va_arg(ap, char *);
	    strcat(outfmt, "s");
	    printf (outfmt, sval);
	    break;
	default:
	    putchar(*p);
	    break;
	}
    }
    va_end(ap); /* clean up when done */
}

int main(int argc, char *argv[])
{
    printf ("%*.*f\n", 10, 2, 3.14151617);
    return 0;
}
