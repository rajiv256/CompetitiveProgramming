#include <bits/stdc++.h>

using namespace std ; 

#define forn(i,st,en) for(int i = st ; i < en ; i++)
#define el endl 


int main(){
	int n ; cin >> n ; 
	string s ; cin >> s ; 
	int a[n] ; 
	forn(i,0,n){
		cin >> a[i] ; 
	}
	int diff = INT_MAX ; int ans = INT_MAX ;  
	forn(i,1,n){
		diff = a[i]-a[i-1] ; 
		if (s[i]=='L' && s[i-1]=='R'){
			ans = min(ans,diff/2) ; 
		}
	}
	if (ans == INT_MAX){
		cout << "-1" << el ; 
	}
	else{
		cout << ans << el ; 
	}
	return 0 ; 
}