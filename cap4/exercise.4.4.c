/*
 * Created: Qua 05 Jan 2011 14:16:03 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 4-4: Add the commands to print the top elements of the stack without poppin, to duplicate it, and to
 * swap the top two elements. Add a command to clear the stack */

#include <stdio.h>

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
    if (sp > 0)
        return val[sp - 1];
    else
        printf("error: stack empty\n");
}

void duplicate(void){
    int i;
    i = sp - 1;
    val[sp++] = val[i];
}

void swap(void){
    int aux = val[sp - 2];
    val[sp - 2] = val[sp - 1];
    val[sp - 1] = aux;
}

void clear(void){
    sp = 0;       
}

int main (int argc, char const* argv[])
{
    push(1.0);
    push(2.0);
    push(3.0);
    push(4.0);
    push(5.0);
    push(6.0);

    return 0;
}
