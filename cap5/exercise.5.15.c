/*
 * Created: 2011-01-18T20:00:23
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 5-15: Add the option -f to fold upper and lower case together,
 * so that casa distinctions are not made during sorting; for example, a and
 * A compare equal */

#include <stdio.h>
#include <string.h>

#define MAXLINES 500 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void _qsort(void *lineptr[], int left, int right, int (*comp) (void *, void *));

int numcmp(char *, char *);
int rnumcmp(char *s1, char *s2);
int rstrcmp(char *s1, char *s2);
int fstrcmp(char *s1, char *s2);
int rfstrcmp(char *s1, char *s2);

void getop(int argc, char *argv[], int *n, int *r, int *f)
{
    int c;

    *n = *r = *f = 0;

    while (--argc > 0) {
	if ((*++argv)[0] == '-') {
	    while ( (c = *++argv[0]) != '\0') {
		switch(c){
		case 'r':
		    *r = 1;
		    break;
		case 'n':
		    *n = 1;
		    break;
		case 'f':
		    *f = 1;
		    break;
		default:
		    printf ("error: unknow option %c\n", c);
		    break;
		}
	    }
	}
    }
}

void* select_function(int n, int r, int f)
{

    if (n) {
	return (r) ? rnumcmp : numcmp;
    } else {
	if (!f) {
	    return (r) ? rstrcmp : (int (*) (char *, char *)) strcmp;
	} else {
	    return (r) ? rfstrcmp : fstrcmp;
	}
    }
}


/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    int reverse = 0; /* 1 if reverset sort */
    int fold;

    getop(argc, argv, &numeric, &reverse, &fold);

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
	_qsort((void**) lineptr, 0, nlines - 1, select_function(numeric, reverse, fold));
	writelines (lineptr, nlines);
	return 0;
    } else {
	printf ("input too big to sort\n");
	return 1;
    }
}

/* qsort: sort v[left]...v[right] into increasing order */
void _qsort(void *v[], int left, int right, int (*comp) (void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) /* do nothing if array contains */
	return ;       /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
	if ((*comp) (v[i], v[left]) < 0)
	    swap(v, ++last, i);
    }
    swap(v, left, last);
    _qsort(v, left, last - 1, comp);
    _qsort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#include <stdlib.h>

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    return v1 - v2;
}

int rnumcmp(char *s1, char *s2)
{
    return -numcmp(s1, s2);

}

int rstrcmp(char *s1, char *s2)
{
    return -strcmp(s1, s2);
}

#include <ctype.h>

int fstrcmp(char *s1, char *s2)
{
    for ( ; *s1 != '\0' && tolower(*s1) == tolower(*s2); s1++, s2++) ;
    return tolower(*s1) - tolower(*s2);
}

int rfstrcmp(char *s1, char *s2)
{
    return -fstrcmp(s1, s2);
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

char *alloc(int n);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0)
	if (nlines >= maxlines || (p = alloc(len)) == NULL)
	    return -1;
	else {
	    line[len - 1] = '\0'; /* delete newline */
	    strcpy (p, line);
	    lineptr[nlines++] = p;
	}
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
	printf ("%s\n", lineptr[i]);
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
	allocp += n;
	return allocp - n; /* old p */
    } else
	return 0;
}
