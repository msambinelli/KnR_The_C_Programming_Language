/*
 * Created: 2011-01-18T15:35:23
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */


/* Exercise 5-13: Write a program tail, which prints the last n line of its input.
 * By default, n is set to 10, let us say, but it can be changed by an optional
 * argument so that

   tail -n

 * prints the last n lines. The program should behave rationally no matter how unreasonable
 * the input or the value of n. Write the program so it makes the best use of available storage; lines
 * should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of fixed
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 1000

char *readline(void);

int main(int argc, char *argv[])
{
    int nlines = 10;
    char *lines[MAXLINES];
    char *line;
    int i;

    if (argc == 2) {
	nlines = atoi (argv[1]);
	nlines = -nlines;
    }

    while ((line = readline()) != NULL) {

	free(lines[0]);
	for (i = 0; i < nlines - 1; i++) {
	    lines[i] = lines[i + 1];
	}
	lines[nlines - 1] = line;
    }

    for (i = 0; i < nlines; i++)
	if (lines[i] != NULL)
	    printf ("%s", lines[i]);
    return 0;
}

int _getline(char s[], int limits)
{
    int i;
    for (i = 0; i < limits - 1 && (s[i] = getchar()) != EOF && s[i] != '\n'; i++) ;
    if (s[i] == '\n')
	i++;
    s[i] = '\0';
    return i;
}

#define MAXLEN 1000

char *readline(void)
{
    char buf[MAXLEN];
    int len;
    char *line;

    len = _getline(buf, MAXLEN);

    if (len == 0)
	return NULL;

    line = malloc((len + 1) * sizeof(char));
    strcpy(line, buf);
    return line;
}

