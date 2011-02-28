/*
 * Created: Qui 30 Dez 2010 12:01:42 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 2-10: Rewrite the function lower, which converts upper case letters
 * to lower case, with a conditional expresssion instead of if-else */

#include <stdio.h>

int lower(int c){
    return (c >= 'A' && c <= 'Z')? c + 'a' - 'A': c;      
}

int main ()
{
    printf("%c\n", lower('A'));
    printf("%c\n", lower('f'));
    printf("%c\n", lower('Z'));
    return 0;
}
