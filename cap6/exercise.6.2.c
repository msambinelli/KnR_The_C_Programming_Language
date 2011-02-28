/*
 * Created: 2011-01-20T17:45:32
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Write a program that reads a C program and prints in alphabetical
 * order each group of variables names that are identical in the first 6
 * characters, but different somewhere thereafter. Don't count words within
 * string and comments. Make 6 a parameter that can be set from the command line */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct tnode {
    struct tlist *list;
    char *key;
    struct tnode *left;
    struct tnode *right;
};

struct tlist {
    struct tlist *next;
    char *word;
};

enum { NAME, CSTRING };

/* string */

char *_strdup(char *s) /* make a duplicate of s */
{
    char *p;
    p = (char *) malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)
	strcpy(p, s);
    return p;
}

/* list */

struct tlist *linsert(struct tlist *list, char *word)
{
    struct tlist *newlist = (struct tlist*) malloc (sizeof(*list));
    newlist->next = list;
    newlist->word = strdup(word);
    return newlist;
}

int lcontains(struct tlist *list, char *w)
{
    for ( ; list != NULL; list = list->next)
	if (!strcmp(list->word, w))
	    return 1;
    return 0;
}

/* tree */

struct tnode *addtree(struct tnode *p, char *w, int n)
{
    int cond;
    if (p == NULL) {
	p = (struct tnode*)  malloc(sizeof(struct tnode));
	p->list = linsert(NULL, w);
	p->key = (char *) malloc (n + 1);
	strncpy(p->key, w, n);
	p->left = p->right = NULL;
    } else if ((cond = strncmp(w, p->key, n)) == 0) {
	if (!lcontains(p->list, w))
	    p->list = linsert(p->list, w);
    } else {
	if (cond < 0)
	    p->left = addtree(p->left, w, n);
	else
	    p->right = addtree(p->right, w, n);
    }
    return p;
}

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
    char *w = word, scaped = 0;
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
	return NAME;
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
    return CSTRING;
}


void display_tree(struct tnode *t)
{
    struct tlist *i;
    if (t != NULL) {
	display_tree(t->left);
	printf ("Group %s\n", t->key);
	printf ("-------------------\n");
	for (i = t->list; i != NULL; i = i->next) {
	    printf ("%s ", i->word);
	}
	printf ("\n\n");
	display_tree(t->right);
    }
}



#define MAXWORD 1000

int main(int argc, char *argv[])
{
    struct tnode *root = NULL;
    char word[MAXWORD];
    int c, n = 6;

    if (argc > 1 && (*++argv)[0] == '-')
	n = atoi(++*argv);

    while ((c= getword(word, MAXWORD)) != EOF) {
	if (c == NAME){
	    root = addtree(root, word, n);
	}
    }
    display_tree(root);
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

