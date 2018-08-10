#include <bits/stdc++.h>

using namespace std ; 


int main(){

	int l, r , x , y, k ; 
	cin >> l >> r >> x >> y >> k ; 

	for(int i = x ; i <= y ; i++){
		if (i*k >= l && i*k <= r){
			cout << YES ; 
			return 0 ; 
		}
	}
	cout << NO ;
	return 0 ; 
}
