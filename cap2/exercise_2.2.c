/*
 * Created: Qua 29 Dez 2010 17:28:44 BRST
 *
 * Author: Maycon Sambinelli, msambinelli@gmail.com
 *
 */
 
int stopcondition = 0;

while (!stopcondition){
	if (i < lim - 1){
		c = getchar();
		if (c != '\n'){
			if (c != EOF){
				...		
			} else 
				stopcondition = 1;		
		} else 
			stopcondition = 1;		
	} else
		stopcondition = 1;		
}
