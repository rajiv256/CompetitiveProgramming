// Hello from the other side.
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdlib.h> 

using namespace std ;
#include <bits/stdc++.h> 
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
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp " " 
#define el "\n"
#define lld long long int 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
 


void dfs(int chef ,vvi& adj, vi& parent, vb& vis){
	
	vis[chef] = true ; 
	for (int i = 0 ; i < adj[chef].size() ; i++){
			
		if (!vis[adj[chef][i]]){
			parent[adj[chef][i]] = chef ; 
			dfs(adj[chef][i],adj,parent,vis) ; 	
		}
	}

}

int find(vi& parent , int x){
	if (parent[x] == -1){
		return x ; 
	}
	return find(parent,parent[x]) ; 
}

void Union(vi& parent, int x , int y){
	int xset = find(parent,x) ; 
	int yset = find(parent,y) ; 

	parent[yset] = xset ; 
	return ; 
}

int main(){
	int n , k ; cin >> n >> k ; 
	int b ; cin >> b ; b-- ; 
	vi v ; vvi adj(n,v) ; 
	
	
	int a1 , a2 ; 
	forn(i,n-1)	{
		cin >> a1 >> a2 ; a1-- ; a2-- ; 
		adj[a1].push_back(a2) ; 
		adj[a2].push_back(a1) ; 
		//d[a1][a2] = 1 ; d[a2][a1] = 1 ;


	}
	vi f ; f.rsz(n) ; 
	forn(i,n){
		int temp ; 
		cin >> temp ;
		f[i] = temp -1 ; 
	}


	vi parent(n,-1) ; vb visit(n,false) ; 
	dfs(b,adj,parent,visit) ; 
	
	int c[n][103] ; 
	memset(c,n,sizeof(c)) ; 
	for (int i = 0 ; i < n ; i++){
		c[i][f[i]] = min(c[i][f[i]],i) ; 
		int u = i ; 
		while (u != b){
			u = parent[u] ;
			c[u][f[i]] = min(c[u][f[i]],i) ; 
			 
		}
	}


	int q ; cin >> q ; 
	
	while (q--){
		int chef , p ; cin >> chef >> p ; chef-- ; p-- ; 
		if (c[chef][p] < n){
			cout <<  c[chef][p]+1 << el ; 
			continue ; 
		}
		else {
			int u = parent[chef] ; 
			while (u != b){
				if (c[u][p] < n){
					cout << c[u][p]+1 << el ; 
					break ; 
				}
				u = parent[u] ; 
			}
			if (u == b){
				if (c[u][p] < n){
					cout << c[u][p]+1 << el ; 
					continue ;
				}
				else {
					cout << "-1\n" << el ; 
					continue ; 
				}
			}

		}
	}
	return 0 ; 
}