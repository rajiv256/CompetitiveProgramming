// http://wcipeg.com/problem/dp1p3

#include <bits/stdc++.h> 

using namespace std ; 

#define MOD 1000000007
#define INF 1000000008 

int main(){
	int n ; cin >> n ; 
	int a[n+1] ; 
	for(int i =1 ; i <= n ; i++){
		cin >> a[i] ; 
	}
	int L[n+2] ; 
	L[0] = 0 ; 
	for(int i = 1; i <= n ; i++) L[i] = 1; 
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j < i ; j++){
			if (a[j] < a[i]){
				L[i] = max(L[i],1+L[j]) ; 
			}
		}
	}
	int maxi = 0 ; 
	for(int i = 0 ; i <= n ; i++){
		maxi = max(maxi, L[i]) ; 
	}
	cout << maxi << endl ; 
	return 0 ; 

}