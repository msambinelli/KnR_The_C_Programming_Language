/*
 * Created: Seg 27 Dez 2010 20:30:54 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
in its input. */

#include <stdio.h>

#define OTHER 26

main ()
{
    int freq[27], c, i, j;
    
    for (i = 0; i < 27; i++) freq[i] = 0;

    while ((c = getchar()) != EOF){
        if (c >= 'A' && c <= 'Z')
            c = c + 32;

        if (c >= 'a' && c <= 'z')
            freq[c - 'a']++;
        else 
            freq[OTHER]++;
    }

    for (i = 0; i < 26; i++){
        printf ("%c: ", i + 'a');
        for (j = 0; j < freq[i]; j++)
            putchar('.');
        printf ("%d\n", freq[i]);
    }

    printf ("other: ");
    for (j = 0; j < freq[OTHER]; j++)
        putchar('.');
    printf ("%d\n", freq[OTHER]);
}

