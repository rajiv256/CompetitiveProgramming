#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std ;
typedef vector<int> vi ; 
typedef vector<pair<int,int> > vp ; 
typedef vector<bool> vb ; 

#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define INF 1000000
int wt[3001][3001] = {0} ; 


int minKey(vi& key, vb& mSet){
	int min = INF ; int minI ; int n = key.size() ; 
	for (int i = 0 ; i < n ; i++){
		if (mSet[i] == false){
			if (min > key[i]){
				min = key[i] ; 
				minI = i ; 
			}
		}
	}
	return minI ; 
}




int prim(int s , vvi& adj , int n){
	vi parent(n,-1) ; 
	vi key(n,INF) ; 
	vb mSet(n,false) ; 
	key[s] = 0 ; parent[s] = -1 ; 
	int d = 0 ; 
	int cnt = 0 ; 
	while (cnt < n ){
		int s = minKey(key,mSet) ; 
		cnt += 1 ; 
		mSet[s] = true ; 
		d += key[s] ; 

		for (int i = 0 ; i < adj[s].size() ; i++){
			if (mSet[adj[s][i]] == false && wt[s][adj[s][i]] < key[adj[s][i]]){
				key[adj[s][i]] = wt[s][adj[s][i]] ; 
				
 			}
		}
	}
	return d ; 
}







int main() {
	int n , m ; cin >> n >> m ; 
	vi v ; vvi adj(n,v) ; 
	int a , b , w  ;
	while (m--){
		cin >> a >> b >> w ; a-- ; b-- ; 
		adj[a].push_back(b) ; 
		adj[b].push_back(a) ; 
		wt[a][b] = w ; 
		wt[b][a] = w ; 
	}
	int s ; cin >> s ; s-= 1 ;

	vi parent(n,-1) ; 
	vb vis(n,false) ; 
	int d = prim(s,adj,n) ; 
	cout << d << endl ;
	return 0 ; 
}
