#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <limits>
using namespace std ; 

int main() {

	int n ; cin >> n ; 
	vector< pair<int,int> > v ; 
	v.resize(n) ;
	int i  = 0 ;  int count = 0 ;
	int total ;  
	while (n--){
		cin >> v[i].first ;
		cin >> v[i].second ;  
		count += v[i].second - v[i].first + 1 ; 
		i++ ; 
	}
	total = count ; 
	int q ; cin >> q ; int r , c ; 
	while (q--){
		cin >> r ; 
		count -= (v[r-1].second - v[r-1].first +1) ; 
		cin >> c ; 
		int j ; 
		for (j = 0 ; j < n ; j++){
			if (j != r-1)
			if (c >= v[j].first && c <= v[j].second)
				count -- ; 
		}
		if (count %2 == 0)
			cout << "E\n" ; 
		else
			cout << "O\n" ; 
		count = total ; 
	}






}