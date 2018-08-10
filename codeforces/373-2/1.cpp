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
	int n ;  cin >> n ; 
	if (n == 1){
		int x ; cin >> x ; 
		if (x == 15){
			cout << "DOWN" << el ; 
			return 0 ; 
		}
		if (x == 0){
			cout << "UP" << el ; 
			return 0 ; 
		}
		cout << "-1\n"; 
		return 0 ; 
	}

	int a[n] ; 
	forn(i,0,n){
		cin >> a[i] ; 
	}
	if (a[n-1]==0){
		cout << "UP" << el ; 
		return 0 ; 
	}
	else if (a[n-1] == 15){
		cout << "DOWN" << el ; 
		return 0 ; 
	}
	else{
		if (a[n-2] < a[n-1]){
			cout << "UP" << el ;
			return 0 ; 
		}
		else{
			cout << "DOWN" << el ; 
			return 0 ; 
		}
	}

	return 0 ; 



}