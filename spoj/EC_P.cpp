#include <iostream>
#include <vector>
#include <cmath> 
#include <cstring> 
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> low , tin ; 

void dfs(int s, int par, vector<vector<int> >& adj, vector<bool>& vis, vector<pair<int,int> >& ans, int time){
	vis[s] = true ; 
	tin[s] = time ; 
	low[s] = tin[s] ; 
	
	for(auto ch: adj[s]){
		if (ch == par) continue ; 
		if (vis[ch] && ch != par){
			low[s] = min(low[s], low[ch]) ; 
		}
		else{
			dfs(ch, s, adj, vis, ans, (time+1)) ; 
			low[s] = min(low[s], low[ch]) ; 
			if (tin[s] < low[ch]){
				int m = min(s, ch) ; 
				int M = max(s, ch) ; 
				ans.push_back(make_pair(m+1, M+1)) ; 
			}
		}
	}
	return ;
}

void solve(vector<vector<int> >& adj){
	vector<bool> vis(adj.size(),false) ;
	vector<pair<int,int> > ans ; 
	low = vector<int>(adj.size(), -1) ; 
	tin = vector<int>(adj.size(), -1) ; 
	for(int i = 0 ; i < adj.size(); i++){
		if (!vis[i]){
			dfs(i, -1, adj, vis, ans, 0) ; 
		}
	}
	if (ans.size() == 0){
		cout << "Sin bloqueos" << endl ; 
		return ; 
	}
	sort(ans.begin(), ans.end()) ; 
	cout << ans.size() << endl  ;
	for(auto it: ans){
		cout << it.first << " " << it.second << endl ; 
	}
	return ; 
	
}


int main() {
	int T ; cin >> T ; 
	int iter = 1 ; 
	
	while (T--){
		int V, E ; cin >> V >> E ; 
		vector<vector<int> > adj(V, vector<int>()) ; 
		
		for(int i = 0 ; i < E ; i++){
			int x ,y ; cin >> x >> y ;  x-- ; y-- ;
			adj[x].push_back(y) ; 
			adj[y].push_back(x) ; 
		
		}
		cout << "Caso #" << iter << endl ; 
		solve(adj) ; 
		iter += 1 ; 
	}
	return 0;
}
