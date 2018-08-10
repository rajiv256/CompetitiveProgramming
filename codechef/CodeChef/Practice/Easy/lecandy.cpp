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
		int  n , c ; 
		cin >> n >> c ;
		int res = 0 ;
		while (n--){
			int k ; cin >>  k ; 
			res += k ;
		} 
		if (res <= c){
			cout << "Yes\n" ; 
			continue ; 
		}
		else {
			cout << "No\n" ; 
			continue ;
		}
	}
	return 0 ; 
}