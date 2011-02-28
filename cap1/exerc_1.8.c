/*
 * Created: Seg 27 Dez 2010 15:15:46 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */

/* Exercise 1-8: Write a program to count blanks, tabs, and newlines; */
 
#include <stdio.h>

main ()
{
    int c;
    int nblanks, ntabs, nl;
    
    nblanks = ntabs = nl = 0;

    while ((c = getchar()) != EOF){
        if (c == ' ')
            nblanks++;
        else if (c == '\n') 
            nl++;
        else if (c == '\t')
            ntabs++;
    }

    printf("\nNumber of Blanks: %d\n", nblanks);
    printf("Number of Tabs: %d\n", ntabs);
    printf("Number of New Lines: %d\n\n", nl);
    return 0;
}
