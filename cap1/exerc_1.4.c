/*
 * Created: Seg 27 Dez 2010 14:48:54 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 1-4: Write a program to print the corresponding Celsius to 
 * Fahrenheit table */

#include <stdio.h>

main ()
{
    float fahr, celsius;
    int step, lower, upper;   

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    while (celsius <= 300){
        fahr =  9.0 / 5.0 * celsius + 32;
        printf ("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + 20;
    }
}
