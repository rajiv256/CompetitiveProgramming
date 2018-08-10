

#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
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
#define ll long long
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
//#define sci(x) scanf("%d",&x)
#define MXN 100003
#define gc getchar_unlocked	

void sci(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

void dijkstra(vector<std::vector<pair<int,int> > >& adj , int src , vb& vis, int dist[] , int n){
	priority_queue<pair<int,int> > pq ; 
	pq.push(mp(0,src)) ; 
	dist[src] = 0 ; 
	while (!pq.isEmpty()){
		pair<int,int> p = pq.top() ; 
		pq.pop() ; 
		src = p.yy ; 
		int wt = p.xx ;
		dist[src] = wt ;  
		for(int i = 0 ; i < adj[p.yy].size() ; i++){
			if (!vis[adj[src][i].yy]){
				if (wt+adj[src][i].xx > dist[adj[src][i].yy]){
					dist[adj[src][i].yy] = wt+adj[src][i].xx ; 
				}
			}
		}


	}
}







int main(){
	int n ; sci(n)  ; 
	vector<std::vector<pair<int,int> > > adj; 
	std::vector<pair<int,int> > v;
	adj(n,v) ; 
	int a , b ,x; 
	forn(i,n){
		sci(a) ;sci(b) ; sci(x) ;  
		adj[a].pb(mp(x,b)) ;
		adj[b].pb(mp(-x,b)) ; 
	}	


}