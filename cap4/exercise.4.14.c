/*
 * Created: 2011-01-07T00:02:47
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 4-14: Define a macro swap(t, x, y) that interchanges two arguments of type t.
 * (Block strucutre will help). */

#include <stdio.h>

#define swap(t, x, y) {t aux; aux = x; x = y; y = aux;}

int main(int argc, char *argv[])
{
    int a = 13, b = 15;
    swap(int, a, b);
    printf ("a: %d\tb: %d\n", a, b);
 
    return 0;
}
