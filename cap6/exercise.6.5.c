/*
 * Created: 2011-01-21T20:15:00
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 */

/* Exercises 6-5: Write a function undef that will remove a name and definition
 * from the table maintained by lookup and install */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name;
    char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for strings s */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
	hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
	if (strcmp(s, np->name) == 0)
	    return np; /* found */
    return NULL; /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) { /* not found */
	np = (struct nlist*) malloc(sizeof(*np));
	if (np == NULL || (np->name = strdup(name)) == NULL)
	    return NULL;
	hashval = hash(name);
	np->next = hashtab[hashval];
	hashtab[hashval] = np;
    } else /* already there */
	free ((void *) np->defn); /* free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
	return NULL;
    return np;
}

void undef(char *s)
{
    struct nlist **prev, *np;
    int hashval = hash(s);

    for (prev = &hashtab[hashval], np = hashtab[hashval];
	 np != NULL && strcmp(s, np->name); prev = &np->next, np = np->next) ;

    if (np == NULL)
	return;
    *prev = np->next;
    free(np);
}

void display_entry(int index)
{
    struct nlist *np;
    for (np = hashtab[index]; np != NULL; np = np->next)
	printf ("[%2d]\tname (%s) -- defn (%s)\n", index, np->name, np->defn);
}

int main(int argc, char *argv[])
{
    int i;

    install("MAX_SIZE", "100");
    install("MIN_SIZE", "0");
    install("COUNT", "5");
    install("HASHSIZE", "101");
    undef("COUNT");
    install("HASHSIZE", "45");


    for (i = 0; i < HASHSIZE; ++i)
	display_entry(i);

    return 0;
}
