#include<stdio.h>
#include<stdlib.h>

void update(int* arr , int *L , int index ,int n){
	if (index == n-1){
		return ;
	}

	if (arr[index] > arr[index + 1]){
		update (arr , L , index + 1, n) ; 
	}
	else {
		update(arr , L , index + 1 , n);
		L[index] += L[index+1] ;  
	}
	return ; 
}



int main() {
	int t ; 
	scanf("%d",&t);
	while (t--){
		int n ; 
		scanf("%d",&n);
		if (n == 1){
			printf("1\n");
			return 0 ;
		}
		int *arr = (int*)malloc(sizeof(int)*n);
		int *L  = (int*)malloc(sizeof(int)*n);

		int i ; 
		for ( i = 0 ; i < n ; i++){
			scanf("%d",&arr[i]) ; 
		}
		for ( i = 0 ; i< n ; i++){
			L[i] = 1 ; 
		}
		update(arr , L , 0 , n) ; 
		int sum = 0 ; 
		for (i = 0 ; i < n ; i++){
			sum += L[i]; 
		}
		printf("%d\n",sum);	
	}
	return 0 ; 
}