#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int n , q ; 
	scanf("%d%d",&n,&q);
	int i ; int arr[n] ; 
	for ( i = 0 ; i < n ; i++){
		scanf("%d",&arr[i]);
	}
	int k , l ;
	int L[n][n]; 
	int j ; 
	for ( i = 0 ; i < n ; i++){
		for ( j = 0 ; j < n ; j++){
			L[i][j] = 0 ;
		}
	}
	
	
	
	
	
	for (i = 0 ; i < q ; i++){
		scanf("%d%d",&k,&l) ; 
		 
		l -= 1 ;
		
		int j ; 
		for ( j = 0 ; j < n  ; j++){ 
			if (k < arr[j]){
				if (l == 0 ){
					printf ("%d\n",arr[j]);
					break ; 
				}
				else
					l -= 1 ; 
			}
			else
				continue ; 
		} 
	}
}

