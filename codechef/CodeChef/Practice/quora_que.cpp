#include <iostream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <bits/stdc++.h> 
 
 
using namespace std ;
 
#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp ' '
#define el '\n'
#define ll long long 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define pb push_back
#define MXN 10000 
#define MOD 1000000007
#define prntv(v) forn(i,v.size()){//cout<<v[i]<<sp;}//cout<<el
#define mp(a,b) make_pair(a,b)
#define fi(x) x.first
#define se(x) x.second 
#define sci(x) scanf("%d",&x)
#define pii pair<int,int>
#define ff first 
#define ss second 
#define mem(x,n) memset(x,n,sizeof(x))  

typedef vector<int> vi ; 
typedef vector<char> vc ;
typedef vector<pair<int,int> > vpii ;
typedef vector<pair<ll,ll> > vpll ;
typedef vector<pair<int,pair<int,int> > > vpp ; 
typedef vector<bool> vb ;
typedef set<int> si ; 
typedef map<int,int> mii ; 
typedef map<int,vector<int> > miv ; 
typedef unsigned long long ull ; 

//adjacency matrix. 

// depth-first search starting from a node to get the 
// no.of paths starting from 'src' with length = n . 

// cnt[0] contains the answer.  
/*void dfs(int src , vb& visited, int nodesSeen,int n, vi& cnt){
	 
	if (nodesSeen == n){
		cnt[0] += 1 ; 
		return ; 
	}
	visited[src] = true ; 
	forn(i,n){
		if (adj[src][i] == true){
			if (!visited[i]){ 
				dfs(i,visited,nodesSeen+1,n,cnt) ; 
			}
		}
	}
	//to try out various paths. 
	visited[src] = false ; 
	return ; 

}*/




int main(){

	// Assuming Zero-based indexing. 
	int n,k ; cin >> n >> k ; 
	
	int adj[n][n] ; 
	memset(adj,0,sizeof(adj)) ; 
	forn(i,n){
		forn(j,n){
			adj[i][j] = 1 ; 
		}
	}
	int a , b ;
	// remove the edges from the adjacency matrix.  
	forn(i,k){
		cin >> a >> b ;
		adj[a][b] = 0 ; 
		adj[b][a] = 0 ; 
	}
	// No self-loops. 
	forn(i,n){
		adj[i][i] = 0 ; 
	}
	
	for (int i = 0 ; i < n ; i++){
		for (int j = 0 ; j < n ; j++){
			cout << adj[i][j] << sp ; 
		}
		cout << el ;
	}
	
	int dp[n][n][n] ; 
	memset(dp,0,sizeof(dp)) ; 

	forn(i,n){
		forn(j,n){
			dp[i][j][1] = adj[i][j] ; 
		}
	}

	for(int k = 2 ; k < n ; k++){
		forn(u,n){
			forn(i,n){
				forn(j,n){
					if (i != j && i != u && u != j)
					for(int d = 1 ; d <= k-1 ; d++){
						dp[i][j][k] += dp[i][u][d]*dp[u][j][k-d] ; 
					}
				}
			}
		}
		forn(i,n){
		forn(j,n){
			cout << dp[i][j][k] << sp ; 
		}
		cout << el ; 
		}
		
		cout << el ; 

	}
	
	
	return 0 ; 

}