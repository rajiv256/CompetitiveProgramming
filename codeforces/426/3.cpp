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
#define MXN 100005
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

bool prime[10*MXN]  ; 

void sieve(){
	memset(prime,true,sizeof(prime)) ; 
	prime[1] = true ; 
	prime[2] = true ; 

	for(int i = 2 ; i < 10*MXN ; i++){
		if (!prime[i]){
			continue ;  
		} 
		for(int j = 2 ; i*j < 10*MXN ; j++){
			prime[i*j] = false ; 
		}
	}
	return ; 
}

map<int,int> primefactors(int n){

	map<int,int> m ; 
	while(n%2 ==0){
		m[2]++ ; 
		
		n /= 2 ; 
	}

	for(int i = 3 ; i < 10*MXN ; i+=2 ){
		if (prime[i]){
			while (n%i==0){
				m[i]++ ; 
				n /= i ; 
			}
		}
	}
	return m ; 

}
bool reduce(int x , int y){
	int p = min(x,y) ; int q = max(x,y) ; 
	if ((p==0) && (q==0)) return true ; 
	if ((p==0) && (q != 0)) return false ; 
	return reduce(p-1,q-2) ; 
}




int main(){
	int t; cin >> t ; 
	
	vector<ll> v; ll x = 1 ; 
	for(int i = 0 ; i <= 1000000+1 ; i++){
		v.pb(x*x*x) ; 
		x++ ; 
	}
	
	while (t--){
		ll a, b ; cin >> a >> b ; 
		ll prod = a*b ; 
		string ans = "No" ;
		if (binary_search(all(v)),prod){
			std::vector<ll> iterator it  = lower_bound(all(v),prod) ;
			ll num = it-v.begin()+1 ; 
			if (a%num==0 && b%num==0) ans = "Yes" ; 
		}
		cout << ans << el ; 

	}
	return 0 ; 
}



















