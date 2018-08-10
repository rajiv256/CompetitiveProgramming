#include<stdio.h>
#include<stdlib.h>


int main () {
	int t , s , q , i ; 
	scanf("%d%d%d",&t,&s,&q) ; 
	int rewind = 0 , current = 0 ;
	float downloaded = (float)s , progress = 0 ;  
	
	while (downloaded < (float)t ) {
		
		if ( (float)current == downloaded ) {
			
			current = 0 ; 
			downloaded += (float)(q-1)/(q) ;  	
			rewind += 1 ; 
			continue ; 
		}
		else {
			current += 1 ; 
			downloaded +=  (float)(q-1) /(q) ; 
			continue;
		}
		
		
	}
	printf("%d\n",1+ rewind );
	return 0 ;  
}
