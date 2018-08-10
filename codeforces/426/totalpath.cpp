// http://wcipeg.com/problem/ccc07s4

#include <bits/stdc++.h> 

using namespace std ; 

#define pb push_back 
#define all(v) v.begin(),v.end()

int main(){
	int n ; cin >> n ;  

	vector<int> v ; vector<vector<int> > adj(n+2,v);  int x, y ; 
	while (true){
		cin >> x >> y ; 
		if (x==0 && y==0) 
			break ; 
		adj[y].pb(x) ; 
	}
	for(int i = 1 ; i <= n ; i++){
		sort(all(adj[i])) ; 
	}
	int L[n+2] ; memset(L,0,sizeof(L)) ; 
	L[1] = 1; 
	for(int i = 2 ; i <= n ; i++){
		for(int j = 0 ; j < adj[i].size() ; j++){
			L[i] += L[adj[i][j]] ; 
		}
	}
	cout << L[n] <<  endl ;

	return 0 ; 
}
