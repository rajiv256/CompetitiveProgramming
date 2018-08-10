#include <iostream>
#include <map>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std ; 
typedef vector<int> vi ; 
typedef vector<bool> vb ; 
#define lld long long int 


#define forn(i,n) for (int i = 0 ; i < n ; i++)
#define N 50000

 

lld dp(vi& a, int idx, int remStock,int n,lld** L ){
	//cout << idx << " " << remStock << endl ; 
	if (remStock < 0){
		return 0 ; 
	}
	if (idx == n-1){
		int buy = a[idx] ;  
		int sell = (remStock+1)* a[idx] ; 
		L[idx][remStock] = sell - buy ;
		return L[idx][remStock] ;  
	}
	if (L[idx][remStock] != -1){
		return L[idx][remStock] ; 
	}
	if (remStock == 0){
		L[idx+1][remStock+1] = dp(a,idx+1,remStock+1,n,L) ; 
		L[idx+1][remStock] = dp(a,idx+1,remStock,n,L) ; 
 		L[idx][remStock] = max(L[idx+1][remStock],-a[idx]+L[idx+1][remStock+1]) ; 
		return L[idx][remStock] ; 
	}
	if (remStock > 0){
		lld temp = -1000000000 ; 
		for (int i = 0 ; i <= remStock ; i++){
			L[idx+1][remStock+1-i] = dp(a,idx+1,remStock+1-i,n,L) ; 

			if (temp < -a[idx]+i*a[idx]+L[idx+1][remStock+1-i])  
				temp = -a[idx]+i*a[idx]+L[idx+1][remStock+1-i] ; 
			
			L[idx+1][remStock-i] = dp(a,idx+1,remStock-i,n,L) ; 
			if (temp < i*a[idx]+L[idx+1][remStock-i]){
				temp = i*a[idx]+L[idx+1][remStock-i] ; 
			}
		}
		temp = max(temp,L[idx][remStock]) ; 
		L[idx][remStock] = temp ; 
		return L[idx][remStock] ; 
	}
	//cout << idx << remStock << endl ; 
	return L[idx][remStock] ; 
}





int main() {

	int t ; cin >> t ; 
	 
	while (t--){
		int n ; cin >> n ; 
		lld** L = (lld**)malloc(sizeof(lld*)*n) ; 
		forn(i,n) {
			L[i] = (lld*)malloc(sizeof(lld)*n) ; 
		}
		vi a ; a.resize(n) ;
		forn(i,n){
			cin >> a[i] ; 
		}
		
		forn(i,n){
			forn(j,n){
				L[i][j] = -1 ; 
			}
		}
		lld k = dp(a,0,0,n,L) ; 
		cout << k << endl ; 
	}




}