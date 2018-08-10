#include<stdio.h>
#include<stdlib.h>

int main() {
	int n , m ; 
	scanf("%d%d",&n,&m) ; 
	char* s = (char*)malloc(sizeof(char)*n) ;
	
	scanf("%s",s) ;
	
	int i ; 
	int flag[n] ; 
	for ( i = 0 ; i < n ; i++){
		flag[i] = 0 ; 
	}
	int count = 0 ; 
	for ( i = 0 ; i < n ; i++){
		if (s[i]-97 < m )
			count++ ;
	}
	
	if (count < n-1){
		printf("0\n");
		return 0 ; 
	}
	if (count == n-1){
		
	}
	if (count > n-1){
		
	}
	 
}
