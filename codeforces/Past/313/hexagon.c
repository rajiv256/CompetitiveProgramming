#include <stdio.h>
#include<stdlib.h>
#include<math.h>


		
int main ( ) {
	double a , b , h ; 
	int ar[6] ; 
	int i ; 
	int area  ; 
	for ( i = 0 ; i < 6 ; i ++ ) {
		scanf("%d",&ar[i]) ; 
	}
	area = (ar[0]+ar[1]+ar[5])*(ar[0]+ar[1]+ar[5]) - ar[5]*ar[5] - ar[1]*ar[1] - ar[3]*ar[3] ; 
	printf("%d\n",area) ; 
	return 0  ;
}
	
	
	
	

		
