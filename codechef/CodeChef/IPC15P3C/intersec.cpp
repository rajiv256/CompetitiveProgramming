#include <bits/stdc++.h> 

using namespace std ; 

#define ll long long 
#define sp " "
#define el endl 
#define forn(i,st,en) for(int i = st ; i < en ; i++)

int main(){
	ios_base::sync_with_stdio(false) ; 
	cin.tie(0) ; 
	int t ; cin >> t  ;
	while (t--){
		ll n ; cin >> n ; 
		ll ans = n*(n-1) ; 
		ans = ans >> 1 ; 
		cout << ans << el ; 
	}
	return 0 ; 
}