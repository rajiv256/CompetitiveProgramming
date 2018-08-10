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


int parent[MXN] ; 
ll deg[MXN] ; 
vi v1,v2 ; 

int find(int x){
	if (parent[x]==-1){
		return x ; 
	}
	return find(parent[x]) ; 
}

void Union(int x, int y){
	int xx = find(x) ; 
	int yy = find(y) ; 
	parent[xx] = parent[yy] ; 
}
void dfs(int src, vvi& adj , vb& vis, int fl){
	vis[src] = true ; 
	if (fl == 0){
		v1.pb(src) ; 
	}
	else{
		v2.pb(src) ; 
	}

	for(int i= 0 ;i < adj[src].size() ; i++){
		int ch = adj[src][i] ; 
		if (!vis[ch]){
			dfs(ch,adj,vis,(fl+1)%2) ; 
		}
	}
	return ; 
}



int main(){
	memset(parent,-1,sizeof(parent)) ; 
	memset(deg,0,sizeof(deg)) ; 
	
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 
	int n ; int x, y ; 
	cin >> n ; 

	vi v ; vvi adj(n,v) ; 
	vb vis(n,false) ; 

	forn(i,0,n-1){
		cin >> x >> y ; x-- ; y-- ; 
		adj[x].pb(y) ; 
		adj[y].pb(x) ; 
	}
	forn(i,0,n){
		deg[i] = adj[i].size() ; 
	}
	dfs(0,adj,vis,0) ; 
	ll ans = 0 ; 
	for(int i= 0 ; i < v1.size() ; i++){
		ans += (ll)v2.size()-(ll)deg[v1[i]] ; 
	}
	cout << ans << el ; 


}






























