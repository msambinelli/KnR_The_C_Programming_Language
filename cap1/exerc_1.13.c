/*
 * Created: Seg 27 Dez 2010 20:05:13 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
#include <stdio.h>

/* Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
 * easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
 */
main ()
{

    int freq[20], c, count, i, j;

    count = 0;

    for (i = 0; i < 20; i++) freq[i] = 0;

    while ((c = getchar()) != EOF) {
        if (count == 0) {
            if  (c != ' ' && c != '\t' && c != '\n') {
                count++;       
            }
        } else {
            count++;
            if (c == ' ' || c == '\t' || c == '\n') {
                if (count > 20)
                    freq[19]++;
                else 
                    freq[count - 2]++;
                count = 0;
            }
        }
    }

    for (i = 0; i < 19; i++){
        printf ("%02d: ", i + 1);       
        for (j = 0; j < freq[i]; j++)
            putchar('.');
        printf ("%d\n", freq[i]);
    }

    printf ("20 or more: ");
    for (j = 0; j < freq[19]; j++)
        putchar('.');
    printf ("%d\n", freq[19]);
    
}
