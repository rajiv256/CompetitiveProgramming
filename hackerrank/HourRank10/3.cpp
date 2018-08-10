#include <bits/stdc++.h> 

using namespace std ; 

#define ll long long 
#define forn(i,st,en) for(int i=st ; i < en ; i++)
#define el endl 
#define sp " "



int main(){
	ios_base::sync_with_stdio(false) ; 
	cin.tie(0) ; 
	int t ; cin >> t ; 
	while (t--){
		ll l , a , n , d ; 
		cin >> l >> a >> n >> d ;	
		ll items = 0 ; 
		ll cost = 0 ;  
		ll maxC = a ;  
		if (maxIt < 0){
			cout << "SAD" << el ; 
			continue ; 
		}
		if (d==1 ){
			cost = maxC*l ; 
			cout << cost << el  ; 
			continue ; 
		}
		ll x = (n-1)/(d-1) ; 
		for(int i = maxC ; i >= maxC-x ; i--){
			cost += x*i ; 
		}
		
	}
	 	
}