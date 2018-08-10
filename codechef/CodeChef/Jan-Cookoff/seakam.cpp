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
#define pb push_back
#define MXN 100003 
#define MOD 1000000007
#define prntv(v) forn(i,v.size()){cout<<v[i]<<sp;}cout<<el
#define mp(a,b) make_pair(a,b)
#define fi(x) x.first
#define se(x) x.second 
#define sci(x) scanf("%d",&x)





void colorGraph(vvi& adj,int N,vi& color){
	int ind = 0 ; 
	while (ind < N){
		color[ind] = 1 ; 
		vb ass(N+1,false) ; 
		for(int j = 0 ; j < adj[ind].size() ; j++){
			if (color[adj[ind][j]] != 0){
				ass[color[adj[ind][j]]] = true ; 
			}
		}
		forn(i,N+1){
			if (!ass[i]){
				color[ind] = i ; 
			}
		}

	} 
	return ; 

}







void dfs(int s , vvi& adj ,vb& vis,int cnt ,lld *anss){

	vis[s] = true ; 
	cnt++ ; 
	if (cnt == vis.size()){
		*anss += 1 ; 
		return ; 
	}
	for (int i = 0 ; i < adj[s].size() ; i++){
		if (!vis[adj[s][i]]){
			dfs(adj[s][i],adj,vis,cnt,anss) ; 
		}
	}	
	return ; 
}




int main() {
	int T ; sci(T) ; 
	while (T--){
		int N , M ; sci(N) ; sci(M) ; 
		
		vi v ; 
		vvi adj(N,v) ;
		
		forn(i,N){
			forn(j,N){
				if (i != j){
					adj[i].pb(j) ; 
				}
			}
		}
		
		int a , b ; 
		forn(i,M){
			sci(a) ; sci(b) ; a-- ; b-- ; 
			vi :: iterator it1 = find(all(adj[a]),b) ; 
			if (it1 != adj[a].end())
				adj[a].erase(it1) ; 
			vi :: iterator it2 = find(all(adj[b]),a) ; 
			if (it2 != adj[b].end())
				adj[b].erase(it2) ;

		} 
		
		lld ans = 0  ; 
		 
		forn(i,N){
		 	vb vis(N,false) ; 
		 	dfs(i,adj,vis,0,&ans) ; 
	    }






		cout << ans%MOD << el  ; 
	}
}