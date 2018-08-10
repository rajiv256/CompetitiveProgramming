#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main () {
	int n , q , i ; 
	scanf("%d%d",&n,&q) ; 
	int par[n] ; 
	for ( i = 0 ; i < n ; i++){
		scanf("%d",&par[i]) ; 	
	}
	int depth[n] ; 
	depth[0] = 1 ; 
	for ( i = 0 ; i < n-1 ; i++){
		depth[i+1]
