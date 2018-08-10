#include<stdio.h>
#include<stdlib.h>

int check (int* arr , int n ){
	int maxIndex = 0 ; 
	int max = arr[0] ; 
	int i ; 
	for ( i = 0 ; i < n ; i++){
		if (arr[i] >= max)
			maxIndex = i ; 
	}
	if (maxIndex == 0)
		return 1 ; 
	return 0 ; 
}



int main (){
	int n , i ; 
	scanf("%d",&n) ;
	int* arr = (int*) malloc(sizeof(int)*n) ;  
	for ( i = 0 ; i < n ; i++){
		scanf("%d",&arr[i]) ; 
	}
	int max = arr[0] ; 
	
	int count = arr[0] ; 
	int che = check(arr,n) ; 
	while (che!=1){
		for (i = 1 ; i < n ; i++){
			if (arr[i] >= arr[0]){
				arr[i] -= 1 ; 
				arr[0] += 1 ; 
			}
		}
		che = check (arr,n) ; 
	}
	int a = arr[0] - count ; 
	printf("%d\n",a) ; 
}

