/*
 * Created: 2011-01-08T19:18:29
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exircise 5-5: Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most
 * the first n characters of their argument strings. For example, strncpy(s, t, n) copies at most n characters
 * of t to s. Full descriptions are in Appendix B. */

#include <stdio.h>

void _strncat(char *s, char *t, int n)
{
    int i, c;
    while (*s != '\0') s++;
    for (i = 0; i < n && (c = *s++ = *t++) != '\0'; i++) ;

    if (c != '\0')
	*s = '\0';
}

void _strncpy(char *s, char *t, int n)
{
    int i, c;
    for (i = 0; i < n && (c = *s++ = *t++) != '\0'; i++) ;
    if (c != '\0')
	*s = '\0';
}

int _strncmp(char *s, char *t, int n)
{
    int i;
    for (i = 0; i < n && *s != '\0'; i++)
	if (*s ++ != *t++)
	    return *--s - *--t;
    return (*s == *t) ? 0 : *s - *t;
}


int main(int argc, char *argv[])
{
    char first[50] = "maycon";
    char last[50] = "maycx";
    int c;
    if ((c = _strncmp("z", "yayc", 10)) == 0)
	printf ("igual\n");
    else
	printf ("diferente\n");
    printf ("diferenca: %d\n", c);
    return 0;
}
