/*
 * Created: Qua 05 Jan 2011 16:19:28 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 4-9: Our getch and ungetch do not handle a pushed-back EOF
 * correctly. Decide what their properties ought to be if an EOF is pushed
 * back, then implement your design */

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void){
    return (buf > 0) ? buf[--bufp] : getchar();       
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else 
        buf[bufp++] = c;
}
