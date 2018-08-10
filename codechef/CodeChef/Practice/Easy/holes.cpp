#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std ; 

int main(){
	map<char,int> m ; 
	m['A'] = 1 ; 
	m['B'] = 2 ; 
	m['D'] = 1 ; 
	m['O'] = 1 ;
	m['P'] = 1 ;
	m['Q'] = 1 ; 
	m['R'] = 1 ; 
	int t ; cin >> t ; 
	while (t--){
		string s ; 
		cin >> s ; 
		int count = 0 ; 
		for (int i = 0 ; i < s.size() ; i++){
			count += m[s[i]] ; 
		}
		cout << count << endl ; 
	}
	return 0 ; 
}
