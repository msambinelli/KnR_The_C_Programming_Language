/*
 * Created: Seg 03 Jan 2011 15:37:43 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 3-6: Write a version of itoa that accepts three arguments instead of
 * two. The third argument is a minimum field width; the converted number must
 * be padded with blanks on the left if necessary to make it wide enough */

#include <stdio.h>
#include <string.h>

void reverse(char s[]){
    int i, j, aux;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int f){
    int i, sign;       

    sign = n;
    i = 0;

    do {
        s[i++] = (n % 10 < 0)? -(n % 10) + '0': n % 10 + '0';     
    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';

    while (i < f)
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
}

int main ()
{
    char s[100];

    itoa(1000007, s, 18);
    printf("%s\n", s);

    return 0;
}
