/*
 * Created: Seg 27 Dez 2010 15:01:28 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 1-5: Modify the temperature conversion program to print the table
 * in reverse order, that is, from 300 degrees to 0 */

#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 300, 280, ..., 0; floating-point version */

main(){

    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = upper;

    printf ("\nConversion Table - Fahrenheit to Celsius\n");
    printf ("-----------------------------------------\n\n");
    while (fahr >= lower) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf ("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr - step;
    }
}
