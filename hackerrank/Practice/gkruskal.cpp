#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std ;
typedef vector<int> vi ; 
typedef vector<pair<int,int> > vp ; 
typedef vector<pair<int,pair<int,int> > > vpp ; 
typedef vector<bool> vb ; 

#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> > 
#define INF 1000000

int graph[3001][3001] = {0} ; 
bool path[3001][3001] = {false} ; 

bool cycle(pp ewt,int n){
	int s = ewt.second.first ; int dst = ewt.second.second  ;
	int dup = s  ; vb vis(n,false) ;  
	queue<int> q ; q.push(dup) ; 
	while (!q.empty()){
		dup = q.front() ; 
		if (dup == dst){
			return true ; 
		}
		forn(i,n){
			if (!vis[i] && graph[dup][i] == 1){
				q.push(i) ; 
			}
		}
		vis[dup] = true ; 
		q.pop() ; 
	}
	return false  ; 

}

void floydWarshall(int n){
	forn(k,n){
		forn(i,n){
			forn(j,n){
				path[i][j] = (path[i][j] || (path[i][k] && path[k][j])) ;  
			}
		}
	}
	return ; 
}

int find(vi& parent,int x){
	if (parent[x] == -1){
		return x ; 
	}
	return find(parent,parent[x]) ; 
}
void union_(vi& parent, int x , int y){
	int xset = find(parent,x) ; 
	int yset = find(parent,y) ; 
	parent[xset] = yset ; 
	
}






int kruskal(int s , vvi& adj ,vpp& edges, int n){
	int d = 0 ; 
	/*forn(i,n){
		forn(j,n){
			path[i][j] = graph[i][j] ; 
		}
	}*/
	vi parent(n,-1) ; 
	int cnt = 0 ; 
	for (int i = 0 ; i < edges.size() ; i++){
		if (cnt == n-1){
			break ; 
		}
		int u = find(parent,edges[i].second.first)  ; 
		int v = find(parent,edges[i].second.second) ; 
		if (u != v || (u == v && u == -1)){
			cnt += 1 ; 

			d += edges[i].first ; 
			/*graph[edges[i].second.first][edges[i].second.second] = 1 ;
			graph[edges[i].second.second][edges[i].second.first] = 1 ;
			*/
			//path[edges[i].second.first][edges[i].second.second] = true ; 
			//path[edges[i].second.second][edges[i].second.first] = true ; 
			//floydWarshall(n) ; 
			
			union_(parent,u,v) ; 
		}
	}
	return d ; 
}





int main() {
	int n , m ; cin >> n >> m ; 
	vi v ; vvi adj(n,v) ; 
	int a , b , w  ; vpp edges ; 
	while (m--){
		cin >> a >> b >> w ; a-- ; b-- ; 
		adj[a].push_back(b) ; 
		adj[b].push_back(a) ; 
		/*
		wt[a][b] = w ; 
		wt[b][a] = w ; 
		*/
		edges.push_back(make_pair(w,make_pair(a,b))) ; 
	}
	int s ; cin >> s ; s-= 1 ;
	int graph[n][n] ; 
	forn(i,n) {
		forn(j,n){
			graph[i][j] = 0 ; 
		}
	}
	sort(edges.begin(),edges.end()); 
	vi parent(n,-1) ; 
	vb vis(n,false) ; 
	int d = kruskal(s,adj,edges,n) ;  
	cout << d << endl ;
	return 0 ; 
}
