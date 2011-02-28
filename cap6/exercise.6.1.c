/*
 * Created: 2011-01-19T16:38:24
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 6-1: Our version of getword does not properly handle underscores,
 * string constants, comments, or preprocessor control lines. Write a better
 * version */

#include <stdio.h>
#include <ctype.h>

void ungetch(int c);
int getch(void);

void del_space(void)
{
    char state = 0;
    int c;

    while (state != 2) {
	c = getch();
	switch(state) {
	case 0:
	    if (c == '/')
		state = 1;
	    else if (!isspace(c)) {
		state = 2;
		ungetch(c);
	    }
	    break;
	case 1:
	    if (c == '*')
		state = 3;
	    else {
		ungetch(c);
		ungetch('/');
		state = 2;
	    }
	    break;
	case 3:
	    if (c == '*')
		state = 4;
	    break;
	case 4:
	    if (c == '*' || c == '/') {
		if (c == '/')
		    state = 0;
	    } else
		state = 3;
	    break;
	}
    }
}

int getword(char *word, int limits)
{
    char *w = word, scaped;
    int c;

    del_space();

    c = *w++ = getch();

    if (!isalpha(c) && c != '_' && c != '#' && c != '"') {
	*w = '\0';
	return c;
    }

    if (c != '"') {
	for ( ; w < word + limits && (isalnum(*w = c = getch()) || c == '_'); w++) ;
	*w = '\0';
	ungetch(c);
	return word[0];
    }

    w--;
    while (w < word + limits - 1) {
	if ((*w++ = c = getch()) == '"' && !scaped)
	    break;
	scaped = 0;
	if (c == '\\') {
	    scaped = 1;
	    w--;
	}
    }

    *--w = '\0';
    return word[0];
}

int main(int argc, char *argv[])
{
    char word[100];

    while (getword(word, 100) != EOF)
	printf ("%s\n", word);
    return 0;
}


#define BUFSIZE 100

int buffer[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp < BUFSIZE)
	buffer[bufp++] = c;
    else
	printf ("error: buffer is full\n");
}
