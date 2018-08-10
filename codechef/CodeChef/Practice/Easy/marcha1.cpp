#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std; 
typedef vector<int> vi ; 
#define forn(i,n) for (int i = 0 ; i < n ; i++)

bool solve(vi& v , int i , int m){
	if (i == v.size()){
		if (m == 0){
			return true ; 
		}
		else { 
			return false; 
		}
	}
	if (m == 0){ 
		return true; 
	}
	return (solve(v,i+1,m-v[i]) || solve(v,i+1,m) ); 

}





int main() {
	int t ; cin >> t ; 
	while (t--){
		int n , m ; cin >> n >> m ; 
		vi v ; int a ; v.resize(n) ;  
		forn(i,n){
			cin >> a ; 
			v[i] = a ; 
		}

		if (solve(v,0,m)){
			cout << "Yes\n" ; 
			continue ; 
		} 
		else{
			cout << "No\n" ; 
		}

	}
}

