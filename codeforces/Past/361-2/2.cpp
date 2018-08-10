#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> >
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >
#define pii pair<int,int>
#define INF 1000000000
#define sp " "
#define el "\n"
#define lld long long int
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define sci(x) scanf("%d",&x)
#define mp make_pair
#define ll long long
 
int mod(int a ){
	if (a < 0)
		return -a ; 
	return a ; 
}
int parent[2000009] ; 

void printQ(priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > >  q){
	while (!q.empty()){
		cout << "(" << q.top().yy << "," << q.top().xx << ")"  << sp ; 
		q.pop() ; 
	}
	cout << el ; 
}




void bfs(int src , vb& vis , vvp& adj, int dist[]){
   queue<pair<int,int> > q ; 
	q.push(mp(0,src)) ; int wt = 0 ; 
	dist[src] = 0 ; 
	while (!q.empty()){
		
		src = q.front().yy ; 
		wt  = q.front().xx ;
		//printQ(q) ; 
		dist[src] = min(dist[src],wt) ; 
		q.pop() ;
		
		vis[src] = true ;  
		//cout << src << sp << wt << el ; 

		for (int i = 1 ; i <= n ; i++){
			if (vis[i]){
				continue ; 
			}
			q.push(mp(wt+adj[src][i].yy,adj[src][i].xx)) ;  
		}
		
		 
	}
}





int main(){

	int n ; cin >> n ; 
	vp v ; 
	vvp adj(n+1,v) ; 
	int x ; 
	forn(i,n){
		cin >> x ; 
		parent[i+1] = x ;
		adj[i+1].pb(mp(x,1)) ;
	}

	for(int i =1 ; i <= n ; i++){
		for(int j = i+1 ; j <= n ; j++){
			if (parent[i]==j){
				adj[j].pb(mp(i,mod(i-j))); 
			}
			else{
				adj[i].pb(mp(j,mod(i-j))) ; 
				adj[j].pb(mp(i,mod(i-j))) ; 
			}
		}
	}
	// for(int i = 1 ; i  <= n ; i++){
	// 	for(int j = 0 ; j < adj[i].size() ; j++){
	// 		cout << "(" << adj[i][j].xx << "," << adj[i][j].yy << ")" << sp ; 
	// 	}
	// 	cout << el ; 
	// }
	 
	int dist[n+1] ; 
	

	for(int i = 1; i <= n ; i++){
		dist[i] = INF ; 
	}
	vb vis(n+1,false) ; 
	bfs(1,vis,adj,dist) ; 


	for(int i = 1 ; i <= n ; i++){
		cout << dist[i] << sp ; 
	}
	cout << el ; 
	return 0 ; 
	
}