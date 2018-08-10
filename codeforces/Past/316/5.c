#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checkPalin(char* s){
	int len = strlen(s) ;
	int i ; 
	for ( i =0 ; i < len/2 ; i++){
		if (s[i] != s[len-i-1]){
			return 0 ; 
		}
	} 
	return 1 ; 
}



int dfs(char** arr , int n , int m ,int i , int j, char* s , int size){
	
	printf("%d %d\n",i,j) ; 
	if (i+1 == n-1 && j == m-1){
		
		if (checkPalin(s)){
			s  = NULL ; 
			size = 0 ; 
			return 1 ;  
		}
		s = NULL ; 
		size = 0 ; 
		return 0 ;	
	}
	if (i == n-1 && j+1 == m-1){
		s[size] = arr[i][j+1] ; 
		if (checkPalin(s)){
			s  = NULL ;
			size = 0 ; 
			return 1 ; 
		}
		s  = NULL ;
		size = 0 ; 
		return 0 ;	
	}
	if ( i +1 > n-1 || j+1 > m-1){
		s = NULL ; 
		size = 0 ; 
		return 0 ; 
	}
	
	s[size] = arr[i+1][j] ; 
	int k = dfs (arr , n , m ,i+1,j,s,size+1) ; 
	s[size] = arr[i][j+1] ; 
	int l = dfs (arr , n , m , i , j+1 ,s ,size+1) ; 
	return k+l; 
	
	
	
	
}





int main () {
	
	int n , m ; 
	scanf("%d%d",&n,&m) ; 
	char** arr = (char**)malloc(sizeof(char*)*n) ; 
	int i , j; 
	for (i = 0 ; i < n ; i++){
		arr[i] = (char*)malloc(sizeof(char)*m) ;
	}
	
	for ( i = 0 ; i < n ; i++){
		for ( j = 0 ; j < m ; j++){
			scanf("%c",&arr[i][j]) ; 
		}
	}
	
	int count = 0 ; 
	char* s = (char*)malloc(sizeof(char)*(m+n+1)) ; 
	s = NULL ; 
	int size = 0 ; 
	count = dfs (arr, n , m ,0 ,0 ,s ,size ) ; 
	
	printf("%d\n", count) ; 
	
	
}
