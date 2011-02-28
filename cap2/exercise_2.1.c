/*
 * Created: Qua 29 Dez 2010 15:31:55 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 2-1: Write a program to determine the gantes of char, short,
int, and long variables, both signed and unsigned, by printing appropriate
values from standard headers and by direct computation. Harder if you
compute them: determine the ganges of the various floating-point types */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main ()
{
	printf ("signed char\tmin: %hhd\tmax: %hhd\n", SCHAR_MIN, SCHAR_MAX);
	printf ("unsigned char\tmin: %hhd\tmax: %hhu\n", 0, UCHAR_MAX);
	printf ("char\tmin: %hhd\tmax: %hhd\n", CHAR_MIN, CHAR_MAX);

	printf ("signed short\tmin: %hd\tmax: %hd\n", SHRT_MIN, SHRT_MAX);
	printf ("unsigned short\tmin: %hu\tmax: %hu\n", 0, USHRT_MAX);
	
	printf ("signed int\tmin: %d\tmax: %d\n", INT_MIN, INT_MAX);
	printf ("unsigned int\tmin: %u\tmax: %u\n", 0, UINT_MAX);

	printf ("signed long\tmin: %ld\tmax: %ld\n", LONG_MIN, LONG_MAX);
	printf ("unsigned long\tmin: %lu\tmax: %lu\n", 0ul, ULONG_MAX);

	printf("\n");

	printf ("float \tmin: %e\tmax: %e\n", FLT_MIN, FLT_MAX);
	printf ("double\tmin: %e\tmax: %e\n", DBL_MIN, DBL_MAX);
	printf ("long double\tmin: %Le\tmax: %Le\n", LDBL_MIN, LDBL_MAX);

	return 0;
}
