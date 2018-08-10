#include<stdio.h>
#include<stdlib.h>

int main ( ) {
	int t , n , k ,i ,remaining, packages ,add ; 	
	scanf("%d",&t) ; 
	while (t -- ) {
		scanf( "%d",&n) ; 
		scanf( "%d",&k) ; 
		int arr[3] ; 
		for (i = 0  ; i < n ; i ++ ) {
			scanf("%d",&arr[i] ) ; 
		}
		
		remaining =  0 ; 
		packages = 0 ; 
		for ( i = 0 ; i < n ; i++ ) {
			if ( remaining >= arr[i] ) {
				remaining -= arr[i] ; 
				continue ; 
			}
			else { 
				float temp = (arr[i] - remaining)/k ; 
				if (temp == (int)temp) 
					add = (int) temp ; 
				else
					add  = (int) temp + 1 ; 
				packages += add  ; 
				remaining = remaining + k*add - arr[i] ; 
			}
			remaining -- ; 
		}
			
		printf ("%d\n", packages ) ;  
	}
	return 0 ; 
} 
