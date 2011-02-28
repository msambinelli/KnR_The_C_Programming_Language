/*
 * Created: Qua 05 Jan 2011 15:42:53 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */

#include <stdio.h>
#include <string.h>

int getch(void);

void _gets(char s[]) {
    int i = 0, c;
    while ((s[i++] = c = getch()) != '\n' && c != EOF) ;
    s[i] = '\0';
}
 
#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next gree position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();       
}

void ungetch(int c) /* get character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void un_gets(char s[]){
    int i;
    if (BUFSIZE - bufp < strlen(s)) {
        printf("un_gets: too many characters\n");       
    } else{
        for (i = strlen(s) - 1; i >= 0 && bufp < BUFSIZE; i--){
            buf[bufp++] = s[i];       
        }
    }
}

int main (int argc, char const* argv[])
{
    char s[255]; 

    _gets(s);
    printf("%s", s);
    un_gets(s);
    _gets(s);
    printf("%s", s);
    _gets(s);
    printf("%s", s);
    un_gets(s);
    _gets(s);
    printf("%s", s);

    return 0;
}
