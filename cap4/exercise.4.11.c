/*
 * Created: 2011-01-06T20:52:38
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 4-11: Modify getop so that it doesn't need to use ungetch. Hint
   use an internal static variable */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP   100 /* max size of operand  or operator */
#define NUMBER  '0' /* signal that a number was found */
#define NVAR    26
#define SIN     '1'
#define COS     '2'
#define EXP     '3'
#define POW     '4'
#define VAR_SET '5'
#define VAR_GET '6'
#define EMPTY -2

int getop(char []);
void push(double);
double pop(void);
double top(void);
int strcmp(char s1[], char s2[]);
int strlen(char s[]);

double var[NVAR];

int getop(char s[]){
    static int c = EMPTY;

    int i =  0;
    if (c == EMPTY)
	c = getchar();
    s[0] = c;
    while (c == ' ' || c == '\t')
	s[0] = c = getchar();
    
    if (c == '+' || c == '-' || isdigit(c)){
	while (isdigit(s[++i] = c = getchar())) ;
	if (c == '.')
	    while (isdigit(s[++i] = c = getchar())) ;
	s[i] = '\0';
	if (strlen(s) == 1 && !isdigit(s[0]))
	    return s[0];
	else
	    return NUMBER;
    } else if (isalpha(c)){
	while (isalpha(s[++i] = c = getchar())) ;
	s[i] ='\0';
	if (!strcmp(s, "SIN"))
	    return SIN;
	else if (!strcmp(s, "COS"))
	    return COS;
	else if (!strcmp(s, "EXP"))
	    return EXP;
	else if (!strcmp(s, "POW"))
	    return POW;
	else if (strlen(s) == 1){ /* is a variable */
	    return (islower(s[0])) ? VAR_GET : VAR_SET;
	} else
	    printf ("error: unknow function %s\n", s);
    } else {
	c = EMPTY;
	s[1] = '\0';
	return s[0];
    }
}
    

#define MAXVAL  100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f){
    if (sp < MAXVAL)
        val[sp++] = f;
    else 
        printf("error: stack full, can't push %g\n", f);
}

double pop(void){
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");    
        return 0.0;
    }
}

double top(void){
    if (sp > 0){
        return val[sp - 1];       
    } else{
        printf("error: stack empty\n");       
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* reverse Polish Calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch(type){
            case NUMBER:
                push(atof(s));
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
                if (op2 != 0.0)
                    push(pop() / op2);
                else 
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                push ((int) pop() % (int) op2);
                break;
            case SIN:
                push(sin(pop()));
                break;
            case COS:
                push(cos(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case VAR_SET:
                var[s[0] - 'A'] = top();
                break;
            case VAR_GET:
                push(var[s[0] - 'a']);
                break;
            case '\n':
                printf ("\t%.8g\n", op2 = pop());
                var['R' - 'A'] = op2;
                break;
            default:
                printf ("error: unknown command %s", s);
                break;
        }
    }
    return 0;       
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next gree position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();       
}

void ungetch(int c) /* get character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int strcmp(char s1[], char s2[]){
    int i, c;
    for (i = 0; (c = s1[i] - s2[i]) == 0 && s1[i] != '\0'; i++);
    return c; 
}

int strlen(char s[]){
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}
