#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define forn(i,n) for (int i = 0 ; i < n ; i++)

int main() {
	int t ; cin >> t ; 
	while (t--){
		int n ; cin >> n ; 
		map<int,int> cnt ; 
		int a ; 
		forn(i,n){
			cin >> a ; 
			cnt[a]++ ; 
		}
		int maxi = 0 ; int maxel = -1 ; 
		for (map<int,int> :: iterator it = cnt.begin() ; it != cnt.end() ; it++){
			if (maxi < (*it).second ){
				maxi = (*it).second ; 
				maxel = (*it).first ; 
			}
		}
		cout << maxel << " " << maxi << endl ; 
	}
	return 0 ; 
}
