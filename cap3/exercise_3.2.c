/*
 * Created: Dom 02 Jan 2011 17:10:25 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
/* Exercise 3-2: Write a function escape(s, t) that converts characters like
   newline and tab into visible escape sequences like \n and \t as it copies
   the string t to s. Use a switch. Write a function for the other direction
   as well, converting escape sequences into the real characters. */

#include <stdio.h>

void escape(char s[], char t[]){
    int i, j;
    for (i = 0, j = 0; t[i] != '\0'; i++){
        switch (t[i]){
            default:
                s[j] = t[i];
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\%':
                s [j++] = '\\';
                s [j] = '\%';
                break;
            case '\\':
                s[j++] = '\\';
                s [j] = '\\';
                break;
        }
        j++;
    }
    s[j] = '\0';
}

void rev_escape(char s[], char t[]){
    int i, j;
    char esc = 0;

    for (i = 0, j = 0; t[i] != '\0'; i++){
        switch(t[i]){
            case '\\':       
                if (!esc){
                    esc = 1;
                    j--;
                } else {
                    esc = 0;
                    s[j] = '\\';
                }
                break;
            case 't':
                s[j] = (esc)? '\t': 't';
                esc = 0;
                break;
            case 'n':
                s[j] = (esc)? '\n': 'n';
                esc = 0;
                break;
            case '\%':
                s[j] = (esc)? '\%': 0;
                esc = 0;
                break;
            default:
                s[j] = t[i];
        }
        j++;
    }
    s[j] = '\0';
}


int main ()
{
    char t[255], u[255];
    escape(t, "\\ -- \% maycon\t\tsambinelli\nCientista \\ da Computacao\t\tformado\t\t2010");
    printf("%s\n", t);
    rev_escape(u, t);
    printf("%s\n", u); 
    return 0;
}
