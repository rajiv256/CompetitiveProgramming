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
typedef vector<vector<int> > vvi  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;
#define pb push_back
#define mp make_pair


int height[10004] ; 
int dist[10004] ; 

int dfs(int src , vvi& adj ,vb& vis){
	int h = 0  ; 
	vis[src] = true ; 
	for(int i = 0 ; i < adj[src].size() ; i++){
		int ch = adj[src][i] ; 
		if (!vis[ch]){
			height[ch] = dfs(ch,adj,vis) ; 
			h = max(h,1+height[ch]) ; 
		}
	}
	return h ; 
}

int diam(int src , vvi& adj, vb& vis){
	int d = 0 ; 
	int hl = -1 , hr = -1 ; 
	vis[src] = true ;  
	for(int i = 0 ; i < adj[src].size() ; i++){
		int ch = adj[src][i] ;
		////cout << ch  << vis[ch<< el ; 
		if (!vis[ch]){
			int d1 = diam(ch,adj,vis) ; 
			vi v ; v.pb(hl) ;v.pb(hr) ;v.pb(height[ch]) ; 
			sort(all(v)) ; 
			
			hl = v[1] ; hr = v[2] ; 
			d = max(d1,2+hl+hr) ; 
		}
	}
	return d ;
}


int main(){
	int n ; sci(n) ; 
	vi v ; vvi adj(n,v) ; 
	int x , y ; 
	for(int i = 0 ; i < n-1 ; i++){
		sci(x) ; sci(y) ; x-- ;  y--; 
		adj[x].pb(y) ; 
		adj[y].pb(x) ; 
	}
	vb vis(n,false) ; 
	////cout << "here" << el ; 
	
	height[0] = dfs(0,adj,vis) ;

	
	for(int i= 0 ; i < n ; i++){
		vis[i] = false ; 
	}

	int di = diam(0,adj,vis) ; 
	printf("%d\n",di) ; 

}