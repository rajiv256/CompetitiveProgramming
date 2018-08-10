#include <bits/stdc++.h>

using namespace std ; 

#define ll long long 
#define sp " " 
#define el endl 
#define forn(i,st,en) for(int i=st;i<en;i++)
#define MXN 100009

int parent[MXN] ; 

int find(int x){
	if (parent[x]==-1 ||parent[x]==x){
		return x ; 
	}
	return find(parent[x]); 
}


int main(){
	ios_base::sync_with_stdio(false) ; 
	cin.tie(0) ; 
	forn(i,0,MXN){
		parent[i] = -1 ; 
	}

	int n , m ,i; cin >> n >> m ; 
	forn(it,0,n){
		parent[it] = it ; 
	}
	for(i=0;i < m ; i++){
		int u , v , w  ;
		cin >> u >> v >> w ;
		int pu = find(u) ; 
		int pv = find(v) ; 
		if (pu==pv)
			break ; 
		else{
			parent[pv] = pu ;
		} 	
	}
	if (i==m){
		cout << "-1\n" ; 
	}
	if (i < m){
		cout << i+1 << el ; 
	}
	return 0 ; 





}