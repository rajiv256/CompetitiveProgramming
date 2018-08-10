#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std ; 

int main() {

	int n ; cin >> n ; 
	cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 

	while (n--){
		string s ; 
		getline(cin,s) ;
		//cout << s ;  
		int l = 0 , r = 0 , i; 

		for (i = 0 ; i < s.size() ; i++){
			if (s[i] == 'W'){
				r = s.size() - l - 1  ;
				break ;  
			}
			l++ ; 
		}
		if (l == 0 && r == 0){
			cout << "Chef\n" ; 
			continue ; 
		}
		if (l == 0 || r == 0){
			cout <<"Aleksa\n" ; 
			continue ;
		}
		if (l > 1 && r > 1){
			cout << "Chef\n" ; 
			continue ; 
		}
		if (l == 1 && r == 1){
			cout <<"Chef\n" ; 
			continue ; 
		}
		if ((l > 1 && r == 1) || (r > 1 && l == 1)){
			cout << "Aleksa\n" ; 
			continue ; 
		}

	}
	return 0 ; 




}