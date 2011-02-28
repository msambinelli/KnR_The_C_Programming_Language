/*
 * Created: Seg 03 Jan 2011 20:28:26 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 4-1. Write the function strindex(s, t) which returns the position
 * of the rightmost occurrence of t in s, or -1 if there is none */


#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int _getline(char s[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main ()
{
    char line[MAXLINE];
    int found = 0, pos;

    while (_getline(line, MAXLINE) > 0){
        if ((pos = strindex(line, pattern)) >= 0) {
            printf ("%s -- %d col", line, pos);
            found++;
        }
    }
    return found;
}

int _getline(char s[], int lim){
    int c, i;

    i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[]){
    int i, j, k;

    for (i = strlen(s) - strlen(t); i >= 0; i--){
        for (j = i, k = 0; t[k] != '\0' && t[k] == s[j]; j++, k++) ;
        if (t[k] == '\0')
            return i;
    }
    return -1;
}
