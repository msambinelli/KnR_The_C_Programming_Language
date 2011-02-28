/*
 * Created: Seg 03 Jan 2011 21:40:11 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 4-2: Extend atof to handle scientific notation of the form:
 *
 *  123.45e-6
 *
 *  Where a floating-point number may be followed by e or E and an optionally
 *  signed exponent
 */

#include <stdio.h>
#include <ctype.h>

double atof(char s[]){
    int i, sign, valexp;
    double val, power, exp;

    for (i = 0; isspace(s[i]); i++) ;       
    sign = (s[i] == '-')? -1: 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = val * 10 + (s[i] - '0');

    if (s[i] == '.'){
        i++;
        for (power = 1.0; isdigit(s[i]); i++){
            val = val * 10 + (s[i] - '0');
            power *= 10;
        }
        val = val / power;
    }

    if (s[i] == 'e' || s[i] == 'E'){
        i++;
        exp = (s[i] == '-')? 1.0 / 10 : 10;
        if (s[i] == '-' || s[i] == '+')
            i++;
        for (valexp = 0; isdigit(s[i]); i++)
            valexp = 10 * valexp + (s[i] - '0');
        for (i = 0; i < valexp; i++)
            val *= exp;
    }

    return val;
}

int main ()
{
    printf("%g\n", atof(".534E3"));
    return 0;
}
