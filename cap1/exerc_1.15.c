/*
 * Created: Seg 27 Dez 2010 21:28:45 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
#include <stdio.h>

float fahr2cels(float fahr){
    return (5.0 / 9.0) * (fahr - 32.0);      
}

main ()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper){
        printf("%3.0f %6.1f\n", fahr, fahr2cels(fahr));       
        fahr = fahr + step;
    }
}
