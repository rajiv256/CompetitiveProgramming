#include<stdio.h>
#include<stdlib.h>

int main () {
	int n , m ; 
	scanf("%d%d",&n,&m);
	int a[m][n] ; 
	int i , j ; 
	for ( i = 0 ; i < m ; i++){
		for ( j = 0 ; j < n ; j++){
			int k ; 
			scanf("%d",&k);
			a[i][j] = k-1 ; 
		}
	}
	int max = -1 , maxVal = -1 ; 	
	int res[n] ; 
	for ( i = 0 ; i < n ; i++)
		res[i] = 0 ; 
	for ( i = 0 ; i < m ; i++){
	 	max = 0 ; maxVal = -1 ; 
		for ( j = 0 ; j < n ; j++){
			if (a[i][j] > maxVal ){
				maxVal = a[i][j] ; 
				max = j ; 
			}
		}
		
		res[max] +=1  ; 
	}
	max = -1 ; maxVal = -1 ; 
	for (i = 0 ; i < n ; i++){
		
		if (res[i] > maxVal){
			maxVal = res[i] ; 
			max = i ; 	
		}
	}
	printf("%d\n",max+1);
	return 0 ; 
}
	
