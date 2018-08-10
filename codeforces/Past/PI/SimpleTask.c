#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Merge ( char* s , int from , int middle , int to, int flag ) { 
	char copy[(int)strlen(s)] ;
	int p ; 
	for (p = 0 ; p < (int)strlen(s) ; p++ ) {
		copy[p] = '0' ; 
	}
	
	int i = from  , j = middle+1 ; 
	int k = from ; 
	if (flag ==  1 ){
		while ( i <= middle && j <= to ) {
	
			if ( s[i] < s[j] ) {
				copy[k] = s[i] ; 
				k++ ; i++ ; 
			}
			if ( s[i] > s[j] ) { 
				copy[k] = s[j] ; 
				k++ ; j++ ; 
			}
			if (s[i] == s[j] ) {
				copy[k] = s[i] ; 
				k++ ; i++ ; 
				copy[k] = s[j] ;
				k++ ; j++ ;  
			}
		}
	
		while (i <= middle ) {
			copy[k] = s[i] ; 
			k++ ; i++ ; 
		}
	
		while ( j <= to ) {
		
			copy[k] = s[j] ; 
		
			k++ ; j++ ; 
		}
	}
	else {
			while ( i <= middle && j <= to ) {
	
			if ( s[i] > s[j] ) {
				copy[k] = s[i] ; 
				k++ ; i++ ; 
			}
			if ( s[i] < s[j] ) { 
				copy[k] = s[j] ; 
				k++ ; j++ ; 
			}
			if (s[i] == s[j] ) {
				copy[k] = s[i] ; 
				k++ ; i++ ; 
				copy[k] = s[j] ;
				k++ ; j++ ;  
			}
		}
	
		while (i <= middle ) {
			copy[k] = s[i] ; 
			k++ ; i++ ; 
		}
	
		while ( j <= to ) {
		
			copy[k] = s[j] ; 
		
			k++ ; j++ ; 
		}
		
		
		
	}

	for ( i = from ; i <= to ; i++ )
		s[i] = copy[i] ; 
	
}		


void mergeSort( char* s , int from , int to , int k  ) {
	if (from == to )
		return ;
	if (from != to ) {
		int middle = (from + to) /2  ; 
		mergeSort(s , from , middle, k ) ; 
		mergeSort(s, middle+1 , to, k  ) ; 
		Merge (s , from, middle, to, k ) ; 
	}
	
}

	
int main ( ) {
	int n , q , i ,from,to, k; 
	scanf("%d%d",&n,&q ) ; 
	char* s = (char*) malloc (sizeof(char)*n) ; 
	scanf("%s",s) ; 
	while (q-- ) {
		scanf("%d%d%d",&from,&to,&k) ; 
		char* copy = (char*) malloc (sizeof(char)) ;
		copy = s ; 
		mergeSort( s , from-1 , to-1, k ) ;
		 
	}
	printf("%s\n	", s ) ; 
}


