/*
 * Created: Qua 29 Dez 2010 19:07:32 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */

#include <stdio.h>

#define TRUE    1
#define FALSE   0
 
void squeeze(char s1[], char s2[]){
    int i, j, k;
    char finded;

    for (i = 0, k = 0; s1[i] != '\0'; i++){
        finded = FALSE;
        for (j = 0; s2[j] != '\0' && !finded; j++){
            if (s1[i] == s2[j]){
                finded = TRUE;
            }
        }
        if (!finded)
            s1[k++] = s1[i];       
    }
    s1[k] = '\0';
}

int main ()
{
    char s[] = "mtyayb";
    squeeze(s, "may");
    printf("%s\n", s);
    return 0;
}
