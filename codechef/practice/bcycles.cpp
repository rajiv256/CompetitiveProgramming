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



bool dfs(int src, int dest , vvi& adj, vb& vis){
	
	if (src == dest){
		return true ; 
	}
	vis[src] = true ; 
	bool b = false ; 
	for(int i = 0 ; i < adj[src].size() ; i++){
		int ch = adj[src][i] ; 
		if (!vis[ch]){
			b |= dfs(ch,dest,adj,vis); 
			if (b) return true ; 
		}
	}
	return b ; 
}



int main(){

	int t; sci(t) ; 
	while (t--){
		int n ; sci(n) ; 
		vi v ; vvi adj(n,v) ; 
		int x , y ; 
		forn(i,0,3*n/2){
			sci(x) ; sci(y) ; x-- ; y-- ; 
			adj[x].pb(y) ; adj[y].pb(x) ; 
		}
		vvi cycles ; 
		for(int i = 0 ; i < n ; i++){
			 
			vi cycsz ; 									
			for(int j = 0 ; j < 3 ; j++){
				vb vis(n,false) ; vis[i] = true ;
				
				for(int k = j+1; k < 3 ; k++){
					int np = 0 ; 
					while (dfs(j,k,adj,vis)){
						np++ ;
						vis[j] = false ;  
					}
					cycsz.pb(np); 
				}
			}

			cycles.pb(all(cycsz)) ; 

		}
		
	}




}