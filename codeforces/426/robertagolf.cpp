// http://wcipeg.com/problem/ccc00s4

#include <bits/stdc++.h> 
using namespace std ; 

typedef vector<int> vi ; 
typedef vector<bool> vb ; 

#define MOD 1000000007 
#define INF 1000000009
#define el endl 
#define sp " "



int main(){

	int sum ; cin >> sum ; 
	int n ; cin >> n ; int a[n+1] ; 
	for(int i =1 ; i <= n ; i++){
		cin >> a[i] ; 
	}
	int L[sum+1] ; 
	for(int i = 0 ; i <= sum ; i++) L[i] = INF ; 
	L[0] = 0 ; 
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j <= sum ; j++){
			if (j-a[i] >= 0){
				L[j] = min(L[j],1+L[j-a[i]]) ; 
			}
		}
	}
	if (L[sum] >= 0 && L[sum] < INF){
		printf("Roberta wins in %d strokes.", L[sum]);
	}
	else {
		printf("Roberta acknowledges defeat.");
	}
	return 0 ; 


}