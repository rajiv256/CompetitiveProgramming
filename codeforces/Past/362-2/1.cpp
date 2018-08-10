#include <bits/stdc++.h> 

using namespace std ; 

#define ll  long long 
#define el endl 

int main(){
	ios_base::sync_with_stdio(false) ; 
	cin.tie(0) ; 
	ll t , s ,x ; 
	cin >> t >> s >> x ; 

	if (x < t){
		cout << "NO" << el ; 
		return 0 ; 
	}
	if (x == t){
		cout << "YES" << el ; 
		return 0 ; 
	}
	if (x >= t+s){
		if ((x-t)%s==0 || (x-t)%s==1){
			cout << "YES" << el ; 
		}
		else
			cout << "NO" << el ; 
		return 0 ; 
	}
	cout << "NO" << el ; 
	return 0 ; 

}