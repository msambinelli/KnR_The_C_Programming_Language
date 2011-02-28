/*
 * Created: Qua 29 Dez 2010 18:34:33 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 2-3: Write a function htoi(s), which converts a string of
hexadecimal digits (including an optional 0x or 0X) into its equivalent
interger value. The allowable digits are 0 through 9, a through f,
and A through F. */

#include <stdio.h>

int htoi(char s[]) {
	int i, val, dec;
	
	if (s[1] == 'x' || s[1] == 'X')
		i = 2;
	else
		i = 0;
	
	val = 0;
	for ( ; s[i] != '\0'; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			dec = s[i] - '0';
		else if (s[i] >= 'A' && s[i] <= 'Z')
			dec = s[i] - 'A' + 10;
		else
			dec = s[i] - 'a' + 10;
		val = val * 16 + dec;	
	}

    return val;
}

int main ()
{
	printf ("%d\n", htoi("aF"));
	return 0;
}
