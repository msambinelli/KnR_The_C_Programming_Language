/*
 * Created: Ter 28 Dez 2010 14:00:00 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
#include <stdio.h>

/* Exercise 1-18: Write a program to remove thrailing blanks and tabs from each line of input, and to delete
 * entirely blank lines */

#define MAXLINE 1000

int _getline(char line[], int maxline);

int main ()
{
    int state, i;
    char line[MAXLINE];

    state = 0;
    while (_getline(line, MAXLINE) > 0){

        if (line[0] == '\n'){
            printf("kill line\n");
            continue;
        }

        for (i = 0; line[i] != '\0'; i++){
            if (state == 0){
                if (line[i] == '\t' || line[i] == ' '){
                    state = 1;
                    if (line[i] == '\t')
                        printf("\\t");
                    else
                        printf("\\b");
                } else 
                    putchar(line[i]);
            } else {
                if (line[i] != '\t' && line[i] != ' '){
                    putchar(line[i]);
                    state = 0;
                }
            }
        }
    }
    return 0;
}

int _getline(char line[], int maxline){
    int i;
    for (i = 0; i < maxline - 1 && (line[i] = getchar()) != EOF && line[i] != '\n'; i++) ;
    if (line[i] == '\n')
        i++;
    line[i] = '\0';
    return i;
}
