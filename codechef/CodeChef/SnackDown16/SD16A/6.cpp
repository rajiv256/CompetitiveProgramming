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
ll pre[MXN] ; 
ll suf[MXN] ; 
int n , m , x, y ; 
int en[31];

ll solve(int x , int y , int m){
	//cout << x << sp << y << sp << m << el ; 
	if (x > y){
		return 0 ; 
	}
	if (m == 0){
		ll sum = 0 ; 
		for(int i = x ; i <= y ; i++){
			sum += a[i]  ; 
			sum %= MOD ; 
		}
		//cout << sum << el ;
		return sum ; 
	}
	
	
	bool b1= (x%2==0) ; 
	bool b2= (y%2==0) ; 
	if (b1&b2){
		if (x == y){
			return (solve(x/2,x/2,m-1)) ; 
		}
		
		ll a2 = 2*solve(x/2,y/2,m-1)%MOD ; 
		ll a3 = solve(x/2+1,y/2-1,m-1)%MOD ; 
		//cout <<  x << sp << y <<sp << m <<  "  EE " << a2+a3 << el ; 
		return (a2+a3)%MOD ; 
	}
	else if ((!b1)&b2){
		ll a1 = solve(x/2,x/2,m-1)%MOD ; 
		ll a2 = 2*solve(x/2+1,y/2,m-1)%MOD ; 
		ll a3 = solve(x/2+1,y/2-1,m-1)%MOD ; 
		//cout << x << sp << y <<sp << m <<   "  OE " << (a1+a2+a3) << el ; 
		return (a1+a2+a3)%MOD ; 
	}
	else if (b1&(!b2)){
		ll a1 = solve(y/2+1,y/2+1,m-1)%MOD ; 
		ll a2 = 2*solve(x/2,y/2,m-1)%MOD ; 
		ll a3 = solve(x/2+1,y/2,m-1)%MOD ; 
		//cout << x << sp << y << sp << m <<   "  EO " << a1+a2+a3 << el ;
		return (a1+a2+a3)%MOD ; 
	}
	else{
		ll a1 = solve(x/2,x/2,m-1)%MOD; 
		ll a2 = solve(y/2+1,y/2+1,m-1)%MOD ; 
		
		ll a3 = 3*solve(x/2+1,y/2,m-1)%MOD ;
		//cout << x << sp << y <<sp <<  m <<  "  OO " << a1+a2+a3 << el ; 
		return (a1+a2+a3)%MOD ; 
	}

}








int main(){
	int t ; sci(t) ; 
	//std::ios_base::sync_with_stdio(0) ; 
	while (t--){
		sci(n) ;sci(m) ; sci(x) ; sci(y) ; x-- ; y-- ; 
		memset(a,0,sizeof(a)) ; 
		memset(pre,0,sizeof(pre)) ; 
		forn(i,n){
			cin >> a[i] ; 
		}
		en[0] = n-1 ; 
		for(int i = 1; i < 31 ; i++){
			en[i] = 2*en[i-1] ; 
		}
		suf[n-1] = a[n-1] ; 
		pre[0] = a[0] ;
		for(int i = 1 ; i < n ; i++){
			pre[i] = (pre[i-1]+a[i])%MOD ; 
		}
		for(int i = n-2 ; i >= 0 ; i--){
			suf[i] = (suf[i+1]+a[i])%MOD ; 
		}
		
		ll ans = solve(x,y,m) ; 
		cout << ans%MOD << el ; 
	}
	return 0 ; 
}





















