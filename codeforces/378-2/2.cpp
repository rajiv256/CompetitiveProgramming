#include <bits/stdc++.h> 
using namespace std ; 

#define ll long long 
#define el endl 
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100003 
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()

int main(){
	int n ; cin >> n ; 
	int l[n] ; int r[n]  ;
	forn(i,0,n){
		cin >> l[i] >> r[i] ; 
	}
	int maxi = 0 ; 
	int L =0  , R = 0 ; 
	forn(i,0,n){
		L += l[i] ; 
		R += r[i] ; 
	}
	maxi = L-R ; 
	if (maxi < 0)
		maxi = -maxi ; 
	int ans = 0 ;
	int Lold = L ; int Rold = R ;  
	forn(i,0,n){
		L = L-l[i]+r[i] ; 
		R = R-r[i]+l[i] ; 
		//cout << L << sp << R << sp << L-R << el; 
		if (maxi < abs(L-R)){
			maxi = abs(L-R) ; 
			ans = i+1  ; 
		}
		L = Lold ; 
		R = Rold ;  
	}

	cout << ans << el ; 

}