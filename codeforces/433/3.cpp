
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
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define YES "YES\n"
#define NO "NO\n"


int main(){

	cin.tie(0); 
	ios_base::sync_with_stdio(false) ; 

	ll n , k ; cin >> n >> k ; 
	ll cost[n+1] ; 
	forn(i,1,n+1){
		cin >> cost[i] ; 
	}
	vector<pair<ll,ll> > v; 
	forn(i,1,n+1){
		v.pb(mp(cost[i],i)) ; 
	}
	
	priority_queue<pair<ll,ll> > pq ;

	for(int i = 1 ; i <= k ; i++){
		pq.push(mp(cost[i],i)) ; 
	}
	ll ans = 0 ;
	int findings[n+1] ; 

	for(int i = k+1 ; i <= n+k ; i++){
		if (i <= n ){
			pq.push(mp(cost[i],i)) ; 
		}
		pair<ll,ll> p = pq.top() ; 
		pq.pop() ; 
		findings[p.yy] = i ; 
		ans += p.xx*(i-p.yy) ; 

	}
	cout << ans <<el ; 
	for(int i = 1 ; i <= n ; i++){
		cout << findings[i] << sp ; 
	}
	cout << el; 









}