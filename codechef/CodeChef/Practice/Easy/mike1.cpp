#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std ;
typedef vector<int> vi ; 
typedef vector<pair<int,int> > vp ; 

typedef unsigned long long ull ; 

#define forn(i,n) for (int i = 0 ; i < n ; i++)
#define lld long long int

ull a[500][500] = {0} ;  


int main() {
	int n , m ; cin >> n >> m ; 
	int maxi = max(n,m) ; 
	forn(i,500){
		forn(j,500){
			a[i][j] = 1E10 ; 
		}
	}
	ull temp ;
	forn(i,n){
		forn(j,m){
			cin >> temp ; 
			a[i][j] = temp ; 
		}
	}
	int L; cin >> L ; 
	vp pp ; pp.resize(L) ; 
	int t1 , t2 ; 
	int it = 0 ; 
	while (it < L ){
		cin >> t1 >> t2 ; 
		pp[it].first = t1-1 ; 
		pp[it].second = t2-1 ; 
		it++ ; 
	}
	ull E1 = 0 , E2 = 0 ; int e1 = 0, e2 = 0 ; 
	forn(i,L){
		if (a[pp[i].first][pp[i].second] == 1E10){
			e1 = -1 ; 
			break ; 
		}
		E1 += a[pp[i].first][pp[i].second] ; 
	}
	forn(i,L){
		if (a[pp[i].second][pp[i].first] == 1E10){
			e2 = -1 ; 
			break ; 
		}
		E2 += a[pp[i].second][pp[i].first] ; 
	} 
	if (e1 == -1 && e2 != -1){
		cout << E2 << endl ;
		return 0 ;  
	}
	if (e2 == -1 && e1 != -1){
		cout << E1 << endl ;
		return 0 ;
	}
	if (e1 == -1 && e2 == -1){
		cout << "-1\n" ; 
		return 0 ; 
	}

	cout << max(E1,E2) << endl ;

	return 0 ; 
}