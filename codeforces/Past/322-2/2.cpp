#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <utility>

using namespace std;
typedef std::vector<int> vi ;



int main() {

	int n ; cin >> n ; 
	vi v ; v.resize(n) ; 
	for (int i = 0 ; i < n ; i++){
		cin >> v[i] ; 
	}
	vi res(n,0) ; 
	int max = v[n-1] ;  
	for (int i = n-2 ; i >= 0 ; i--){
		if (v[i] > max){
			max = v[i] ;
			res[i] = 0 ;  
		}
		else {
			res[i] = max - v[i] + 1 ; 
		}
	}

	for (int i = 0 ; i < n ; i++){
		cout << res[i] << " "; 
	}
	return 0 ; 



}
