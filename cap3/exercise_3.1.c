/*
 * Created: Qui 30 Dez 2010 14:18:01 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 3-1: Our binary search makes two test inside the loop, when one
would suffice (at the price of more tests outside.) Write a version with
only one test inside the loop and measure the difference in run-time. */

/* time:
 *
 * function         |   not optimized   | -O2 optimized |
 * -----------------------------------------------------
 * bisearch_1test   |       0.24s       |   0.09s       |
 * bisearch_2test   |       0.24s       |   0.1s        |
 * ------------------------------------------------------
 */

#include <stdio.h>

#define VETSIZE     1000000

int binsearch_2test(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high){
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1; /* no match */
}

int binsearch_1test(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high){
        mid = (low + high) / 2;       
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return (low == high)? low: -1;
}


int main ()
{
    int v[VETSIZE];
    int i;

    for (i = 0; i < VETSIZE; i++)
        v[i] = i;
    for (i = 0; i < VETSIZE; i++){
        printf ("search %d -- Found: %d\n", i, binsearch_1test(i, v, VETSIZE));       
    }
    return 0;
}
