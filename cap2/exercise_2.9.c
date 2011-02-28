/*
 * Created: Qui 30 Dez 2010 11:47:26 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 2-9: In a two's complement number system, x &= (x - 1) deletes the 
 * rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcont.
 */


/* 
    + Suponha que n é um número com 6 bits
    + (x - 1) pode ser escrito como (x + (-1))
    + A representação de -1 com 6 bits em complemento de dois é: 111111
    + Quando fizermos x + (-1) o primeiro bit setado para 1 em x será setado para 0 pois:

(vai um)    1 <-  1
                + 1
                ----
                  0

    + Se o bit da esquerda for 0 o valor desse bit será mantido pois:
(vai um)    1 <-  1 <- (bit enviado pelo bit da direita)
                  0
                + 1
                ----
                  0

    + Se o bit da esquerda for 1 o valor desse bit será mantido pois:
(vai um)    1 <-  1 <- (bit enviado pelo bit da direita)
                  1
                + 1
                ----
                  1
    + e assim sucessivamente
    + Desta forma após zerar o primeiro bit setado para 1 os bits da esquerda desse bit serão copiados 
    para o resultado
    + Após isso é efetivada x & (x -1)

*/

#include <stdio.h>

int bitcount(unsigned x){
    int b;
    for (b = 0; x != 0; x&= x - 1)
        b++;
    return b;
}

int main ()
{
    printf("%d\n", bitcount(0x588f));
    return 0;
}
