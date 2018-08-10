#include <iostream>
#include <algorithm>
#include <utility> 
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std ; 

int findMax(std::vector<int>& v,int mini,vector< vector<int> > L){

	






}





int main () {

	int T ; 
	int n1, n2 , m ; 
	scanf("%d",&T);
	
	int j = 0 ; 
	for (j = 0 ; j < T ; j++){
		
		scanf("%d%d%d",&n1,&n2,&m) ; 
		
		int mini = min(n1,n2) ; 
		if (m >= max(n1,n2)){
			cout << "0\n" ; 
			continue ;  
		}

		if (m >= min(n1,n2)){
			cout << n1-n2 << "\n" ; 
			continue ;
		}

		vector<int> v ; v.resize(m); int i ; 
		
		for (i = 0 ; i < m ; i++){
			v[i] = i+1 ;
		}
		vector<int> vv (m,0);
		vector< std::vector<int> L(mini+1,vv); 
		int res = findMax(v,mini,L);
	}



}