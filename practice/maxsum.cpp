// http://wcipeg.com/problem/dp1p1

#include <bits/stdc++.h> 

using namespace std ; 

#define el endl 
#define INF 1000000008
#define xx first

int main(){
	int n ; cin >> n ; 
	int a[n+1] ; 
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ; 
	}

	int L[n+2][2] ; memset(L,0,sizeof(L)) ; 

	for(int i = 1 ; i <= n ; i++){
		L[i][0] = max(L[i-1][0],L[i-1][1]) ;
		L[i][1] = L[i-1][0] + a[i] ; 
	} 
	printf("%d\n",max(L[n][0],L[n][1]));
	return 0 ; 
}