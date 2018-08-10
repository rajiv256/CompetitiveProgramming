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
	ll n , m ; 
	cin >> n >> m ; 
	ll a[5] ; 
	ll b[5] ; 
	forn(i,5){
		a[i] = n/5 ; 
		b[i] = m/5 ; 
	}
	int idx = 1 ; int x = 0 ; 
	while (x <  n%5){
		a[idx] += 1 ; 
		idx += 1 ; idx %= 5 ; 
		x++ ; 
	}
	idx = 1 ; x = 0 ; 
	while (x <  m%5){
			b[idx] += 1 ; 
			idx += 1 ; idx %= 5 ; 
			x++  ; 
	}
	ll ans = 0 ; 
	forn(i,5){
		ans += a[i]*b[(5-i)%5] ; 
	}
	cout << ans << el ; 
	
	
	
	
}

