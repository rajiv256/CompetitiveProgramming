#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std ;

typedef vector<int> vi ; 
typedef vector<bool> vb ; 

#define forn(i,n) for(int i = 0 ; i < n ; i++)
#define INF 1E9 
#define vvi vector<vector<int> > 
#define EDGE 6 

void dijkstra(int s,vvi& adj , vi& dist,vi& parent,vb& visited){

	
	queue<int> q ; 
	q.push(s) ; 
	while (!q.empty()){
		s = q.front() ; 
		forn(i,adj[s].size()){
			if (!visited[adj[s][i]]){
				 
				if (dist[s]+EDGE < dist[adj[s][i]]){
					q.push(adj[s][i]) ;
					dist[adj[s][i]] = dist[s] + EDGE ; 
					parent[adj[s][i]] = s ;
				}
				 

			}
		}
		q.pop() ; 
		visited[s] = true ; 

	}







	








}







int main() {

	int t ; cin >> t ; 
	while (t--){
		int n , m ; cin >> n >> m ; 
		vi v ; 
		vvi adj(n,v) ;
		int a , b ; 
		while (m--){
			cin >> a >> b ; a-- ; b--; 
			adj[a].push_back(b) ; 
			adj[b].push_back(a) ; 
		} 
		int s ; cin >> s ; s-= 1 ; 
		vi dist(n,INF) ; 
		vi parent(n,-2) ; 
		vb visited(n,false) ; 
		dist[s] = 0 ; 
		dijkstra(s,adj,dist,parent,visited) ; 
		forn(i,n){
			if (i == s){
				continue ; 
			}
			if (dist[i] == INF){
				cout << "-1 " ;
			}
			else {
				cout << dist[i] << " "; 	
			}
		}	
		cout << endl ; 
	}
	
	return 0 ; 





}
