#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std ;
typedef vector<int> vi ; 
typedef vector<pair<int,int> > vp ; 

typedef unsigned long long ull ; 

#define forn(i,n) for (int i = 0 ; i < n ; i++)
#define lld long long int

#define C(i,j,k) ((a[i] == a[j]) && (a[j] == a[k]))

int main() {
	int t ; cin >> t ;
	while (t--){
		string a[7] ; 
		forn(i,7){
			a[i] = "" ; 
		}
		forn(i,6){
			cin >> a[i+1] ;
		}
		if (C(3,6,1) || C(3,6,2) || C(3,5,2) || C(3,5,1) || C(4,1,6) || C(4,1,5) || C(4,2,6) || C(4,2,5)){
			cout << "YES\n" ; 
		}
		else {
			cout << "NO\n" ; 
		}
	}
	return 0 ; 
}