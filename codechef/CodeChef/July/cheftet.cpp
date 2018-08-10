#include <bits/stdc++.h>

using namespace std ;



#define forn(i,n) for(int i = 0; i < n ; i++)
#define INF 10000000000LL

#define el "\n"
#define MXN 100009
#define sci(x) scanf("%d",&x)
#define mp make_pair
#define ll long long

bool valid(int idx , int n){
	if (idx >= 0 && idx < n){
		return true ; 
	}
	return false ; 
}

bool solve(ll a[] ,ll b[] , ll val,  int idxa,int idxb, int n){
	if (idxa==n){
		return true ;  // check if we need to use all elements of B
	}
	

}


int main(){
	
	int t ; sci(t) ; 
	while (t--){
		int n; sci(n) ; 
		ll a[n] ; ll b[n] ; 
		forn(i,n){
			cin >> a[i] ; 
		}
		forn(i,n){
			cin >> b[i] ; 
		}
		


	}





}