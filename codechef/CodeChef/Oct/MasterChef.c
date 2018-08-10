#include<stdio.h>
#include<stdlib.h>

int max (int a , int b ) { 
	if (a >= b ) 
		return a ;
	return b ;
}


/* Recursive function which iterates over the negative scores of the chef */
int getMaxScore (int arr[], int from[] ,int to[], int taken[], int score,int index,int n ,int k , int m ) {
	
	/* Base case */
	if ( index >= n-1 || k <= 0 ) 
		return score ; 
	/*Pass if the score is +ve */
	else if ( arr[index] >= 0 ) 
		getMaxScore(arr,from,to,taken,score,index+1,n,k,m) ; 
	
	else{
	
	int t ;
	int i ;int least = 100000;  
	/*  Iterate over all the options available for a given index and choose the optimum choice */
	for (i = 0 ; i < m ; i++) {
		if (index <= from[i]-1 && index >= to[i]-1 && taken[i] <= k ){
			if (  least > taken[i] )
				 t = i ; 
				least = taken[i] ; 
		}
		
	}
	/* Recurse whether to take it or not */
	return (max (getMaxScore(arr,from,to,taken,score-arr[index],index+1,n,k-least,m),getMaxScore(arr,from,to,taken,score,index+1,n,k,m))) ;
	}	
}



int main() {
	int t, i , n, m , k , score = 0 ,temp = 0 ; 
	scanf("%d",&t) ; 
	while (t-- ) {
		
		scanf("%d%d%d",&n,&k,&m ) ; 
		int arr[n] ; 
		for (i = 0 ; i < n ; i++ ){
			scanf("%d",&arr[i] ) ; 
			
		}
		for ( i = 0 ; i < n ; i ++){
			score+=arr[i] ;
		}
		int from[m] , to[m] , taken[m] ; 
		for ( i = 0 ; i < m ; i++ ) {
			scanf("%d",&from[i]) ; 
			scanf("%d",&to[i]) ; 
			scanf("%d",&taken[i]) ; 
		}
		int index =  0 ; 
		
		int sc = getMaxScore (arr, from,to,taken,score,index,n,k,m ) ; 
		printf("%d\n",sc ) ; 
			
	}
	return 0 ; 
}		
