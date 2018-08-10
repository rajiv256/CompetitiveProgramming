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
#define INF 10000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()

int main(){
	int n ; cin >> n ; 
	int a[n] ; 
	forn(i,0,n){
		cin >> a[i] ; 
	}
	forn(i,0,n-1){
		if (a[i]%2==0){
			continue ; 
		}
		else{
			a[i+1] -= 1 ; 
			if (a[i+1] < 0){
				cout << "NO" << el ; 
				return 0 ; 
			}
			continue ; 
		}
	}
	if (a[n-1]%2 != 0){
		cout << "NO" << el ;
		return 0 ; 
	}
	cout << "YES" << el ; 
	return 0  ;

}