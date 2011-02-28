/*
 * Created: Seg 03 Jan 2011 15:05:50 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 3-5: Write the function itob(n, s, b) that converts the integer n into a base b character representation
 * in the string s. In particular, itob(n, s, 16) formats s as a hexadecimal
 * integer in s. */

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

char num2char(int n){
    switch(n){
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            return n - 10 + 'A';
        default:
            return n + '0';
    }
}

void itob(int n, char s[], int b){
    int i, sign;

    sign = n;

    i = 0;
    do {
        s[i++] = num2char((n % b < 0)? -(n % b): n % b);
    } while ((n /= b) != 0);

    if (b == 16){
        s[i++] = 'x';
        s[i++] = '0';
    }

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main (int argc, char const* argv[])
{
    char s[50];
    itob(255, s, 4); 
    printf("%s\n", s);
    return 0;
}
