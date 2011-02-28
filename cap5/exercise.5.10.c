/*
 * Created: 2011-01-16T19:06:34
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 5-10: Write the program expr, which evaluates a reverse Polish
 * expression from the command line, where each operator or operand is a separate argument. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'

double pop(void);
void push(double);
int getop(char *);

int main(int argc, char *argv[])
{
    int c;
    double op2;
    
    while (--argc > 0) {
	switch (c = getop(*++argv)) {
	case NUMBER:
	    push(atof(*argv));
	    break;
	case '+':
	    push(pop() + pop());
	    break;
	case '*':
	    push(pop() * pop());
	    break;
	case '-':
	    op2 = pop();
	    push(pop() - op2);
	    break;
	case '/':
	    op2 = pop();
	    if (op2 != 0)
		push(pop() / op2);
	    else
		printf ("error: division by zero\n");
	    break;
	default:
	    printf ("error: invalid operation %c\n", c);
	    return 1;
	    break;
	}
    }
    printf ("\t%f\n", pop());
    return 0;
}

int getop(char *s)
{
    if (!isdigit(s[0]) && s[1] == '\0')
	return s[0];
    return NUMBER;
}

#define STACKSIZE 10000

double val[STACKSIZE]; /* stack value */
int sp = 0; /* stack position: next free position */

double pop(void)
{
    if (sp > 0)
	return val[--sp];
    else
	printf ("error: empty stack\n");
    return 0.0;
}

void push(double f)
{
    if (sp < STACKSIZE)
	val[sp++] = f;
    else
	printf ("error: full stack\n");
}
