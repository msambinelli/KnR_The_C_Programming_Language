/*
 * Created: Seg 03 Jan 2011 22:53:21 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 4-3: Given the basic framework, it's straighforward to extend the calculator. 
 * Add the modulus (%) operator and provisions for  negative numbers. */

#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP   100 /* max size of operand  or operator */
#define NUMBER  '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish Calculator */
main()
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
            case '\n':
                printf ("\t%.8g\n", pop());
                break;
            default:
                printf ("error: unknown command %s", s);
                break;
        }
    }
    return 0;       
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

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[]){

    int c, next, i;

    while ((s[0] = c = getch()) == ' ' || c == '\t') ;

    if (c == '\n' || c == EOF)
        return c;

    next = getch();
    ungetch(next);
    if (isdigit(c) || (( c == '+' || c == '-') && isdigit(next))){
        s[i = 0] = c;
        while (isdigit(s[++i] = c = getch())) ;
        if (c == '.'){
            while (isdigit(s[++i] = c = getch())) ;
        } else {
            ungetch(c);       
        }
        s[i] = '\0';
        c = NUMBER;
    } else {
        s[0] = c;
        s[1] = '\0';
    }

    return c; 
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
