#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int common (char *s1 , char *s2 , int n){
	int i ; int count = 0 ;
	for ( i = 0 ; i < n ; i++){
		if (s1[i] == s2[i]){
			count ++ ; 
		}
	}
	return count ; 
}

int main() {
	int t ; 
	scanf("%d",&t) ; 
	while (t--){
		int n ; 
		scanf("%d",&n);
		char *cor = (char*)malloc(sizeof(char)*n) ; 
		char *che = (char*)malloc(sizeof(char)*n) ; 
		scanf("%s",cor);
		scanf("%s",che); 
		int i ; 
		int score[n+1] ;  
		for ( i = 0 ; i < n+1 ; i++){
			scanf("%d",&score[i]) ; 
		}

		int same = common(cor , che , n) ;
		if (same == strlen(cor)){
			printf("%d\n",score[n]);
			return 0 ; 
		}
		
		
		int max = score[0] ; 
		for ( i = 1 ; i <= same ; i++){
			if (max < score[i]){
				max = score[i] ; 
			}		
		}

		printf("%d\n",max) ;  

	}
	return 0 ;
}