#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <iterator>

using namespace std;
typedef long long LL;
typedef vector<int> vi ; 
typedef vector<bool> vb ; 
	
void pg (vector <std::vector<int> > fGraph , int N){
	for (int i = 0 ; i < N ; i++){
			for (int j = 0 ; j < N ; j++){
				cout << fGraph[i][j] << " " ; 
			}
			cout << "\n" ; 
	}
	cout << "\n\n" ; 
}

void pp(vector<int> v){
	for (int i = 0 ; i < v.size() ; i++){
		cout << v[i] << " " ; 
	}
	cout << "\n\n" ; 
}

bool BFS (vector < vector<int> >& graph , int src , int sink , vi& parent,int N) {

	vector<bool> visited(N,false) ; 
	queue<int> q ; 
	q.push(src) ; 
	visited[src] = true ; 
	parent[src] = -1 ; 
	while (!q.empty()){
		
		int u = q.front() ; 
		q.pop() ; 
		for(int j = 0 ; j < N ; j++){
			if (graph[u][j] == 1 && visited[j] == false){
				q.push(j); 
				parent[j] = u ; 
				visited[j] = true ; 
			}
		}
	}

	return (visited[sink]) ; 
}

int fordFulkerson(vector < vector<int> >& fGraph ,int src , int sink ,int N){
	vi parent(N,0) ; 
	vector < vector<int> > rGraph = fGraph ; 
	int max_flow = 0 ; 
	//cout << "enter BFS\n" ; 
	while (BFS(rGraph , src , sink , parent, N)){
		//cout << "didn't come out\n" ; 
		//pg(rGraph,N) ; 
		//pp(parent) ; 
		max_flow += 1 ; 

		int u = sink; 
		for (int u = sink ; u != src ; u = parent[u]){
			rGraph[parent[u]][u] = 0 ; 
			rGraph[u][parent[u]] = 1 ; 
		}
		vi parent(N,0) ; 
	}

	return max_flow ; 

}


int main() {

	int  t ; cin >> t ;
	
	while (t--){

		int n , m ; cin >> n ; cin >> m ; 
		
		vector < vector<int> > fGraph (2*n + 2,vector<int>(2*n+2,0)) ; 
		
		int sink = 2*n+1 ;
		int src  = 0 ;  
		for(int i = 0 ; i < n ; i++){
			fGraph[i+1][i+1+n] = 1 ; 
			fGraph[src][i+1+n] = 1 ; 
			fGraph[i+1][sink] = 1 ; 
		}

		while (m--){
			int i , j ; 
			cin >> i ; cin >> j ; 
			fGraph[i+n][j] = 1 ;
			//cout << m << endl;  
		}

		int N = 2*n + 2 ; 
		
		//pg(fGraph,N);
		

		int max_flow = fordFulkerson(fGraph , src , sink, N ) ; 
		cout << n-max_flow << endl ; 
	}

}