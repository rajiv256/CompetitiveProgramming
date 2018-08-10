// This is O(V^3) solution as it uses modified version of Floyd-Warshall algorithm.
// Self-thought sef implemented without any outside help.  

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>

using namespace std ;
typedef vector<int> vi ; 
#define vvi vector<vector<int> > 


void transitiveClosure(vvi& wt, int n){

	int i , j, k ; 
	for (k = 0 ; k < n ; k++){
		for (i = 0 ; i < n ; i++){
			for (j = 0 ; j < n ; j++){
				if (wt[i][j] < min(wt[i][k] , wt[k][j]) && i != j){
					wt[i][j] = min(wt[i][k] , wt[k][j]) ; 
				}
			}
		}
	}
	return ; 

}




int main() {
	int v , e ; cin >> v >> e ; 
	vi ewt(v,0);
	vvi wt(v,ewt) ; 
	
	//vi vadj ; 
	/*vvi adj(v,adj) ; */
	while (e--){
		int v1,v2,w ; 
		cin >> v1 >> v2 >> w ; 
		/*adj[v1].push_back(v2) ; 
		adj[v2].push_back(v1) ; */
		wt[v1][v2] = w ; 
		wt[v2][v1] = w ;
	}
	transitiveClosure(wt,v) ;
	for(int i = 0 ; i < v ; i++){
		for (int j = 0 ; j < v ; j++){
			cout << wt[i][j] << " " ; 
		}
		cout << endl ; 
	} 
	return 0 ; 
}
