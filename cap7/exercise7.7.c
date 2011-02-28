/*
 * Created: 2011-01-26T15:18:05
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 7-7: Modify the patter finding program of Chapter 5 to take its
 * input from a set of named files or, if no files are named as arguments, from
 * the standard input. Should the file name be printed when a matching line is found? */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int status = 0;

#define MAXLINE 1000

void pattern_search(char *fname, char *pattern)
{
    FILE *fd;
    char line[MAXLINE];

    if (fname == NULL)
	fd = stdin;
    else
	fd = fopen(fname, "r");

    if (fd == NULL) {
	fprintf (stderr, "error: don't open file %s\n", fname);
	status = 1;
	return ;
    }

    while (fgets(line, MAXLINE, fd) != NULL) {
	if (strstr(line, pattern)) {
	    if (fname == NULL)
		printf ("%s", line);
	    else
		printf ("%s: %s", fname, line);
	}
    }

    fclose(fd);
}

#define MAXPATTERN 1000

int main(int argc, char *argv[])
{
    char pattern[MAXPATTERN];

    if (argc < 2) {
	fprintf (stderr, "%s: pattern is required\n", argv[0]);
	exit(1);
    }

    strcpy(pattern, *++argv);

    if (argc > 2) {
	while (*++argv)
	    pattern_search(*argv, pattern);
    } else
	pattern_search(NULL, pattern);

    return status;
}
