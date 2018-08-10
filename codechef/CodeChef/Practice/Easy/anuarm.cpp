#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std ;

typedef vector<int> vi ; 
typedef vector<int> vc ; 

#define forn(i,n) for (int i = 0 ; i < n ; i++)

int mod(int a ){
	if (a > 0)
		return a  ;
	else 
		return -a ; 
}

int main() {
	int t ; cin >> t ; 
	while (t--){
		int n , m ; cin >> n >> m ; 
		vi maxi ; maxi.resize(n) ; 
		vi act ; act.resize(n) ; 
		forn(i,n){
			maxi[i] = -1 ; 
			act[i] = i ; 
		}
		vi ms ; ms.resize(m) ; 
		forn(i,m){
			cin >> ms[i] ; 
		}
		sort(ms.begin(),ms.end()) ; 
		forn(i,n){
			int max1 = mod(ms[0]-i) ; 
			int max2 = mod(ms[ms.size()-1]-i) ;
			cout << max(max1,max2) << " " ; 
		} 
		cout << endl ; 

	}
	return 0 ;
}
