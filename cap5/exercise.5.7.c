/*
 * Created: 2011-01-16T14:50:22
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Rewrite readline to store lines in an array supplied main, rather than calling alloc
 * to maintain storage. How much faster is the program? */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], char buffer[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

#define BUFSIZE 1000 /* size of available space */

/* sort input lines */
int main()
{
    int nlines; /* number of input lines read */
    char allocbuf[BUFSIZE]; /* storage for alloc */
    
    if ((nlines = readlines(lineptr, allocbuf, MAXLINES)) >= 0) {
	qsort (lineptr, 0, nlines - 1);
	writelines(lineptr, nlines);
	return 0;
    } else {
	printf ("error: input too big to sort\n");
	return 1;
    }
}

/* swap: interchanges v[i] and v[j] */
void swap (char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* qsort: sort v[left]...v[right] int increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) /* do nothing if array contains */
	return;        /* fewer than two elements */

    swap (v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
	if (strcmp(v[i], v[left]) < 0)
	    swap (v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}
    

#define MAXLEN 1000 /* max length of any input line */
int _getline(char *, int);


/* readlines: read input lines */
int readlines(char *lineptr[], char buffer[], int maxlines)
{
    int nlines, len;
    char *bufp; /* next free position */
    char line[MAXLEN];

    nlines = 0;
    bufp = buffer;
    
    while ((len = _getline(line, MAXLEN)) > 0){
	if (buffer + BUFSIZE - bufp < len)
	    return -1;
	line[len - 1] = '\0';
	strcpy(bufp, line);
	lineptr[nlines++] = bufp;
	bufp += len;
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; ++i) {
	printf ("%s\n", lineptr[i]);
    }
}


/* getline: read a line int s, return lenght */
int _getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	s[i] = c;
    if (c == '\n')
	s[i++] = c;
    
    s[i] = '\0';
    return i;
}
