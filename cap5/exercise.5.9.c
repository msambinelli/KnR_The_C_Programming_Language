/*
 * Created: 2011-01-16T16:40:11
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 5-9: Rewrite the routines day_of_year and month_day with pointers
 * instead of indexing */
 
#include <stdio.h>
#include <string.h>

static char *month_names[] = {
    "Illegal month", "Jan", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago",
    "Set", "Out", "Nov", "Dec"
};

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* ismonth: return 1 if parameter is one month, 0 otherwise */
int ismonth(char *month)
{
    int i;
    for (i = 1; i < 13; i++)
	if (!strcmp(month, month_names[i]))
	    return 1;
    return 0;
}

int month_idx(char *month)
{
    int i;
    for (i = 1; i < 13; i++)
	if (!strcmp(month, month_names[i]))
	    return i;
    return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, char *month, int day)
{
    int i, leap, idxmonth;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (year < 0 || !ismonth(month) || day <= 0 ||  day > daytab[leap][(idxmonth = month_idx(month))])
	return -1;
    
    for (i = 1; i < idxmonth; ++i) {
	day += daytab[leap][i];
    }
    return day;
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, char **pmonth, int *pday)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (year < 0 || yearday <= 0 || yearday > (leap ? 366 : 365))
	return -1;
    
    for (i = 1; yearday > daytab[leap][i]; ++i) {
	yearday -= daytab[leap][i];
    }
    *pmonth = month_names[i];
    *pday = yearday;
    return 1;
}

int main(int argc, char *argv[])
{
    int month,  pday, error;
    char *smonth;
    printf ("day of year %d\n", error = day_of_year(2011, "MaR", 28));
    if (error < 0)
	printf ("error: invalid parameter\n");
    error = month_day(2012, 365, &smonth, &pday);
    printf ("month: %s day %d\n", smonth, pday);
    if (error < 0)
	printf ("error: invalid parameter\n");
    return 0;
}
