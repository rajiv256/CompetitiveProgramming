#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

typedef vector<float>  vi ; 
typedef vector<pair<int,int> > vp ;
typedef vector<bool> vb ; 
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0 ; i < n ; i++)
#define lld long long int 
#define MIN -1E9 
#define MAX 1E9



int mini(vi& b , int l ,int r){
	float first = 1000000000.0 ; 
	int minInd = -1 ; 
	for (int i = l ; i <= r ; i++){
		if (first > b[i]){
			first = b[i] ; 
			minInd = i ; 
		}
	}
	return minInd ; 
}

int maxi(vi& b , int l ,int r){
	float res = -1000000000.0 ; 
	int maxInd = -1 ; 
	for (int i = l ; i <= r ; i++){
		if (res < b[i]){
			res = b[i] ; 
			maxInd = i ; 
		}
	}
	return maxInd ; 
}

int main(){
	int n ; cin >> n ; 
	vector<float> b (n,0.0) ; 
	forn(i,n){
		float f ; scanf("%f",&f) ; 
		b[i] = f ;  
	}
	int q ; cin >> q ;
	int l , r ;  
	while (q--){
		cin >> l >> r ;
		int mIn = mini(b,l,r);
		float first = b[mIn] ; 
		for (int i = l ; i <= r ; i++){
			b[i] -= first ; 
			b[i] /= 2 ; 
			b[i] += first ;
		} 
		for (int i = 0 ; i < l ; i++){
			b[i] += first ; 
		}
		for (int i = r+1 ; i < n ; i++){
			b[i] += first ; 
		}
		int maIn = maxi(b,0,n-1) ; 
		float second = b[maIn] ; 
		printf("%.1f\n",second) ; 



	}




	return 0 ; 






}