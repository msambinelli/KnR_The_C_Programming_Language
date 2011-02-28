/*
 * Created: 2011-01-24T18:46:17
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 7-4: Write a private version of scanf analogous to minprintf
 * from the previous section */

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

#define MAXSTRING 1000

void minscanf(char *fmt, ...)
{
    va_list ap;
    char *p;
    int c;

    int ival, *idest;
    float dval, *ddest;
    char cval, *cdest;
    char sval[MAXSTRING], *sdest;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */

    for (p = fmt; *p; p++) {

	if (isspace(*p))
	    continue;

	if (*p != '%') {
	    while ((c = getchar()) != EOF && isspace(c));
	    if(c != *p) {
		va_end(ap);
		return ;
	    }
	    continue;
	}

	switch (*++p) {
	case 'd':
	    scanf ("%d", &ival);
	    idest = va_arg(ap, int *);
	    *idest = ival;
	    break;
	case 'f':
	    scanf ("%f", &dval);
	    ddest = va_arg(ap, float *);
	    *ddest = dval;
	    break;
	case 'c':
	    cval = getchar();
	    cdest = va_arg(ap, char *);
	    *cdest = cval;
	    break;
	case 's':
	    scanf ("%s", sval);
	    sdest = va_arg(ap, char *);
	    strcpy(sdest, sval);
	    break;
	default:
	    while ((c = getchar()) != EOF && c != *p);
	    break;
	}
    }
    va_end(ap); /* clean up when done */
}

int main(int argc, char *argv[])
{
    float f, f2;
    char s[50];
    char c;
    int n1, n2;
    minscanf("%f %s %f %c", &f, s, &f2, &c);
    printf ("%f %s %F %c", f, s, f2, c);
    return 0;
}
