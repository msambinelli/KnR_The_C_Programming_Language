/*
 * Created: Ter 28 Dez 2010 16:17:29 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
#include <stdio.h>

#define MAXLINE 1000
#define TAB	8

int tab(int pos);
int _getline(char line[], int limits);


int main ()
{	
    char line[MAXLINE];
    int pos, i;

	while (_getline(line, MAXLINE) > 0) {
        for (i = 0, pos= 0; line[i] != '\0'; i++, pos++){
            if (line[i] == '\t')
                pos = tab(pos);
            else
                putchar(line[i]);
        }
	}
}

int tab(int pos){
	for ( ; pos % TAB != 0; pos++)
		putchar(' ');
    return pos - 1;
}

int _getline(char line[], int limits){
	int i;

	for (i = 0; line[i] < limits - 1 && (line[i] = getchar()) != EOF && line[i] != '\n'; i++) ;		
	if (line[i] == '\n')
		i++;

	line[i] = '\0';
	return i;
}
