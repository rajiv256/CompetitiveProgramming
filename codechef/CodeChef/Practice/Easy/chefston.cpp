#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int>  vi ; 
typedef vector<pair<int,int> > vp ;
typedef vector<bool> vb ; 

#define forn(i,n) for(int i = 0 ; i < n ; i++)
#define lld long long int 

int main() {
	int t ; cin >> t ; 
	while (t--){
		int n , k ; cin >> n >> k ; 
		vi a ; a.resize(n) ; 
		forn(i,n){
			cin >> a[i] ; 
		}
		vi c ; c.resize(n) ; 
		forn(i,n){
			cin >> c[i] ; 
		}
		vector<lld> res ; res.resize(n) ; 
		lld maxres = -1 ;
		forn(i,n){
			res[i] = (k/a[i]) * c[i] ;
			if (maxres < res[i]){
				maxres = res[i] ; 
			} 
		}
		
		cout << maxres << endl ; 
	}
	return 0 ; 
}