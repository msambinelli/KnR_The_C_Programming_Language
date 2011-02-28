/*
 * Created: 2011-01-08T20:06:11
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */


/* Exercise 5-6: Rewrite appropriate programs from earlier chapter and exercises with pointers instead
 * of array indexing. Good possibilities include getline (chapter 1 and 4), atoi, itoa, and
 * theirs variants (Chapter 2, 3 and 4). reverse (chapter 3), and strindex and getop (chapter 4). */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void _getline(char *line)
{
    int c;
    while (( c = *line++ = getchar()) != '\n' && c != EOF) ;
    *--line = '\0';
}

void do_reverse(char *i, char *j)
{
    if ( i < j ) {
	int aux = *i;
	*i = *j;
	*j = aux;
	do_reverse(i + 1, j - 1);
    }
}

void reverse(char *s)
{
    char *p;
    for (p = s; *p != '\0'; p++) ;
    do_reverse(s, p - 1);
}

int _atoi(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
	n = n * 10 + (*s - '0');
    return n;
}

void itoa(char *s, int n)
{
    char *p = s;
    int sign = n;

    do {
	*p++ = abs(n % 10) + '0';
    } while ((n /= 10));

    if (sign < 0)
	*p++ = '-';
    *p = '\0';
    reverse(s);
}

char* strindex(char *s, char *t)
{
    char *p = s;
    while (*p != '\0')
	p++;
    int nchars = strlen(t);
    for (p -= nchars; p >= s; p--)
	if (!strncmp(p, t, nchars))
	    return p;
    return NULL;
}

char* any(char *s1, char *s2)
{
    char *p;
    while (*s1 != '\0') {
	for (p = s2; *p != '\0' ; p++) {
	    if (*s1 == *p) {
		return s1;
	    }
	}
	s1++;
    }
    return NULL;
}

double _atof(char *s){
    int i, sign, valexp;
    double val, power, exp;

    while (isspace(*s))
	s++;
    sign = (*s == '-')? -1: 1;
    if (*s == '+' || *s == '-')
        s++;

    val = 0.0;
    while (isdigit(*s))
	val = val * 10 + (*s++ - '0');
	
    if (*s == '.'){
	s++;
        power = 1.0;
	while (isdigit(*s)){
	    val = val * 10 + (*s++ - '0');
            power *= 10;
	}
        val /= power;
    }

    if (*s == 'e' || *s == 'E'){
        s++;
        exp = (*s == '-')? 1.0 / 10 : 10;
        if (*s == '-' || *s == '+')
            s++;
	valexp = 0;
	while (isdigit(*s))
	    valexp = 10 * valexp + (*s++ - '0');
        for (i = 0; i < valexp; i++)
            val *= exp;
    }

    return val;
}


int main(int argc, char *argv[])
{
    char s[50] = "   45e2 abc";
    printf ("%f\n", _atof(s));
    return 0;
}

