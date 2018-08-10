#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main () {
	int n , i ; 
	scanf("%d",&n) ;
	int* ar = (int*)malloc(sizeof(int)*n) ;
	//char*s = (char*)malloc(sizeof(char)); 
	for (i = 0 ; i < n ; i++){
		scanf("%d",&ar[i]) ; 
	}
	int beauty = 1 ; 
	int babe = ar[0] ;
	for ( i = 1 ; i < n ; i++ ) {
		if ( beauty == 0 ) {
			if (ar[i] == babe){
				beauty += 1 ; 
			}
			else {
				beauty = 1 ; 
				babe = ar[i] ; 
			}
		}
		if ( ar[i] == babe ){
			beauty += 1 ;
			continue ; 
		}
		if (ar[i] != babe && beauty >= 1 ){
			beauty -= 1 ; 
			continue ;
		}
		
	}
	int j ; 
	for ( i = 0 ; i < n ; i++) {
		if (ar[i] == babe) 
			break ; 
	}
	for ( j = n-1 ; j >= 0 ; j--) {
		if (ar[j] == babe) 
			break ; 
	}
	printf("%d %d\n",i+1 , j+1 ) ;
}
