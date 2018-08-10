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

#define N 50005 

int par[2][N] ; 
int anc[2][N] ;  
int dist[2][N] ;
int depth[2][N] ;  
int maxdepth[2] ; 

void dfs(int src, vvp& adj , vb& vis, int d, int dep, int fl){
	vis[src] = true ; 
	
	dist[fl][src] = d ; 
	depth[fl][src] = dep ; 
	maxdepth[fl] = max(maxdepth[fl],dep) ; 

	for(int i = 0 ; i < adj[src].size() ; i++){
		int ch = adj[src][i].xx ; 
		int cost = adj[src][i].yy ;
		if (!vis[ch]) {
			par[fl][ch] = src ; 
			dfs(ch,adj,vis,cost+d,dep+1,fl) ; 
		}
	}
	return ; 
}

void DFS(int src, vvp& adj, vb& vis, int fl , int Nr){
	vis[src] = true ; 
	if (depth[fl][src]%Nr == 0){
		anc[fl][src] = par[fl][src] ; 
	}
	else{
		anc[fl][src] = anc[fl][par[fl][src]] ; 
	}

	for(int i = 0 ; i < adj[src].size() ; i++){
		int ch = adj[src][i].xx ; 

		if (!vis[ch]){
			DFS(ch,adj,vis,fl,Nr) ; 
		}
	}
	return ; 
}

int lca(int x , int y, int fl){
	while (anc[fl][x]!=anc[fl][y]){
		if (depth[fl][x] < depth[fl][y]){
			y = anc[fl][y] ; 
		}
		else{
			x = anc[fl][x] ; 
		}
	}
	while (x != y){
		if (depth[fl][x] < depth[fl][y]){
			y = par[fl][y] ; 
		}
		else{
			x = par[fl][x] ; 
		}
	}
	return x ; 
}



int main(){
	int t ; sci(t) ; 
	while (t--){
		int n ; sci(n); 
		vp v ; 
		vvp adj1(n,v) ; 
		vvp adj2(n,v) ; 

		forn(i,0,n-1){
			int u , v , c ; 
			sci(u) ; sci(v) ; sci(c) ; u-- ; v-- ; 
			adj1[u].pb(mp(v,c)) ; 
			adj1[v].pb(mp(u,c)) ; 
		}
		forn(i,0,n-1){
			int u , v , c ; 
			sci(u) ; sci(v) ; sci(c) ; u-- ; v-- ; 
			adj2[u].pb(mp(v,c)) ; 
			adj2[v].pb(mp(u,c)) ; 
		}

		vb vis(n,false) ; //par[0][0] = -1 ; 
		dfs(0,adj1,vis,0,0,0)  ; 
		forn(i,0,n) vis[i] = false ; 
		dfs(0,adj2,vis,0,0,1) ;

		forn(i,0,n) vis[i] = false ; 
		DFS(0,adj1,vis,0,sqrt(maxdepth[0])+1) ; 

		forn(i,0,n) vis[i] = false ; 
		DFS(0,adj2,vis,1,sqrt(maxdepth[1])+1) ; 
		

		ll ans = 0 ; 

		for(int i= 0 ; i < n; i++){
			for(int j = i+1 ; j < n ; j++){

				ll lca1 = lca(i,j,0) ; 
				ll lca2 = lca(i,j,1) ; 
				ll cd = dist[0][i]+dist[0][j]-2*dist[0][lca1] ; 
				ll fd = dist[1][i]+dist[1][j]-2*dist[1][lca2] ; 

				ans += min(cd,fd) ;  
			}
		}
		printf("%lld\n", ans);


	}

	return 0 ; 
}

















