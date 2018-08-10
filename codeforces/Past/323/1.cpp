#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>


using namespace std ; 
 
int main() {
	int n ; 
	cin >> n ; 
	int i = 0 , j = 0 ; 
	
	vector<int> v (n+1,0) ; 
	vector<int> h (n+1,0) ;
	int r = n*n ; int day = 1 ; 
	while (day <= r){
		int a,b ; 
		cin >> a ; cin >> b ; 
		if (v[a] == 0 && h[b] == 0){
			v[a] = 1 ; h[b] = 1 ; 
			cout << day << " " ;  
		}
		day++ ; 
	}
}