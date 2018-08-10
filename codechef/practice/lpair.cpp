/* 
        Code written by rajiv. 
        God speed!
*/
#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define sclf(x) scanf("%lf",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 

ll BIT[MXN] ; 


ll query(int i){
	ll sum = 0 ; 
	while (i > 0){
		sum += BIT[i] ; 
		i -= (i&-i) ; 
	}
	return sum ;
}

void update(int i){
	while (i < MXN){
		BIT[i] += 1 ; 
		i += (i&-i) ; 
	}
}

void dimred(ll b[], map<ll,ll>& m, int n){
	set<ll> s ; 
	for(int i = 1 ; i <= n ; i++){
		s.insert(b[i]) ; 
	}
	int idx = 1 ; 
	for(set<ll>::iterator it = s.begin() ; it != s.end() ; it++){
		m[*it] = idx++ ; 
	}
}

int main(){

	int n ; sci(n) ; 
	
	vector<pair<ll,ll> > v ; 
	for(int i = 1 ; i <= n ; i++){
		ll x , y ; scll(x) ; scll(y) ; 
		v.pb(mp(x,y)) ; 
	}
	sort(all(v)) ; 
	int a[n] ; int b[n] ; 
	for(int i = 0 ; i < n ; i++){
		a[i] = v[i].yy ; 
		b[i] = a[i] ; 
	}
	sort(a,a+n) ; 
	for(int i =0 ; i < n ; i++){
		b[i] = lower_bound(a,a+n,b[i])-a ;
		b[i]+= 1;  
	}

	ll ans = 0 ; 
	for(int i = n-1 ; i >= 0 ; i--){
		ans += query(b[i]-1) ; 
		update(b[i]) ; 
	}

	printf("%lld\n", ans);
	


}