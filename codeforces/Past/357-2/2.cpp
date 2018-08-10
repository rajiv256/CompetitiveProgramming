#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;

#define forn(i,n) for(int i = 0; i < n ; i++)
#define INF 1000000
#define LIM 1000000000
#define sp " "
#define el endl
#define ll long long
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x)
#define MXN 100003

int main(){
	ll n ; cin >> n ;
	ll x1 = 1234567 ; ll x2 = 123456  ; ll x3 = 1234 ; int fl = 0 ; 
	for(int i= 0 ; i < 100 ; i++){
		for(int j = 0 ; j < 1000 ; j++){
			ll sum = x1*i+x2*j ; 
			if (sum > n){
				continue ; 
			}
			else{
				if ((n-sum)%1234 == 0){
					fl = 1 ; 
					break ; 
				}
			}
		}
	}
	if (fl){
		cout << "YES" << el ;
	}
	else{
		cout << "NO" << el ; 
	}
}
