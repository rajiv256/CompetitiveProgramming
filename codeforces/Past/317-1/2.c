#include<stdio.h>
#include<stdlib.h>

void swap (int* a , int from , int to ) {
	int temp  = a[i] ; 
	a[from] = a[to] ; 
	a[to] = temp ; 
	return ; 
}
int abs (int a ){
	if (a > 0 )
		return a ; 
	return -a ; 
}

void getGreedy(int* a , int n , int k ){
	int i ; int index = i ; int diff = 1000000; 
	for ( i = 0 ; i < n-k ; i++ ){
		for ( j = i+1 ; j < n ; j++ ){
			int k = abs(a[i]-a[j]) ; 
			if (diff >= k){
				index = j ; 
				diff  = k ; 
				
			}
		}
		swap (a , index , i+k) ; 
	}
}

int main () {
	int n , k , i ; 
	scanf("%d%d", &n, &k) ; 
	int* a = (int*)malloc(sizeof(int)*n); 
	
	
	for ( i = 0 ; i < n ; i++ ){
		scanf("%d",&a[i]) ; 
	}
	
	getGreedy (a , n , k ) ; 
	
	
	
	
	
	
	
}
