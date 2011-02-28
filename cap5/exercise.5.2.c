/*
 * Created: 2011-01-07T17:50:38
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 5-2: Write getfloat, the floating-point analog of getint. What type does getfloat
 * returns as its function value? */

#include <stdio.h>
#include <math.h>

void ungetch(int);
int getch(void);

int getfloat(double *n) {
    int c, signal, exp, expsign;
    double p;
    
    while (isspace (c = getch())) ;

    if (!isdigit(c) && c != EOF && c != '.' && c != '+' && c != '-') {
	ungetch(c);
	return 0;
    }

    signal = ( c == '-' ) ? -1 : 1;
    if (c == '+' || c == '-')
	c = getch();

    for (*n = 0.0; isdigit(c); c = getch())
	*n = *n * 10 + (c - '0');
    
    if (c == '.')
	c = getch();

    for (p = 1.0; isdigit(c); c = getch()) {
	*n = *n * 10 + (c - '0');
	p *= 10;
    }

    *n /= p;

    if (c == 'e' || c == 'E') {
	c = getch();
	expsign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
	    c = getch();
	for (exp = 0; isdigit(c); c = getch())
	    exp = exp * 10 + (c - '0');

	*n *= pow(10, exp * expsign);
    }

    if (c != EOF)
	ungetch(c);
    return c;
}

int main(int argc, char *argv[])
{
    int c;
    double num;
    while ((c = getfloat(&num)) != EOF && c != 0)
	printf ("%f\n", num);
    if (c == 0)
	printf ("error: input is not a number\n");
    return 0;
}

#define BUFSIZE 100

int buffer[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp < BUFSIZE)
	buffer[bufp++] = c;
    else
	printf ("error: buffer is full\n");
}
