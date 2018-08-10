#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std; 
typedef std::vector<int> vi ;
#define forn(i,n) for(int i = 0 ; i < n ; i++) 

int main() {
	int t ; cin >> t ; 
 
	while (t--){
		int n ; cin >> n ; 
		vi pies ; vi racks ; pies.resize(n) ; racks.resize(n) ; 
		forn(i,n){
			cin >> pies[i] ; 
		}
		forn(i,n) {
			cin >> racks[i] ; 
		}
		sort(pies.begin(),pies.end()) ; 
		sort(racks.begin(),racks.end()) ; 
		int p1 = 0 ; 
		int p2 = 0 ; int count = 0 ; 
		while (p1 != n && p2 != n){
			if (pies[p1] <= racks[p2]){
				p1 += 1 ; 
				p2 += 1 ; 
				count ++ ; 
			}
			else {
				p2 += 1 ; 
			}
		}
		cout << count << endl ; 


	}
	return 0 ; 
}