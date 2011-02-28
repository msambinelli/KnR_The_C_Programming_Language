/*
 * Created: Qua 05 Jan 2011 16:09:36 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */


/* Exercise 4-8: Suppose that thre will never  be more than on character of
 * pushback. Modify getch and ungetch accordingly. */


#define EMPTY   -2
 
int buf = EMPTY;

int getch(void){
    int c;
    c = (buf != EMPTY)?  buf : getchar();       
    buf = EMPTY;
    return c;
}

void ungetch(int c){
    buf = c;       
}

