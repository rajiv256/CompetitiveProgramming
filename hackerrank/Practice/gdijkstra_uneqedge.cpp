#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>

using namespace std ;

typedef vector<int> vi ; 
typedef vector<bool> vb ; 

#define forn(i,n) for(int i = 0 ; i < n ; i++)
#define INF 1E9 
#define vvi vector<vector<int> > 
#define EDGE 6 

int wt[3000][3000] ={0} ; 
struct edge {
	pair<int,int> p ;  int w ; 

	/*bool operator== (const edge& e) const
	{
		if (e.w == w){
			if ((p.first == e.first && p.second == e.second) && (p.first == e.second && p.second == e.first))
				return true ; 
		}
		return false ; 
	}*/
	bool operator< (const edge& e) const
	{
		if (w < e.w){
			return true ; 
		}
		return false ; 
	}

} ; 

pair<int,pair<int,int> > make(int w , int src ,int dest){
	pair<int,pair<int,int> > p ;  
	p.first = w ;  
	p.second.first = src ; 
	p.second.second = dest ; 
	return p ; 
}

void pt (vector<pair<int,pair<int,int> > > p){
	forn(i,p.size()){
		cout << "( " << p[i].first << " " << p[i].second.first << "-" << p[i].second.second << ")  " ; 
	}
	cout << endl ; 
}








int main() {

	int t ; cin >> t ; 
	while (t--){
		int n , m ; cin >> n >> m ; 
		memset(wt,0,sizeof(int)*3000*3000) ; 
		vi v ; 
		vvi adj(n,v) ;
		
		int a , b ,w; 
		while (m--){
			cin >> a >> b >> w ; a-- ; b--; 
			adj[a].push_back(b) ; 
			adj[b].push_back(a) ; 
			
			wt[a][b] = w ; wt[b][a] = w ; 
		} 
		forn(i,n){
			forn(j,n){
				cout << wt[i][j] << " " ; 
			}
			cout << endl ; 
		}
		int s ; cin >> s ; s-= 1 ; 
		
		vi dist(n,INF) ; 
		vi parent(n,-2) ; 
		vb visited(n,false) ; 
		dist[s] = 0 ; 
		
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
