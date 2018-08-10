#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std; 
#define M 100000
int n , m ;

bool err[M+1] ; 

void sieve() {

	memset(err,false,sizeof(bool)*(M+1)) ; 
	
	for (int i = 2 ; i <= sqrt(n) ; i++){
		//cout << i << " "<< err[i]<< " :P :P"<<endl ; 

			for (int j = max(m/i,2) ; i*j<= n ; j++){
				if (i*j < m)
					continue ; 
				//cout << i << " "<< j << endl ;
				err[i*j-m] = true ; 
			}	
		

	}
	return ; 
}



int main() {
	int t ; cin >> t ; 
	while (t--){
		cin >> m>> n ; 
		sieve() ; 
		for(int i = m ; i <= n ; i++){
			if (err[i-m] == false){
				if (i == 1)
					continue ; 
				cout << i << endl ; 
			}
		}
		cout << endl ; 
	} 
	return 0 ; 
}
