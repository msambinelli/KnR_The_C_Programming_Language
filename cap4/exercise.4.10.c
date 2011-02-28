/*
 * Created: Seg 03 Jan 2011 22:53:21 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 4-10: An alternate organization uses getline toread an entire input line; this makes
 * getch and ungetch unnecessary. Revise the calculator to use this approach */

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

int getop(char []);
void push(double);
double pop(void);
double top(void);
int strcmp(char s1[], char s2[]);
int _getline(int s[], int limit);

double var[NVAR];

int carrier = 0;
int command[MAXOP];

/* reverse Polish Calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    _getline(command, MAXOP);

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
                _getline(command, MAXOP);
                carrier = 0;
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

double top(void){
    if (sp > 0){
        return val[sp - 1];       
    } else{
        printf("error: stack empty\n");       
        return 0.0;
    }
}

#include <ctype.h>

/* getop: get next character or numeric operand */
int getop(char s[]){

    int c, next, i;

    while ((s[0] = c = command[carrier++]) == ' ' || c == '\t') ;

    if (c == '\n' || c == EOF)
        return c;

    next = command[carrier];

    if (isdigit(c) || (( c == '+' || c == '-') && isdigit(next))){
        s[i = 0] = c;
        while (isdigit(s[++i] = c = command[carrier++])) ;
        if (c == '.'){
            while (isdigit(s[++i] = c = command[carrier++])) ;
        } 
        carrier--;       
        s[i] = '\0';
        c = NUMBER;
    } else if (isalpha(c)){
        i = 0;
        while (isalpha(s[++i] = c = command[carrier++])) ;
        carrier--;
        s[i] = '\0';
        if (i > 1){
            if (!strcmp(s, "SIN")){
                return SIN;       
            } else if (!strcmp(s, "COS")){
                return COS;       
            } else if (!strcmp(s, "EXP")){
                return EXP;       
            } else if (!strcmp(s, "POW")){
                return POW;       
            } else {
                printf("error: unknow functions %s\n", s);       
            }
        } else {
            if  (islower(s[0]))
                return VAR_GET;       
            else 
                return VAR_SET;
        }
    } else {
        s[0] = c;
        s[1] = '\0';
    }
    return c; 
}

int strcmp(char s1[], char s2[]){
    int i, c;
    for (i = 0; (c = s1[i] - s2[i]) == 0 && s1[i] != '\0'; i++);
    return c; 
}

int _getline(int s[], int limit){
    int i, c;
    for (i = 0; i < limit - 2 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    s[i++] = c;
    s[i] = '\0';
    return i;
}
