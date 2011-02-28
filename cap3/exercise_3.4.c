/*
 * Created: Seg 03 Jan 2011 13:50:40 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 3-4: In a two's complement nuumber representation, our version of itoa does not handle the largest
 * negative number, that is, the  value  of n equal to -(2^(wordsize-1)). Expain why not. Modify it to print that 
 * value correctly, regardless of the machine on wich it runs. */

/*
 
Digamos que a máquina em questão tenha o tamanho de palavra igual a 3. Desta forma podemos representar os seguintes
numeros positivos:

321 | valor decimal
----+--------------
000 |   0
001 |   1
010 |   2
011 |   3
----+--------------

A representação desses valores em complemento de dois é:

321 | valor decimal
----+--------------
000 |   - 0
111 |   - 1
110 |   - 2
101 |   - 3
100 |   - 4
----+--------------

Desta forma, o intervalo representado é: [-4, 3]. Assim, não podemos representar o menor número negativo na sua forma
absoluta.

*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]){
    int i, j, aux;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]){
    int i, sign;       

    sign = n;
    i = 0;

    do {
        s[i++] = (n % 10 < 0)? -(n % 10) + '0': n % 10 + '0';     
    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main ()
{
    char s[100];
    itoa(INT_MIN, s); 

    printf("%s %d\n", s, INT_MIN);
    return 0;
}
