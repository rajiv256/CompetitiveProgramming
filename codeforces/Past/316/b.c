#include<stdio.h>
#include<stdlib.h>

int main () {
	int n , m ; 
	scanf("%d%d",&n,&m);
	if (n == 1 ) {
		printf("1\n");
		return 0; 
	}
	if (m - 1 >= n - m){
		printf("%d\n",m-1);
	}
	if ( m - 1 < n - m ){
		printf("%d\n",m+1);
	}
	return 0 ; 
}
