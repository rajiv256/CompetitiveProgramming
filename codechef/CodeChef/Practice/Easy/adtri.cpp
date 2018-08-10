#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std ;
typedef vector<int> vi ; 
typedef vector<pair<int,int> > vp ; 

typedef unsigned long long ull ; 

#define forn(i,n) for (int i = 0 ; i < n ; i++)
#define lld long long int

bool h[5000001] ; 
bool p[5000001] ; 

void sieve() {
	memset(h,false,sizeof(bool)*5000001) ;
	memset(p,false,sizeof(bool)*5000001) ; 

	for (lld i = 2 ; i <= sqrt(5000000) ; i++){
		if (!p[i]){
			for (lld j = 2 ; i*j <= 5000000 ; j++){
				p[i*j] = true ; 
			}
		}
	}
	for (lld i = 2 ; i <= sqrt(5000000) ; i++){
		if (!p[i]){
			if (i%4 == 1){
				for (lld j = 1 ; i*j <= 5000000 ; j++){
					h[i*j] = true ; 
				}
			}
		}
	}





}




int main() {
	
	sieve() ; 
	lld t ; cin >> t ; 
	while (t--){
		lld n ; cin >> n ; 
		if (h[n]){
			cout << "YES\n" ; 
		}
		else {
			cout << "NO\n" ; 
		}
	}
	return  0 ;
}