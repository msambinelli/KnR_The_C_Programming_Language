/*
 * Created: Ter 28 Dez 2010 13:38:45 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
#include <stdio.h>

#define MAXLINE 1000

int _getline(char line[], int maxline);
void putline(char line[]);

main ()
{
    int len;
    char line[MAXLINE];
    while ((len = _getline(line, MAXLINE)) > 0){
        if (len > 80)
            _putline(line); 
    }
    return 0;
}

int _getline(char line[], int maxlen){
    int i; 

    for (i = 0; i < maxlen - 1 && (line[i] = getchar()) != EOF && line[i] != '\n'; i++) ;      

    if (line[i] == '\n')
        i++;       

    line[i] = '\0';

    return i;
}

int _putline(char line[]){
    int i;

    for (i = 0; line[i] != '\0'; i++) 
        putchar(line[i]);
}
