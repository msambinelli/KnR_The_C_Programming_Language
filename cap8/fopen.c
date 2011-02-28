/*
 * Created: Dom 20 Fev 2011 14:38:58 BRT
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
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

int _fillbuf(FILE *);
//int _flushbuf(int, FILE *);

#define feof(p)     (((p)->flag & _EOF) != 0)
#define ferror(p)   (((p)->flag & _ERR) != 0)
#define fileno(p)   ((p)->fd)

#define getc(p)     (--(p)->cnt >= 0 \
                    ? (unsigned char) *(p)->ptr++ : _fillbuf(p))

#define putchar(c)  (write(stdout, &(c), 1))

#include <fcntl.h>
#define PERM 0666

FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;

    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if ((fp->flag & (_READ | _WRITE)) == 0)
            break;      /* found free slot */
    if (fp >= _iob + OPEN_MAX)
        return NULL;

    if (*mode == 'w')
        fd = creat(name, PERM);
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0) == -1))       
            fd = creat(name, PERM);
        lseek(fd, 0L, 2);
    } else 
        fd = open(name, O_RDONLY, 0);

    if (fd == -1)
        return NULL;

    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}

#include <stdlib.h>

/* _fillbuf: allocate and fill input buffer */
int _fillbuf(FILE *fp)
{
    int bufsize;

    if ((fp->flag & (_READ | _EOF | _ERR)) != _READ)
        return EOF;

    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL) {
        if ((fp->base = (char*) malloc(bufsize)) == NULL)
            return EOF;     /* can't get buffer */
    }
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->flag |= _EOF;
        else
            fp->flag |= _ERR;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}

int main (int argc, char const* argv[])
{
    FILE *fp = fopen("/tmp/teste.txt", "r");
    
    while (feof(fp)) {
        int c = getc(fp);
        putchar(c); 
    }
    close(fp->fd);
    return 0;
}
