/*
 * Created: 2011-01-21T17:41:02
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 6-3: Write a cross-reference that prints a list of all words in a document
 * and for each word, a list of the line numbers on which it occurs. Remove noise words
 * like "the", "and" ando so on. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 500

struct tnode {
    int nlines[MAXLINES];
    int nfree;
    char *word;
    struct tnode *left, *right;
};

char *black_list[] = {
    "the", "on", "in", "is", "he", "she", "it", "we", "us", "my", "a", "an"
};

#define WORD 'a'
#define MAXWORD 10000

void ungetch(int c);
int getch(void);

int line = 1;

int getword(char *word, int limits)
{
    char *w = word;
    int c;

    while (isspace(c = getch()))
	if (c == '\n')
	    line++;

    if (!isalpha(c) && c != '_')
	return c;

    for (*w = c; (isalnum(*w) || *w == '_' || *w == '-') && w < word + MAXWORD - 1; *++w = c = getch()) ;

    ungetch(c);
    *w  = '\0';
    return WORD;
}

int blacklist(char *w)
{
    int nelementos = sizeof black_list / sizeof (char *);
    int i;

    for (i = 0; i < nelementos; i++)
	if (!strcmp(w, black_list[i]))
	    return 1;
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w, int line)
{
    int cond;

    if (p == NULL) {
	p = (struct tnode *) malloc(sizeof(struct tnode));
	p->word =  strdup(w);
	p->nfree = 1;
	p->nlines[0] = line;
	p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
	if (p->nlines[p->nfree - 1] != line)
	    p->nlines[p->nfree++] = line;
    } else if (cond < 0) {
	p->left = addtree(p->left, w, line);
    } else {
	p->right = addtree(p->right, w, line);
    }
    return p;
}

void tree_print(struct tnode *p)
{
    int i;

    if (p != NULL) {
	tree_print(p->left);

	printf ("%s: ", p->word);
	for (i = 0; i < p->nfree; i++)
	    printf ("%d ", p->nlines[i]);
	printf("\n");

	tree_print(p->right);
    }
}


int main(int argc, char *argv[])
{
    struct tnode *root = NULL;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) {
	if (!blacklist(word))
	    root = addtree(root, word, line);
    }
    tree_print(root);
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

