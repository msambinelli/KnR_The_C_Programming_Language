/*
 * Created: 2011-01-19T14:44:52
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};

int tokentype; /* type of last token */
char token[MAXTOKEN]; /* last token string */
char name[MAXTOKEN]; /* identifier namme */
char datatype[MAXTOKEN]; /* data type = char, int , etc. */
char out[1000];

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

int gettoken(void) /* return next token */
{
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t') ;

    if (c == '(') {
	if ((c = getch()) == ')') {
	    strcpy(token, "()");
	    return tokentype = PARENS;
	} else {
	    ungetch(c);
	    return tokentype = '(';
	}
    } else if (c == '[') {
	for (*p++ = c; (*p++ = getch()) != ']'; ) ;
	*p = '\0';
	return tokentype = BRACKETS;
    } else if (isalpha(c)) {
	for (*p++ = c; isalnum(c = getch()); )
	    *p++ = c;
	*p = '\0';
	ungetch(c);
	return tokentype = NAME;
    } else
	return tokentype = c;
}

void dirdcl(void);

/* dcl: parse a declarator */
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*'; ) /* count *'s */
	ns++;
    dirdcl();
    while (ns-- > 0)
	strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
    int type;

    if (tokentype == '(') {  /* (dcl) */
	dcl();
	if (tokentype != ')')
	    printf ("error: missing )\n");
    } else if (tokentype == NAME) {
	strcpy(name, token);
    } else {
	printf ("error: expected name or (dcl)\n");
    }

    while ((type = gettoken()) == PARENS || type == BRACKETS)
	if (type == PARENS)
	    strcat(out, " function returning");
	else {
	    strcat(out, " array");
	    strcat(out, token);
	    strcat(out, " of");
	}
}


int main(int argc, char *argv[])
{
    while (gettoken() != EOF) { /* 1st token on line */
	strcpy(datatype, token);  /* is the datatype */
	out[0] = '\0';
	dcl(); /* parse rest of line */
	if (tokentype != '\n')
	    printf ("syntax error\n");
	printf ("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}
