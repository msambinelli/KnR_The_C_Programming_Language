/*
 * Created: 2011-01-06T23:37:41
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 4-13: Write a recursive version of the function reverse (s), which reverses
 * the string s in place. */

#include <stdio.h>
#include <string.h>

void do_reverse(char s[], int left, int right){
    int aux;
    if (left < right){
	aux = s[left];
	s[left] = s[right];
	s[right] = aux;
	do_reverse (s, left + 1, right - 1);
    }
}

void reverse(char s[]){
    do_reverse(s, 0, strlen(s) - 1);
}

int main(int argc, char *argv[])
{
    char s[] = "Maycon Sambinelli";
    printf ("%s\n", s);
    reverse(s);
    printf ("%s\n", s);
    return 0;
}
