/*
 * Created: Seg 03 Jan 2011 00:08:53 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */

/* Exercise 3-3: Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into
 * the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to
 * handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally
 */
 
#include <stdio.h>

#define MAXLEN  1000

void expand(char s1[], char s2[]){
    int i, j, prev, k;

    for (i = 0, j = 0, prev = -1; s1[i] != '\0'; i++){
        if (s1[i] == '-'){
            if (prev == -1 || s1[i + 1] == '\0')
                s2[j++] = s1[i];
            else {
                for (k = prev + 1; k <= s1[i + 1]; k++)    
                    s2[j++] = k; 
                prev = s1[i + 1];
                i++;
            }
        } else {
            prev = s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}

int main (int argc, char const* argv[])
{
    char out[MAXLEN]; 
    
    expand("0-9abc-zA-F-M-Z-", out);
    printf("%s\n", out);
    return 0;
}
