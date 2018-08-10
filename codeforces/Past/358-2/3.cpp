#include <bits/stdc++.h>

using namespace std ;
#define ll long long

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<vector<pair<ll,ll> > > vvp ;  
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
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x)
#define MXN 100003

ll vert[MXN] ; 
bool mark[MXN] ; 
vvp adj ; 
ll maxi[MXN] ; 
ll subtree[MXN] ; 

ll dfs(int src,vb& vis){
	ll ret = 1 ;
	vis[src] = true ; 
	for(int i = 0 ; i < adj[src].size() ; i++){
		if (!vis[adj[src][i].xx]){
			if (maxi[src]+adj[src][i].yy > vert[adj[src][i].xx]){
				mark[adj[src][i].xx] = true ; 
				subtree[adj[src][i].xx] = dfs(adj[src][i].xx,vis) ; 
				continue ; 
			}
			maxi[adj[src][i].xx] = max((ll)0,maxi[src]+adj[src][i].yy) ; 
			subtree[adj[src][i].xx] = dfs(adj[src][i].xx,vis) ; 
			ret += subtree[adj[src][i].xx] ;
			
		}
		
	}
	return ret; 
}




int main(){
	ll n ; cin >> n ; 
	memset(vert,0,sizeof(vert)) ;
	memset(subtree,0,sizeof(subtree)) ; 
	memset(mark,false,sizeof(mark));
	memset(maxi,0,sizeof(maxi)) ; 
	
	forn(i,n){
		cin >> vert[i] ; 
	}
	vector<pair<ll,ll> > v ; 
	forn(i,n){
		adj.pb(v) ; 
	}
	int u , cost ; 
	forn(i,n-1){
		cin >> u >> cost ; u-- ; 
		adj[i+1].pb(mp(u,cost)) ; 
		adj[u].pb(mp(i+1,cost)) ; 
	}
	vb vis(n,false) ; 
	subtree[0] = dfs(0,vis) ; 
	ll ans = 0 ;
	
	forn(i,n){
		if (mark[i]){
			ans += subtree[i] ; 
		}
	}
	cout << ans << el ; 
	
}
