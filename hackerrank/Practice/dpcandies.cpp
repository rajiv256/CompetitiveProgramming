#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

typedef vector<int> vi ; 
#define forn(i,n) for (int i = 0 ; i < n ; i++)
#define lld long long int 
int mlr[2][100000]; 

int fillml(vi& a , int n , int i){
	if (mlr[0][i] != -1){
		return mlr[0][i] ; 
	}
	if (a[i] < a[i-1]){            // < | <= 
		int k = fillml(a,n,i-1) ; 
		mlr[0][i] = k ; 
	}
	else {
		mlr[0][i] = i ; 
	}
	return mlr[0][i] ; 
}	
int fillmr(vi& a , int n ,int i){
	 
	if (mlr[1][i] != -1){
		return mlr[1][i] ; 
	}
	if (a[i] < a[i+1]){
		int k = fillmr(a,n,i+1) ; 
		mlr[1][i] = k ; 
	}
	
	if (a[i] >= a[i+1]){
		 
		mlr[1][i] = i ; 
	}
	return mlr[1][i] ; 
}





int main() {
	int n ; cin >> n ; 
	vi a ; a.resize(n) ;
	
	forn(i,n){
		cin >> a[i] ; 
	}
	
	forn(i,n){
		mlr[0][i] = -1 ; 
		mlr[1][i] = -1 ; 
	}
	mlr[0][0] = 0 ; 
	mlr[1][n-1] = n-1 ; 
	for (int i = n-1 ; i >= 1 ; i--){
		fillml(a,n,i) ; 
	}
	for (int i = 0 ; i < n-1 ; i++){
		fillmr(a,n,i) ; 
	}
	/*forn(i,n){
		cout << mlr[0][i] << " " ; 
	}
	cout << endl ; 
	forn(i,n){
		cout << mlr[1][i] << " " ; 
	}
	cout << endl ;*/
	vi res(n,1) ; 
	forn(i,n){
		for (int j = i-1 ; j >= mlr[0][i] ; j--){
			res[j] += 1 ; 
		}
		for (int j = i+1 ; j <=mlr[1][i] ; j++){
			res[j] += 1 ; 
		}
	}
	if (a[0] < a[1]){
		a[0] = 1 ; 
	}
	if (a[n-1] < a[n-2]){
		a[0] = 1 ;
	}
	for (int i = 1 ; i <= n-2 ; i++){
		if (a[i] > a[i+1] && a[i] > a[i-1]){
			res[i] = max(res[i+1],res[i-1])+1 ; 
		}
		
	}
	int result = 0 ; 
	forn(i,n){
		result += res[i] ; 
	}


	

	cout<< result << endl ; 

	return 0 ; 
}
