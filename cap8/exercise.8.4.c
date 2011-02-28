/*
 * Created: Qui 24 Fev 2011 20:08:00 BRT
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 8-4:  The standard library function
 *
 *      int fseek(FILE *fp, long offset, int origin)
 *
 * Is identical to lseek execpt that fp is a file pointer instead of a file 
 * descriptor and return value is an int status, not a position. Write fseek.
 * Make sure that your fseek coordinates properly with the buffering done for 
 * the other functions of the library \
 */

int fseek(FILE *stream, long offset, int origin)
{
    int status, mode;
    int c;

    if (stream == NULL)
        return 1;

    switch(origin){
    case SEEK_SET:
        mode = 0;
        break;
    case SEEK_CUR:
        mode = 1;
        break;
    case SEEK_END:
        mode = 2;
        break;
    default:
        return 1;
        break;
    }

    status = lseek(stream->fd; offset, mode);

    if (status == -1)
        return 1;

    if (stream->flag & _READ) {
        c = _fillbuf(stream);       
        ungetch(c, stream);
    } else { /* write */
        fflush(stream); 
    }

    return 0;
}
