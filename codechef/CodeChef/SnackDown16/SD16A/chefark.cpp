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
#define MOD 1000000007
#define MXN 100003
#define gc getchar_unlocked	
void sci(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

ll a[MXN] ; 



ll ncr(ll n , ll r){
	ll prod = 1 ; 
	for(int i = n ; i >= n-r+1 ; i--){
		prod *= i ; 
	}
	for(int i = r ; i >=1 ; i--){
		prod /= i ; 
	}
	return prod ; 
}


int main(){
	int t ; sci(t) ; 
	 
	for(int i = 1 ; i < MXN ; i++){
		
	}
	while (t--){
		int n , k ; sci(n) ; sci(k) ;  
		forn(i,n){
			cin >> a[i] ; 
		}
		ll ans = 0 ; 
		if (k%2==0){
			for(int i = 0 ; i <= k ; i+=2 ){
				ans += ncr(n,i) ; 
				ans %= MOD ; 
			}
		}
		if (k%2==1){
			for(int i = 1 ; i <= k ; i+=2){
				ans += ncr(n,i) ; 
				ans %= MOD ; 
			}
		}
		cout << ans << el ;
	}
}

























