/*
 * Created: 2011-01-26T14:37:27
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 7-6: Write a program to compare two files. Printing the first line
 * where they differ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *Fopen(char *file_name, char *perm)
{
    FILE *fd;
    if ((fd = fopen(file_name, perm)) == NULL) {
	fprintf (stderr, "error: on open file %s\n", file_name);
	exit(1);
    }
    return fd;
}

#define MAXLINE 1000
#define MAXNAME 255

int main(int argc, char *argv[])
{

    FILE *file1, *file2;
    char *o1, *o2;
    char line1[MAXLINE], line2[MAXLINE];
    char file_name1[MAXNAME], file_name2[MAXNAME];

    if (argc < 3) {
	fprintf (stderr, "%s: arguments required\n", argv[0]);
	exit (1);
    }

    strcpy(file_name1, *++argv);
    strcpy(file_name2, *++argv);

    file1 = Fopen(file_name1, "r");
    file2 = Fopen(file_name2, "r");

    while (1) {
	o1 = fgets(line1, MAXLINE, file1);
	o2 = fgets(line2, MAXLINE, file2);

	if (o1 == NULL || o2 == NULL)
	    break;

	if (strcmp(line1, line2) != 0) {
	    printf ("%s: %s", file_name1, line1);
	    printf ("%s: %s", file_name2, line2);
	    return 0;
	}
    }

    if (o1 != o2) {
	if (o1 != NULL)
	    printf ("%s: %s", file_name1, line1);
	else
	    printf ("%s: %s", file_name2, line2);
    }

    fclose (file1);
    fclose (file2);

    return 0;
}
