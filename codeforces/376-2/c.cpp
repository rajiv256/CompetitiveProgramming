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

bool mark[200003]  ; 
ll sum = 0 ; 
ll maxi = 0 ; 
void dfs(int src, int c[] ,ll cols[],vector<int> adj[], bool vis[]){

	vis[src] = true ;
	cols[c[src]] += 1 ;
	sum += 1 ; 
	if (maxi < cols[c[src]]){
		maxi = cols[c[src]] ; 
	}
	for(int i = 0 ; i < adj[src].size();i++){
		int child = adj[src][i] ; 
		if (!vis[child]){
			dfs(child,c,cols,adj,vis) ; 
		}
	}
	return ; 

}

///////////////////////////////////
int main(){
	ios_base::sync_with_stdio(false) ; 
	cin.tie(0) ; 
	int n , m , k ; 
	cin >> n >> m >> k ; 
	int c[n]; 
	forn(i,0,n){
		cin >> c[i] ;
		c[i]-- ;  
	}
	vi v ; 
	vector<int> adj[n];  
	int l , r ; 
	forn(i,0,m){
		cin >> l >> r ; l-- ; r-- ; 
		adj[l].pb(r) ; 
		adj[r].pb(l) ; 
	}
	ll ans = 0 ;
	bool vis[n] ; 

	if (m == 0){
		cout << ans << el ; 
		return 0 ; 
	}
	forn(i,0,n){
		if (!vis[i]){
			ll cols[k] ; 
			memset(cols,0,sizeof(cols)) ; 
			sum = 0 ; 
			maxi = 0; 
			
			dfs(i,c,cols,adj,vis) ;
		 	
			ans += sum-maxi ; 

		}
	}	
	cout << ans << el ; 
}