#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <queue>



using namespace std;

typedef vector<int> vi ;
typedef vector<bool> vb ; 
typedef vector<pair<int,int> > vp ; 
#define forn(i,n) for(int i=0;i<n;i++)

void print_da(vector<vector<int> >& v,int n){
	 forn(i,n){
	 	cout << "v " << i << " : "; 
	 	forn(j,v[i].size()){
	 		cout << v[i][j] << " " ; 
	 	}
	 	cout << endl ; 
	 }
}

void addBridges(int u , vector<vector<int> >& adj ,vector<vector<int> >& crit , vb& visited,vi& disc,vi& low,vi& parent,int n){

	static int time = 0 ; 
	//print_da(adj,n) ; 
	 
	visited[u] = true ; 

	disc[u] = low[u] = ++time ; 
	forn(i,adj[u].size()){
		int v = adj[u][i] ; 
		if (visited[v] == false){
			parent[v] = u ; 
			addBridges(v,adj,crit,visited,disc,low,parent,n);

			low[u] = min(low[u],low[v]) ; 
			//std::cout << low[v] << " " << disc[u] << endl ; 
			if (low[v] > disc[u]){
				
				crit[u].push_back(v) ;
				crit[v].push_back(u) ; 
			}
		}
		else if (v != parent[u]){
			low[u] = min(low[u],disc[v]) ; 
		}
	}
	//print_da(crit,n) ; 

}

int result(int src , vector<vector<int> >& adj, vector<vector<int> >& crit,vb& visited, int critical ,int count, int n)
{
	if (critical == 0 ){
		return count ; 
	}
	visited[src] = true ; 
	int u = src ; 
	for (int i = 0 ; i < adj[u].size() ; i++){
		if (!visited[i]){
			if (binary_search(crit.begin(),crit.end(),i))
				critical-- ; 
			count += result(i,adj,crit,visited,critical,count,n) ; 
		}
	}
	return count ; 




}


/*void setvalues(int src , vector<vector<int> >& adj, vector<vector<int> >& crit,
	map<int,vector<int> >& fmap ,vb& visited, int critical , int n){
	int u = src ; 
	if (critical == 0 ){
		return ; 
	}
	visited[u] = true ; 
	for(int i = 0 ; i < n ; i++){
		if (!visited[i]){
			fmap[u].push_back(i) ;
			fmap[i].push_back(u) ; 
			if (binary_search(crit[u].begin(),crit[u].end(),i)){
				setvalues(i,adj,crit,fmap,visited,critical-1,n) ; 

			}
			else{
				setvalues(i,adj,crit,fmap,visited,critical,n) ; 
			}
			fmap[u].insert(fmap[u].end(),fmap[i].begin(),fmap[i].end()) ; 
			fmap[i].insert(fmap[i].end(),fmap[u].begin(),fmap[u].end()) ; 
				
		}
		else{
			if (binary_search(crit[u].begin(),crit[u].end(),i)){
				fmap[u].push_back(i) ;
				fmap[i].push_back(u) ; 
				setvalues(i,adj,crit,fmap,visited,critical-1,n) ; 
			}
			fmap[u].insert(fmap[u].end(),fmap[i].begin(),fmap[i].end()) ; 
			fmap[i].insert(fmap[i].end(),fmap[u].begin(),fmap[u].end()) ; 
			return ; 
		}
	}
	return ; 



}
*/

void getBridges(vector<vector<int> >& adj , vector<vector<int> >& crit , int n ) {

	vb visited(n,false) ; 
	vi disc(n,0);
	vi low(n,0) ; 
	vi parent(n,-1) ;

	addBridges(0,adj,crit,visited,disc,low,parent,n) ; 
	return ; 

}



int main() {
    int n , e, p ; 
    cin >> n >> e >> p ; 
    int nedges = e ; int nvertices = n ; 
    //vector<vector<bool> > adj(n,vector<bool>(n,false)) ;
    //vector<vector<bool> > crit(n,vector<bool>(n,true)) ;
   	vi v ; 
   	vector<vector<int> > adj(n,v) ;
   	vector<vector<int> > crit(n,v) ;
   	vp edge ; 
    while (e--){
    	int a , b ; cin >> a >> b ; a-= 1 ;b -= 1 ; 
    	//adj[a][b] = true ; adj[b][a] = true ;
    	adj[a].push_back(b) ; adj[b].push_back(a) ; 
    	edge.push_back(make_pair(a,b)); 
    	
    }
    forn(i,n){
    	sort(adj[i].begin(),adj[i].end());
    }


    getBridges(adj,crit,n) ; 

    
    forn(i,n){
    	sort(crit[i].begin(),crit[i].end());
    }
   	vb visited(n,false) ; 
   	forn(i,n){
   		int count = 0 ; 
   		count += result(i,adj,crit,visited,p,0,n) ; 	
   	}
   	
   
   	
    return 0;
}
