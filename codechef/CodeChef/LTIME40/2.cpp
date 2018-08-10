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

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef std::vector<std::vector<int> > vvi;
typedef unsigned long long ull ;
#define pb push_back
#define mp make_pair

ll a[MXN] ; 
ll ug[MXN] ; 

void dfs(int src,vvi& adj,vb& vis){
	int parent = src ; 
	vis[src] = true ;  
	if (adj[parent].size()==0){
		ug[parent] = a[parent] ;
		return ;  
	}
	ll ret = -1 ; 
	forn(i,0,adj[src].size()){
		int child = adj[src][i] ; 
		if (vis[child]){
			continue ; 
		}
		dfs(child,adj,vis) ; 
		ret = max(ret,a[parent]^ug[child]) ; 
	}
	ug[parent] = ret ; 
	return ; 
}



int main(){
	int T ; cin >> T ; 
	while (T--){
		clr(a) ; 
		clr(ug) ; 
		int N ; cin >> N ; 
		vi v ; vvi adj(N,v) ; 
		forn(i,0,N){
			cin >> a[i] ; 
		}
		int u , x; 
		forn(i,0,N-1){
			cin >> u >> x ; u-- ; x-- ; 
			adj[u].pb(x) ; 
			adj[u].pb(x) ; 
			
		}
		vb vis(N,false) ; 
		dfs(0,adj,vis) ; 
		
		forn(i,0,N){
			cout << ug[i] << el ; 
		}
	}
}