/*
 * Created: 2011-01-16T22:13:27
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

int next_ts(int cur);

void detab(char *s)
{
    int i, j, k, ts;
    
    for (i = 0, j = 0; s[i] != '\0'; j++) {
	if (s[i] != ' ') {
	    s[j] = s[i++];
	} else {
	    k = i + 1;
	    while (s[k] == ' ') k++;
	    while ((ts = next_ts(i)) <= k) {
		i = ts;
		s[j++] = '\t';
	    }
	    for (; i < k; ++i) {
		s[j++] = ' ';
	    }
	    j--;
	}
    }
    s[j] = '\0';
}

void show_line(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; ++i) {
	if (s[i] == '\t')
	    printf ("\\t");
	else
	    putchar(s[i]);
    }
}

int main(int argc, char *argv[])
{
    char line[MAXLEN];
    
    while (--argc > 0)
	insert_ts(atoi(*++argv));
    while (_getline(line, MAXLEN) > 0) {
	detab(line);
	show_line(line);
    }
    return 0;
}



#define MAXTS 100
int tab_stop[MAXTS];
int nts = 0; /* next free tab stop index */

void insert_ts(int ts)
{
    tab_stop[nts++] = ts;
}

#define DEFAULT_TS 4

int next_ts(int cur)
{
    int i, ts;
    for (i = 0; i < nts && tab_stop[i] <= cur; i++) ;

    ts = tab_stop[i];
    if (i == nts) {
	ts = (nts == 0) ? 0 : tab_stop[nts - 1];
	for ( ; ts <= cur; ts += DEFAULT_TS );
    }
    return ts;
}
