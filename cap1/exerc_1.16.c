/*
 * Created: Seg 27 Dez 2010 22:22:25 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the
length of arbitrary long input lines, and as much as possible of the text. */

#include <stdio.h>

//#define MAXLINE 1000
#define MAXLINE 4

int _getline (char line[], int maxline);
void copy(char to[], char from[]);

int main ()
{
    int len, maxlen;
    int sum;
    char line[MAXLINE], temp[MAXLINE];
    char longest[MAXLINE];

    maxlen = sum = 0;
    while ((len = _getline(line, MAXLINE)) > 0){
        if (line[len - 1] == '\n'){
            if (len + sum > maxlen){
                maxlen = len + sum;
                if (sum != 0){
                    copy(longest, temp);       
                } else {
                    copy(longest, line);       
                }
            }
            sum = 0;
        } else {
            if (sum == 0){
                copy(temp, line);       
                sum = len;
            } else {
                sum += len;       
            }
        }
    }

    if (maxlen > 0)
        printf ("%s -- size %d\n", longest, maxlen);

    return 0;
}

_getline(char s[], int lim){
    int c, i;

    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]){
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') i++;
}
