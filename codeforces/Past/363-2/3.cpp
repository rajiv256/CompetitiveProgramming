#include <bits/stdc++.h> 

using namespace std ; 

#define ll long long 
#define sp " "
#define el endl 
#define forn(i,st,en) for(int i = st ; i < en ; i++)
#define MXN 109

int L[MXN] ; 




int main(){
	int n ; cin >> n ; 
	int a[n+1] ; 
	forn(i,1,n+1){
		cin >> a[i] ; 
	}
	a[0] = -1 ; int cnt = 0 ; int prev = 0 ;  
	forn(i,1,n+1){
		if (a[i]==0){
			prev = 0 ; 
			cnt++ ; 
			continue ; 
		}
		if (a[i]==1){
			if (prev!=1){
				prev =1 ;
				continue ;  
			}
			else{
				prev = 0 ; 
				cnt++ ; 
				continue ; 
			}
		}
		if (a[i]==2){
			if (prev != 2){
				prev = 2 ; 
				continue ; 
			}
			else{
				prev = 0 ;
				cnt++ ; 
				continue ; 
			}
		}
		if (a[i]==3){
			if (prev == 1){
				prev = 2 ; 
				continue ; 
			}
			if (prev == 2){
				prev = 1 ; 
				continue ; 
			}

		}
	}
	cout << cnt << el ; 
	return 0 ; 

}