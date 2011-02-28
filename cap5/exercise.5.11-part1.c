/*
 * Created: 2011-01-16T20:07:31
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 5-11: Modify the program entab and detab (written as exercises in
 * Chapter 1) to accept a list of tab stops as arguments. Use the default tab settings
 * if there are no arguments */

#include <stdio.h>
#include <stdlib.h>

void insert_ts(int ts);

#define MAXLEN 1000

void display_line(char *);

int _getline(char s[], int limits)
{
    int i, c;
    for (i = 0; i < limits - 1 && (c = s[i] = getchar()) != EOF && c != '\n'; ++i) ;
    if (c == '\n')
	i++;
    s[i] = '\0';
    return i;
}



int main(int argc, char *argv[])
{
    char line[MAXLEN];
    
    while (--argc > 0)
	insert_ts(atoi(*++argv));
    while (_getline(line, MAXLEN) > 0) {
	display_line(line);
    }
    return 0;
}

int insert_tab(int);

void display_line(char *s)
{
    int i, cur;
    for (i = 0, cur = 0; s[i] != '\0'; i++){
	if (s[i] == '\t')
	    cur = insert_tab(cur);
	else {
	    putchar(s[i]);
	    cur++;
	}
    }
}

#define MAXTS 100
int tab_stop[MAXTS];
int nts = 0; /* next free tab stop index */

void insert_ts(int ts)
{
    tab_stop[nts++] = ts;
}

#define DEFAULT_TS 4;

int insert_tab(int cur)
{
    int i, ts;

    for (i = 0; i < nts && tab_stop[i] <= cur; i++) ;

    ts = tab_stop[i];
    if (nts == i){
	ts = (nts != 0) ? tab_stop[nts - 1] : 0;
	while (ts <= cur)
	    ts += DEFAULT_TS;
    }
   
    for (; cur < ts; cur++)
	putchar(' ');
    return cur;
}
