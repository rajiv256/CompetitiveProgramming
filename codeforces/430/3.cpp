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



#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define YES "YES\n"
#define NO "NO\n"

int parent[2*MXN+5] ; 
int a[2*MXN+5] ; 

int gcdtill[2*MXN+5] ; 

int res[2*MXN+5]; 


int gcd(int a, int b){
	if (a < b) return gcd(b,a) ; 

	if (b == 0){
		return a ; 
	}

	return gcd(b,a%b) ; 
}

void dfsfp(int src, vector<bool>& vis, vector<vector<int> > & adj){

	vis[src] = true ; 
	for(int i = 0 ; i < adj[src].size() ; i++){
		if (!vis[adj[src][i]]){
			parent[adj[src][i]] = src ; 
			gcdtill[adj[src][i]] = gcd(gcdtill[src],a[adj[src][i]]) ; 
			dfsfp(adj[src][i], vis , adj) ; 
		}
	}

	return ; 

}


void dfs(int src, vector<bool>& vis ,vector<vector<int> > & adj, set<int>& ZoO ){
	
	vis[src] = true ; 

	set<int> newZoO  ; 
	int maxi = 0 ; 

	newZoO.insert(gcdtill[src]) ; 

	for(set<int> :: iterator it = ZoO.begin() ; it != ZoO.end() ; it++){
		newZoO.insert(gcd(a[src],*it)) ; 
	}
	
	if (src == 0)  newZoO.insert(0) ; 
	else newZoO.insert(gcdtill[parent[src]]) ; 
	

	for(set<int> :: iterator it = newZoO.begin() ; it != newZoO.end() ; it++){
		maxi = max(maxi,*it) ; 
	}
	
	res[src] = maxi ; 


	for(int i = 0 ; i < adj[src].size() ; i++){
		int child = adj[src][i] ; 
		if (!vis[child]){
			dfs(child,vis,adj,newZoO) ; 
		}
	}
	return ; 
	
}





int main(){

	int n ; cin >> n ; 
	forn(i,0,n){ cin >> a[i] ; } 

	vector<int> v ; 
	vector<vector<int> >  adj(n,v) ;
	int x , y ; 
	forn(i,0,n-1){
		cin >> x >> y ; x-- ; y-- ; 
		adj[x].pb(y) ; 
		adj[y].pb(x) ; 
	}

	vector<bool> vis(n,false) ; 
	parent[0] = -1 ; 
	gcdtill[0] =  a[0] ; 
	dfsfp(0,vis,adj) ; 

	forn(i,0,n) { vis[i] = false ; }

	set<int> ZoO ; 
	 
	  	
	
	dfs(0,vis,adj,ZoO) ; 

	for(int i = 0 ; i < n ; i++) cout << res[i] << " " ; 


	return 0 ; 



}