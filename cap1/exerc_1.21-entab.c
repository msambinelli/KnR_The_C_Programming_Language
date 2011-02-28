/*
 * Created: Ter 28 Dez 2010 16:49:52 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */

#include <stdio.h>

#define MAXLINE 1000
#define TAB		4	
 
int _getline(char line[], int limits);
int tab(char line[], int i, int j);

int main ()
{	
	char line[MAXLINE];
	int i, j;

	while (_getline(line, MAXLINE) > 0){

		for (i = 0; line[i] != '\0'; i++){
			if (line[i] != ' ')
				putchar(line[i]);
			else {
				j = i + 1;
				while (line[j] == ' ') j++;
				i = tab(line, i, j);
				while (i < j){
					putchar(line[i]);
					i++;
				}
				i--;
			}
		}

	}
	return 0;
}

int tab (char line[], int i, int j){
	int cur = i;
	i++;
	while (i <= j){
		if (i % TAB == 0){
			cur = i;
			putchar('\t');
		}
		i++;
	}
	return cur;
}

int _getline(char line[], int limits){
	int i;
	for (i = 0; i < limits - 1 && (line[i] = getchar()) != EOF && line[i] != '\n'; i++) ;
	if (line[i] == '\n')
		i++;
	line[i] = '\0';
	return i;
}
