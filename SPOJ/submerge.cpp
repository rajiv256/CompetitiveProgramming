#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>

using namespace std ; 

vector<int> tin, low ; 

void dfs(int src, int par, int time, vector<vector<int> >& adj, 
	vector<bool>& vis, vector<int>& ans){
		
		vis[src] = true ; 
		tin[src] = time ;
	  	low[src] = tin[src] ; 
		int children = 0 ; 
		for (auto ch: adj[src]){
			if (par ==ch) continue ; 
			
			if (par != ch && vis[ch]){
				low[src] = min(low[src], tin[ch]) ; 
			}
			else{
				dfs(ch, src, time+1, adj, vis, ans) ; 
				low[src] = min(low[src], low[ch]) ; 
				
				if (par != -1 && tin[src] <= low[ch]){
					ans.push_back(src) ; 
				}
				++children ; 
			
			}
		}
		if (par == -1 && children > 1){
			ans.push_back(src) ; 
		}
	}
	
void printv(vector<int> v){
	for(auto ch: v){
		cout << ch << " " ; 
	}
	cout << endl ; 
}

void solve(vector<vector<int> >& adj){
	int N = adj.size() ; 
	low = vector<int>(N, -1) ; 
	tin = vector<int>(N, -1) ; 
	vector<bool> vis(N, false) ; 
	vector<int> ans ; 
	
	for (int i = 0 ; i < N ; i++){
		if (!vis[i]){
			dfs(i, -1, 0, adj, vis, ans) ; 
		}
	}
	set<int> ss = set<int>(ans.begin(), ans.end()) ; 
	cout << ss.size() << endl ; 
}

int main(){
	while (true){
		int N, M ; cin >> N >> M ; 
		if (N == 0 && M == 0) break ; 
		
		vector<vector<int> > adj(N, vector<int>()) ; 
		for(int i = 0 ; i < M ; i++){
			int x , y ; cin >> x >> y ; x-- ; y-- ; 
			adj[x].push_back(y) ; 
			adj[y].push_back(x) ; 
		}
		solve(adj) ; 
		
	}
}
