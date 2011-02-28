/*
 * Created: 2011-01-16T23:16:10
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 5-12: Extend entab and detab to accept the shorthand
 *
 * entab -m +n
 *
 * to mean tab stops every n columns, starting at column m. Choose convenient (for the user)
 * default behavior */

#include <stdio.h>
#include <stdlib.h>

#define MAXTS 100

int col_start = 2000;
int ts_step;
int tab_stop[MAXTS];
int nts = 0;

void getopt(int argc, char *argv[])
{
     while (--argc > 0) {
	switch ((*++argv)[0]) {
	case '-':
	    col_start = atoi(*argv + 1);
	    break;
	case '+':
	    ts_step = atoi(*argv + 1);
	    break;
	default:
	    tab_stop[nts++] = atoi(*argv);
	    break;
	}
    }
}

int _getline(char s[], int limits)
{
    int i;
    for (i = 0; i < limits - 1 && (s[i] = getchar()) != EOF && s[i] != '\n'; i++) ;
    s[i] = '\0';
    return i;
}

#define TS 4

int next_ts(int cur)
{
    int i, ts;

    for (i = 0; i < nts && tab_stop[i] <= cur; i++);

    if (i < nts)
	return tab_stop[i];

    if (cur < col_start) {
	ts = (nts == 0) ? 0 : tab_stop[nts - 1];
	for ( ; ts < cur; ts += TS);
    } else {
	ts = (nts == 0) ? 0 : tab_stop[nts - 1];
	for ( ; ts < col_start; ts += TS) ;
	for ( ; ts <= cur; ts += ts_step) ;
    }
    return ts;
}

void printline(char s[])
{
    int cur, newcur;
    int i;

    for (i = 0, cur = 0; s[i] != '\0'; ++i) {
	if (s[i] == '\t')
	    for (newcur = next_ts(cur); cur < newcur; cur++)
		putchar(' ');
	else {
	    putchar(s[i]);
	    cur++;
	}
    }
    putchar('\n');
}

#define MAXLEN 1000

int main(int argc, char *argv[])
{
    char line[MAXLEN];

    getopt(argc, argv);
    while (_getline(line, MAXLEN) > 0)
	printline(line);
    return 0;
}

