
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

double exp(int src, vvi& adj, vb& vis){
	vis[src] = true ; 
	double ret = 0 ; 
	double cnt = 0 ; 

	for(int i = 0 ; i < adj[src].size() ; i++){
		int child = adj[src][i] ; 
		if (!vis[child]){
			ret += 1+exp(child,adj,vis) ; 
			cnt++ ; 
		}
	}
	if (cnt == 0) 
		return 0.0 ; 

	return ret/cnt ; 

}

int main(){
	int n ; sci(n) ; 
	vi v ; vvi adj(n,v) ; int u ,x ; 
	vb vis(n,false) ; 
	forn(i,0,n-1){
		sci(u) ; sci(x) ; u-- ; x-- ; 
		adj[u].pb(x) ; 
		adj[x].pb(u) ; 
	}
	double ans = exp(0,adj,vis) ; 
	printf("%.7f\n",ans );

	return 0 ; 
}


































