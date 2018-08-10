#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>

using namespace std; 

typedef vector<int> vi ; 
#define forn(i,n) for (int i = 0 ; i < n ; i++)

int main() {
	int t ; cin >> t  ; 
	while (t--){
		int n ; cin >> n ; 
		vi v ; v.resize(n) ;
		//cout << n << endl ;
		for (int i = 0 ; i < n ; i++){
			//cout << i << " " << n << endl ; 
			cin >> v[i] ;  
		}
		 	
		int c1 = 0 ; int c2 = 0 ; 
		for (int i = 0 ; i < n ; i++){
			for (int j = i+1 ; j < n ; j++ ){
				if (v[i] > v[j]){
					c1++ ;
				}
				if (j == i+1 && v[i] > v[j]){
					c2++ ; 
				}
			}
				
		}
		if (c1 == c2){
			cout << "YES\n" ; 
			
		}
		else {
			cout << "NO\n" ;  
		}
	}
}
