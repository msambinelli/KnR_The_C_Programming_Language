/*
 * Created: 2011-01-07T17:13:39
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* As written, getint treats a + or - not followed by a digit as a valid
 * representation of zero. Fiz it to push such a character back on the input. */

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input int *pn */
int getint (int *pn)
{
    int c, sign, aux;

    while (isspace(c = getch())) ;

    if (!isdigit(c) &&  c != EOF && c != '+' && c != '-') {
	ungetch (c);
	return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
	aux = c;
	while (isspace(c = getch())) ;
	if (!isdigit(c)) {
	    ungetch(c);
	    ungetch(aux);
	    return 0;
	} 
    }
    
    for (*pn = 0; isdigit(c); c = getch())
	*pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
	ungetch(c);
    return c;
}

int main(int argc, char *argv[])
{
    int n, c;
    while ((c = getint(&n)) != EOF && c != 0)
	printf ("%d\n", n);
    if (!c)
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

