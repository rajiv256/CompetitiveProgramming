
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
#define maxn (int)1e6+9

int n , m , k ; 
ll tca[maxn] ; 
ll na[maxn] ; 
ll tcd[maxn] ; 
ll nd[maxn] ;

ll d , f , t , c ; 

// t --> Total. a --> Arrival  d--> Departure. c---> Cost 

int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false); 

	cin >> n >> m >> k ; 
	map<ll,vector<pair<ll,ll> > > arr; 
	map<ll,vector<pair<ll,ll> > > dep;
	ll MAX_DAYS = 0 ; 
	while (m--){
		cin >> d >> f >> t >> c ; 
		MAX_DAYS = max(MAX_DAYS,d) ; 
		if (f == 0){
			dep[d].pb(mp(c,t)) ; 
		}
		else{
			arr[d].pb(mp(c,f)) ; 
		}
	} 
	clr(tca) ; 
	clr(na) ; 
	clr(tcd) ; 
	clr(nd) ; 
	map<ll,ll> minCA ;
	map<ll,ll> minCD ;
	for(int i = 1 ; i <=(1e6+2) ; i++){    // Total of n - days 
		na[i] = na[i-1] ; 
		tca[i] = tca[i-1] ; 
		if (arr[i].size()!=0){
			for(int j = 0 ; j < arr[i].size() ; j++){
				pair<ll,ll> p = arr[i][j] ; 
				ll cost = p.xx ; 
				ll from = p.yy ; 

				if (minCA[from]==0){
					minCA[from] = cost ; 
					na[i]++ ; 
					tca[i] += cost ; 
				}
				else{
					tca[i] -= minCA[from] ; 
					cost = min(minCA[from],cost) ; 
					minCA[from] = cost ; 
					tca[i] += cost ; 
				}
			}
		}
	} 
	for(int i = (1e6+2) ; i > 0 ; i--){
		nd[i] = nd[i+1] ; 
		tcd[i] = tcd[i+1] ; 
		if (dep[i].size()!=0){
			for(int j = 0 ; j < dep[i].size() ; j++){
				pair<ll,ll> p = dep[i][j] ; 
				ll cost = p.xx ; 
				ll to   = p.yy ; 

				if (minCD[to]==0){
					nd[i]++ ; 
					tcd[i] += cost ; 
					minCD[to] = cost ; 
				}
				else{
					tcd[i] -= minCD[to] ; 
					cost = min(minCD[to],cost) ; 
					minCD[to] = cost ; 
					tcd[i] += cost ; 
				}
			}
		}
	}
	ll mincost = (1LL<< 50) ; 
	int fl = 0 ; 
	for(int i = 1 ; i <= MAX_DAYS ; i++){
		
		if (na[i-1]==n && nd[i+k]==n){
			fl = 1 ; 
			mincost = min(mincost,tca[i-1]+tcd[i+k]) ; 
		}
	}
	if (fl == 0){
		cout << "-1" << el ; 
	}
	else{
		cout << mincost << el ; 
	}
	return 0 ; 

}

