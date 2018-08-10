#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std ;

int main () {

	int n , k ; 
	cin >> n ; 
	cin >> k ; 
	vector<int> v ; 
	v.resize(n);

	int i ; 
	for (i = 0 ; i < n ; i++){
		cin >> v[i] ; 
	}

	int max = -1 ; 
	if (n <= k){
		cout << v[n-1] <<"\n" ; 
		return 0 ; 
	}


	vector<int> fits (v.begin()+n-k , v.end()) ; 


	vector<int>extra(v.begin(),v.begin()+n-k) ;
	reverse(extra.begin(),extra.end()) ; 

	for (i = 0 ; i < extra.size() ; i++){
		fits[i] += extra[i] ; 
	}
	
	for (i = 0 ; i < k ; i++){
		if (max < fits[i]){
			max = fits[i] ; 
		}
	}	
	cout << max <<"\n" ; 
	return 0 ; 

}