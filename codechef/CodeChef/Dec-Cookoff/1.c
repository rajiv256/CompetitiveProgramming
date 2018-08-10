#include <stdio.h>
#include <stdlib.h>


int max (int a , int b ){
	if (a > b )
		return a ; 
	return b ; 
}

int dp(int index,int m, int size , int *values,int** L){
	//printf("%d\n",index) ; 	
	
	if (index < 0)
		return 0 ; 
	if (index == m-1 ){
		if (values[m-1] <= size){
			L[index][size] = values[m-1] ;
			return values[m-1] ; 
		}
		else{
			L[index][size] = 0 ; 
			return 0 ; 
		}
	}
	if (size == 0){
		return 0 ; 
	}
	int take = 0 ; int dt = 0 ; 
	if (L[index][size] != 0){
		return L[index][size] ; 
	}

	
	if (values[index] <= size){
		take = values[index] + dp(index+1,m,size-values[index],values,L) ; 
		dt = dp(index+1,m,size,values,L) ; 
		L[index][size] = max(take,dt) ; 
		return L[index][size] ; 
	}





}



int main () {
	int a = 3 ; 
	int b = 4 ; 
	int T ; 
	scanf("%d",&T) ; 
	int j = 0 ; int i = 0 ; 
	while (j < T ){
		int n1 ,n2 , m ; 
		scanf("%d%d%d",&n1,&n2,&m);
		int *values = (int*)malloc(sizeof(int)*m);  
		for (i = 0 ; i < m ; i++){
			values[i] = i+1 ; 
		}
		int mini ; 

		if (n1 > n2)
			mini = n2 ; 
		else 
			mini = n1 ; 

		int **L = (int**)malloc(sizeof(int*)*(m));
		for (i = 0 ; i < m+1 ; i++){
			L[i] = (int*)malloc(sizeof(int)*(mini+1)) ; 
		}
	 	int k ; 
		for (i = 0 ; i < m+1 ; i++){
			for (k = 0 ; k < mini+1 ; k++){
				L[i][k] = 0 ; 
			}
		}
		if (mini <= m){
			printf("%d\n",n1+n2-2*mini) ; 
			j++ ; 
			continue ; 
		}
		int result = dp(0,m,mini,values,L) ; 

		printf("%d\n",n1+n2-2*result);




		j++ ; 
	}
	return 0 ; 
}