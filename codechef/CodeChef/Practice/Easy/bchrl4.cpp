#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>

using namespace std;
typedef vector<int> vi ; 
#define forn(i,n) for (int i = 0 ; i < n ; i++)
#define lld long long int 
#define vvi vector<vector<int> > 


void findmin(vi& v , vi& L ,int n , int k){
	
	forn(i,n+1){
		L[i] = 1E9 ; 
	}

	L[n] = v[n] ; int i , j ; 
	for (i = n ; i >= 1 ; i--){
		for (j = i-1 ; j >= i-k && j>= 1; j--){
			
			if (L[j] > v[j] * L[i]){
				L[j] = v[j] * L[i] ; 
			}
		}
	}




}





int main(){

	int n , k ; cin >> n >> k ; 
	vi v ; v.resize(n+1) ; 
	forn(i,n){
		cin >> v[i+1] ; 
	}
	//cout << "hello\n" ; 	
	vi empty (n+1,0); 
	vi L(n+1,1000000000) ;  
	findmin(v,L,n,k) ; 
	cout << (L[1]%(1000000007)) << endl ; 
	return 0 ; 

}
