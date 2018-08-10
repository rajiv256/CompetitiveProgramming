#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>


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


int wt[400][400] = {1E6} ; 
int graph[400][400] = {0} ; 







int main(){
	int n , m ; cin >> n >> m ; 
	vi v ; vvi adj(n,v) ; 
	int a , b , w ; 
	vpp edges ; edges.rsz(m) ; 
	int ec = 0 ; 
	forn(i,n){
		forn(j,n){
			wt[i][j] = 1E6 ; 
		}
	}
	while (m--){
		cin >> a >> b >> w ; a-- ; b-- ; 
		adj[a].push_back(b) ; 
		wt[a][b] = w ; 
		edges[ec] = make_pair(w,make_pair(a,b)) ; 

	}

	for (int k = 0 ; k < n ; k++){
		for (int i = 0 ; i < n ; i++){
			for (int j = 0 ;j < n ; j++){
				wt[i][j] = min(wt[i][j], wt[i][k]+wt[k][j]) ; 
			}
		}
	}
	int q ; cin >> q ; 
	while (q--){
		cin >> a >> b ; a-- ; b-- ; 
		if (wt[a][b] == 1E6){
			cout << "-1\n" ; 
			continue ; 
		}
		cout << wt[a][b] << el ; 
	}
	return 0 ; 


}