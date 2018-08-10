#include <bits/stdc++.h>

using namespace std ; 

#define REP(i,st,en) for(int i=st;i<en;i++)
#define el endl 

int main(){
	ios_base::sync_with_stdio(false) ; 
	cin.tie(0) ; 
	int n , k ; cin >> n >> k  ;
	int a[n] ; int energy = 100 ;  
	REP(i,0,n){
		cin >> a[i] ; 
	}

	int start = 0 ; 
	start += k ;
	start %= n ;  
	if (a[start]) energy-= 3 ;
	else energy-- ;  
	while (start != 0){
		start += k ; 
		start %= n ; 
		if (a[start]) energy -= 3; 
		else energy -=1 ;
	}
	cout << energy << el ; 

}
