#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int min(int a , int b ) {
	if (a  > b ) {
		return b ; 
	}
	return a ; 
}

int goBack (int mult , int n  ) {
	int count = 0 ; 
 	double root  = pow((double)mult,1/n) ; 	
	while (root != (int)root) {
		mult = mult >> 1 ; 
		count ++ ; 
		root = pow((double)mult , 1/n) ; 
	}
	return count  ; 
}

int goFwd (int mult , int n  ) {
	int count = 0 ; 
 	double root  = pow((double)mult,1/n) ; 	
	while (root != (int)root) {
		mult = mult << 1 ; 
		count ++ ; 
		root = pow((double)mult , 1/n) ; 
	}
	return count  ; 
}





int main () {
	int n , i , j ; 
	scanf("%d",&n) ;
	int ar[n] ; 
	for ( i = 0 ; i < n ; i++ ) {	
		scanf("%d",&ar[i]) ;
	}
	
	int mult = 1 ; 
	for (i = 0 ; i < n ; i++){
		mult *= ar[i] ; 
	}
	double root  = exp((double)1/3 * log((double)mult)) ;
	
	printf("%lf\n", root - (int)root) ;
}
