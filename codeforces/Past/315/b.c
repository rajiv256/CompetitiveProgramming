
#include<stdio.h>
#include<stdlib.h>


int main () {
	int n , i ;
	scanf("%d",&n);
	int a[n] ;
	int count[n] ; 
	for ( i = 0 ; i< n ; i++){
		scanf("%d",&a[i]);
		
	}
	for ( i = 0 ; i < n ; i++){
		a[i]-=1 ; 
		count[i] = 0 ; 
	}
	int j ; 
	for ( i = 0, j = 0 ; i < n && j < n ; ){
			if (count[a[i]] == 0 ){
				count[a[i]] += 1 ;
				i++ ; 	
				continue ; 
			}
			else if (count[a[i]] > 0 ){
				int k ; 
				for ( k = j ; k
				a[i] = j  ; 
				 
				i++ ; 
		
	}
	
	return 0 ;
}
