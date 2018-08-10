#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cstring>
using namespace std ;

typedef vector<int> vi ; 





int main() {

	int n , k ; cin >> n >> k  ; 
	bool op[n] ; 
	memset(op,false,sizeof(bool)*n) ; 
	int sum = 0 ; 
	while (k--){
		string s ; int a ;
		cin >> s ; 
		 
		if (s == "CLICK"){
			cin >> a ; 
			if (op[a-1] == false){
				sum += 1 ;
				op[a-1] = true ; 
				cout << sum << endl ; 
				continue ; 
			} 
			else if (op[a-1] == true){
				sum -= 1 ; 
				op[a-1] = false ; 
				cout << sum << endl ; 
				continue ; 
			}

		}	
		if (s == "CLOSEALL"){
			sum = 0 ;
			memset(op,false,sizeof(bool)*n) ; 
			cout << sum << endl ; 
		}

	}






}
