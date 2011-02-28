/*
 * Created: Ter 28 Dez 2010 15:51:08 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
#include <stdio.h>

#define MAXLINE 1000

void reverse(char line[], int len);
int _getline(char line[], int limits);
void swap(char line[], int i, int j);
void putline(char line[]);

int main ()
{			
	char line[MAXLINE];
	int len;

	while ((len = _getline(line, MAXLINE)) > 0){
		reverse(line, len);		
		putline(line);
	}
	return 0;
}

int _getline(char line[], int limits){
	int i;
	for (i = 0; i < limits -1 && (line[i] = getchar()) != EOF && line[i] != '\n'; i++) ;
	if (line[i] == '\n')
		i++;
	line[i] = '\0';
	return i;
}

void reverse(char line[], int len){
	int i, j;
	for (i = 0, j = len -1; i < j; i++, j--)
		swap(line, i, j);		
}

void swap(char line[], int i, int j){
	int aux;
	aux = line[i];
	line[i] = line[j];
	line[j] = aux;
}

void putline(char line[]){
	int i;
	for (i = 0; line[i] != '\0'; i++) 
		putchar(line[i]);		
}
