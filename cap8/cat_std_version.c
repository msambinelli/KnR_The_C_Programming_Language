/*
 * Created: Dom 20 Fev 2011 12:41:29 BRT
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
#include <stdio.h>
#include <stdlib.h>

#define BUFZ 1000
void filecopy(FILE *dest, FILE *origin) {
    char buff[BUFZ];
    int c;

    while (fgets(buff, BUFZ, origin) != NULL)
        fputs(buff, dest);
}

/* cat: concatenate files, version 2 */
int main (int argc, char *argv[])
{
    FILE *fp;
    char *prog = argv[0];  

    if (argc == 1)
        filecopy(stdout, stdin);
    else
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf (stderr, "%s: can't open %s\n", prog, *argv);       
                exit(1);
            } else {
                filecopy(stdout, fp);      
                fclose(fp);
            }
        }

    if (ferror(stdout)) {
        fprintf (stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}
