/*
 * Created: 2011-01-26T16:04:18
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 7-8: Write a program to print a set of files, starting each new one on a
 * new page, with a litle and a running page count for each file. */

#include <stdio.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
    int count = 0;
    FILE *fd;
    char line[MAXLINE];
    int status = 0;

    while (*++argv) {
	fd = fopen (*argv, "r");

	if (fd == NULL) {
	    status = 1;
	    fprintf (stderr, "error: don't open fine %s\n", *argv);
	    continue;
	}

	printf ("title: %s\t\tpage: %d\n\n", *argv, ++count);

	while (fgets(line, MAXLINE, fd) != NULL)
	    printf ("%s", line);
	printf ("\n\n");
	fclose (fd);
    }
    return status;
}
