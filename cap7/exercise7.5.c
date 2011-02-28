/*
 * Created: 2011-01-26T21:11:14
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercises 7-5: Rewrite the postfix calculator of Chapter 4 to use scanf  and/or
 * sscanf to do the input and number conversion */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


#define MAXOP   100 /* max size of operand  or operator */
#define NUMBER  '0' /* signal that a number was found */
#define NVAR    26
#define SIN     '1'
#define COS     '2'
#define EXP     '3'
#define POW     '4'
#define VAR_SET '5'
#define VAR_GET '6'
#define ERROR   '7'

int getop(void);
void push(double);
double pop(void);
double top(void);

double var[NVAR];
char line[MAXOP];
char *ptr = NULL;
double dec_opt;
char c_opt;

char *refill(void)
{
    return fgets(line, MAXOP, stdin);
}

int getop(void)
{
    double dval;
    char cval;
    char sval[MAXOP];

    if (ptr == NULL) {
	if (refill() == NULL)
	    return EOF;
	ptr = line;
    }

    while (*ptr == ' ' || *ptr == '\t' || *ptr == '\0') {
	if (*ptr == '\0') {
	    if (refill() == NULL)
		return EOF;
	    ptr = line;
	} else
	    ptr++;
    }

    if ((sscanf (ptr, "%lf", &dval)) == 1) {
	while (isdigit(*ptr))
	    ptr++;
	if (*ptr == '.') {
	    ptr++;
	    while (isdigit(*ptr))
		ptr++;
	}
	dec_opt = dval;
	return NUMBER;
    }

    sscanf(ptr, "%c", &cval);
    if (cval == '+' ||  cval == '-' || cval == '*' || cval == '/' || cval == '%' || cval == '\n') {
	ptr++;
	return cval;
    }

    sscanf (ptr, "%s", sval);
    while (isalpha(*ptr))
	ptr++;
    if (!strcmp("SIN", sval)) {
	return SIN;
    } else if (!strcmp("COS", sval)) {
	return COS;
    } else if (!strcmp("EXP", sval)) {
	return EXP;
    } else if (!strcmp("POW", sval)) {
	return POW;
    } else if (strlen(sval) == 1) {
	c_opt = sval[0];
	return (isupper(sval[0])) ? VAR_SET : VAR_GET;
    } else
	return ERROR;
}

/* reverse Polish Calculator */
main()
{
    int type;
    double op2;

    while ((type = getop()) != EOF) {
        switch(type){
            case NUMBER:
                push(dec_opt);
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
                var[c_opt - 'A'] = top();
                break;
            case VAR_GET:
                push(var[c_opt - 'a']);
                break;
            case '\n':
                printf ("\t%.8g\n", op2 = pop());
                var['R' - 'A'] = op2;
                break;
            default:
                printf ("error: unknown command\n");
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

double top(void)
{
    if (sp > 0){
        return val[sp - 1];
    } else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

