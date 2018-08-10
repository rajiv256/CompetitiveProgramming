#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int useDp(int n , int *L){
	int tw = 0 ;
	int i ;
	if ( n== 1)
		return 1 ; 
	for ( i = 1 ; i <= n ; i++){
		if ( i == 1 || i == n){
			if (L[n-1]==0)
				L[n-1] = useDp(n-1 , L); 
			tw += L[n-1]; 
			tw += 2 ;
			continue ;
		}
		else {
			if (L[i-1] == 0)
				L[i-1] = useDp(i-1,L) ; 
			tw += L[i-1]; 
			if (L[n-i] == 0)
				L[n-i] = useDp(n-i,L) ; 
			tw += L[n-i] ; 
			tw += 1 ;
			continue ; 
		}
	}
	return tw ;
}



int main() {
	int t ; 
	scanf("%d",&t) ;
	int i = 0 ; 
	while ( i < t){
		int n ; 
		scanf("%d",&n) ; 
		int wa = (int)pow(2,n-1) ; 
		int L[n+1]  ;
		int j ; 
		for ( j = 0 ; j <= n ; j++){
			L[j] = 0 ; 
		}
		
		int wj = useDp(n, L) ; 
		printf("%d\n",(wj-wa)%1000000007) ; 
		
		i++ ; 
	}
	
}
