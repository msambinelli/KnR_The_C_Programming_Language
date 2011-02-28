/*
 * Created: 2011-01-16T15:45:06
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 5.8: There is no error checking in day_of_year or month_day. Temedy this defect */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (year < 0 || month <= 0 || day <= 0 || month > 12 || day > daytab[leap][month])
	return -1;
    
    for (i = 1; i < month; ++i) {
	day += daytab[leap][i];
    }
    return day;
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (year < 0 || yearday <= 0 || yearday > (leap ? 366 : 365))
	return -1;
    
    for (i = 1; yearday > daytab[leap][i]; ++i) {
	yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
    return 0;
}

int main(int argc, char *argv[])
{
    int month,  pday, error;
    printf ("day of year %d\n", error = day_of_year(2011, 2, 29));
    if (error < 0)
	printf ("error: invalid parameter\n");
    return 0;
}


   
