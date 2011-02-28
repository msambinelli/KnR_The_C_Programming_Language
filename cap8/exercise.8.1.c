/*
 * Created: Dom 20 Fev 2011 12:31:50 BRT
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 8-1: Rewrite the program cat from Chapter 7 using read, write, open, and
 * close instead of their standard library equivalents. Perform experments to determine
 * the relative speeds of the two versions */

/* result:
 * version using stdlib: 7s
 * version using unix interface: 7s
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void filecopy(int dest, int orig) {
    char buff[BUFSIZ];
    int n;

    while ((n = read(orig, buff, BUFSIZ)) > 0) 
        write (dest, buff, n);
}

int main (int argc, char const* argv[])
{
    int fd;

    if (argc == 1) {
        filecopy(1, 0);
    } else {
        while (--argc > 0) {
            if ((fd = open(*++argv, O_RDONLY, 0)) == -1)        
                exit (1);
            filecopy(1, fd);
            close(fd);
        }
    }
    exit(0);
}
