/*
 * Created: 2011-01-21T18:50:23
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercise 6-4: write a program that prints the distinct words in its input
 * sorted into decreasing order of frequenci of occurrence. Precede each
 * word by its count */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 500

struct tnode {
    int count;
    char *word;
    struct tnode *left, *right;
};

#define WORD 'a'
#define MAXWORD 10000

void ungetch(int c);
int getch(void);

int getword(char *word, int limits)
{
    char *w = word;
    int c;

    while (isspace(c = getch())) ;

    if (!isalpha(c) && c != '_')
	return c;

    for (*w = c; (isalnum(*w) || *w == '_' || *w == '-') && w < word + MAXWORD - 1; *++w = c = getch()) ;

    ungetch(c);
    *w  = '\0';
    return WORD;
}

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {
	p = (struct tnode *) malloc(sizeof(struct tnode));
	p->word =  strdup(w);
	p->count = 1;
	p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
	p->count++;
    } else if (cond < 0) {
	p->left = addtree(p->left, w);
    } else {
	p->right = addtree(p->right, w);
    }
    return p;
}

void tree_print(struct tnode *v[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
	printf ("%4d: %s\n", v[i]->count, v[i]->word);
    }
}

void do_tree2vetor(struct tnode *t, struct tnode *v[], int *index)
{
    if (t != NULL) {
	v[(*index)++] = t;
	do_tree2vetor(t->left, v, index);
	do_tree2vetor(t->right, v, index);
    }
}

int tree2vetor(struct tnode *t, struct tnode *v[])
{
    int index = 0;
    do_tree2vetor(t, v, &index);
    return index;
}

int compare(const void *a, const void *b)
{
    return (* (struct tnode **) b)->count - (* (struct tnode **) a)->count;
}

#define MAXWORDS 10000

int main(int argc, char *argv[])
{
    struct tnode *root = NULL;
    struct tnode *vetor[MAXWORDS];
    int nelement = 0;

    char word[MAXWORD];
    int c;

    while ((c = getword(word, MAXWORD)) != EOF) {
	if (c == WORD)
	    root = addtree(root, word);
    }

    nelement = tree2vetor(root, vetor);
    qsort(vetor, nelement, sizeof(struct tnode *), compare);

    tree_print(vetor, nelement);

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



