/*
 * Created: Qui 24 Fev 2011 18:48:07 BRT
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 8-3: Design and write _flushbuf, fflush, and fclose */

#include <stdlib.h>

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20     /* max #files open at once */

typedef struct _iobuf {
    int cnt;    /* characters left */
    char *ptr;  /* next character position */
    char *base; /* location of buffer */
    int flag;   /* mode of file acess */
    int fd;     /* file descriptor */
} FILE;

FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags {
    _READ = 01,     /* file open for reading */
    _WRITE = 02,    /* file open for writing */
    _UNBUF = 04,    /* ffile is unbuffered */
    _EOF = 010,     /* EOF has occurred on this file */
    _ERR = 020,     /* error occurred on this file */
};

int _flushbuf(int c, FILE *fp)
{
    int bufsize;

    if (fp == NULL)
        return EOF;

    if ((fp->flag & (_WRITE | _ERR)) != _WRITE) {
        return EOF;
    }
    
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

    if (fp->base == NULL) {
        if ((fp->base = malloc(bufsize)) == NULL)
            return EOF;
    } else {
        if (write(fp->fd, fp->base, bufsize) != bufsize) {
            fp->flag |= _ERR;
            return EOF;
        }
    }

    fp->ptr = fp->base;
    fp->cnt = bufsize - 1;
    return (*fp->ptr++ = c);
}

int fflush(FILE *fp)
{
    int bufsize, write_size;

    if (fp == NULL)
        return EOF;

    if ((fp->flag & (_WRITE | _ERR)) != _WRITE) 
        return EOF; 

    if (fp->base == NULL) 
        return 0;

    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    write_size = bufsize - fp->cnt;

    if (write(fp->fd, fp->base, write_size) != write_size) {
        fp->flag |= _ERR;
        return EOF;
    }

    fp->ptr = fp->base;
    fp->cnt = bufsize;

    return 0;
}

int fclose(FILE *fp)
{
    if (fp->flag & _WRITE) {
        if (fflush(fp) != 0)
            return EOF;
    }

    free(fp->base);
    close(fp->fd);
    return 0;
}

#define putc(x,p) ((--(p)->cnt >= 0) \ 
                            ? *(p)->ptr++ = (x) : _flushbuf((x), p))
