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

int n , m , q; 

int gs(int l , int r){
	int sz = r-l+1 ; 
	if (sz%2==0){
		return 0 ; 
	}
	if (l%2==0){
		return -1 ; 
	}
	return 1 ; 
}

int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 

	cin >> n >> m >> q ; 
	ll a[n+1] ; 
	ll b[m+1] ; 
	forn(i,0,n){
		cin >> a[i+1] ; 
	}
	forn(i,0,m){
		cin >> b[i+1] ; 
	}
	for(int i = 1 ; i <= m ; i++){
		if (i%2==1){
			b[i] = -b[i] ; 
		}
	}
	vector<ll> s; ll x = 0 ; 
	ll bval = 0 ; 
	for(int i = 1 ; i <= n ; i++){
		bval += b[i] ; 
	}
	s.pb(bval) ; 
	for(int i = 2 ; i <= m-n+1 ; i++){
		bval -= b[i-1] ; 
		bval += b[i+n-1]  ; 
		if (i%2==0){
			s.pb(-bval) ; 	
		}
		else{
			s.pb(bval) ; 
		}
	}
	
	sort(all(s)) ; 
	
	ll asum = 0 ; x = 1 ; 
	forn(i,1,n+1){
		asum += x*a[i] ; 
		x *= -1 ; 
	}
	
	int l, r ; ll val,ans ; 
	ll x1 = lower_bound(all(s),-asum)-s.begin()  ;
	ll x2 = lower_bound(all(s),-asum)-s.begin()-1 ; 
	x1 = min((ll)s.size()-1,x1) ; 
	x2 = max((ll)0,x2) ; 
	ans = min(abs(asum+s[x1]),abs(asum+s[x2])) ; 

	cout << ans << el ; 
	while (q--){
		cin >> l >> r >> val ;
		asum += gs(l,r)*val ; 
		x1 = lower_bound(all(s),-asum)-s.begin()  ;
		x2 = lower_bound(all(s),-asum)-s.begin()-1 ; 
		x1 = min((ll)s.size()-1,x1) ; 
		x2 = max(0LL,x2) ; 
		ans = min(abs(asum+s[x1]),abs(asum+s[x2])) ; 
		cout << ans << el ; 
	}
	





























}



























































