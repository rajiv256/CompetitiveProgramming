#include<stdio.h>
#include<stdlib.h>

int max (int a , int b){
	if ( a > b ){
		return a ; 
	}
	return b ; 
}



int main () {
	int n , i ; 
	scanf("%d",&n) ; 
	int* a = (int*)malloc(sizeof(int)*n) ; 
	for ( i = 0 ; i < n ; i ++){
		scanf("%d",&a[i]) ; 
	}
	int count = 0 ;
	int start = 0 ; 
	int end = n - 1 ; 
	
	while (start <= end){
		
		for (i = start ; i <= end ; i++){
			if (a[i]!= 0 )
				break ; 
		}
		start = i ; 
		for ( i = end ; i >= start ; i--){
			if (a[i]!=0)
				break ;
		}
		end = i ;
		
		if (start >= end){
			printf("%d\n",count) ; 
			return 0 ; 
		}
		
		int temp ;
		printf("-------------------------\n"); 
		for ( i = start+1 ; i < end ; i++){
			for ( i =0 ; i < n ; i++){
				printf("%d ",a[i]) ; 
			}
			printf("\n"); 
			temp = max (a[i] - a[i-1] , a[i]-a[i+1]) ;
			
			if (temp <= 0){
				a[i] -= 1 ; 
			} 
			if (temp > 0){
				a[i] -= temp ; 
			}
		}
		printf("-------------------------\n");
		a[start] = 0 ; 
		a[end]  = 0 ; 
		count ++ ;
		start += 1 ; 
		end -= 1 ; 
	}
	printf("%d\n",count) ; 
	
	
}
