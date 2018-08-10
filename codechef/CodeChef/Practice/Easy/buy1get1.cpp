#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>

using namespace std; 
typedef vector<int> vi ; 
#define forn(i,n) for (int i = 0 ; i < n ; i++)

int main() {
	int t ; cin >> t ; 
	while (t--){
		string s ; vi v ; 
		cin >> s ; 
		map<int,int> cnt ; 
		forn(i,s.size()){
			cnt[s[i]-'a']++ ; 
		}
		int result = 0 ; 
		for (map<int,int> :: iterator it = cnt.begin() ; it != cnt.end() ; it++ ){
			result += (*it).second/2 ; 
			result += (*it).second % 2 ; 
		}
		cout << result << endl ; 
	}
	return 0 ; 


}