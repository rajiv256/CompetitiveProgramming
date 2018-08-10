#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>



using namespace std ; 
typedef vector<int> vi ; 


void ldss(vi& L ,vi& v){
	int i , j ; int n = v.size() ; 
	for (i = n-1 ; i >= 0 ; i--){
		for (j = i+1 ; j< n ; j++){
			if (v[i] <= v[j]) {
				if (L[i] < L[j]+ 1){
					L[i] = L[j] + 1 ; 
				}
			}
		}
	}
}





int main () {

	int n, T; cin >> n ; cin >> T ; 
	vi v ; v.resize(n) ; 
	int i ; 
	for (i = 0 ; i < n ; i++){
		cin >> v[i] ; 
	}
	vi L(n,1);
	int fl= 0 ; 
	int j ;
	vi cur = L ;
	vi dup = L ; 
	int cnt = 0 ; 

	while (cnt < T){
		//cout << cnt <<"\n" ;  
		
		if (cnt == 0){
			ldss(L,v);
			fl = 1 ; 
			cur = L ;
			cnt++ ; 
			continue ;
		}	
		//cur = L ;
		vi mark(n,0) ; 
		for (i = n-1 ; i >= 0 ; i--){
			for (j = 0 ; j < n ; j++){
				
				if (v[i] <= v[j]){
					//cout <<v[i] << " $ " << v[j] <<" $ "<< cur[i] << " $ " << cur[j]+1 << endl ; 
					if (cur[i] < cur[j]+1){
						
						if (j == i && mark[i] == 0){
							//cout << "one\n" ; 
							cur[i] = cur[j]+1 ;
							mark[i] = 1 ; 
							continue ; 
						}
						else if (j == i && mark[i] == 1){
							//cout << "Two\n" ; 
							continue ; 
						}
						else if (j != i ){
							//cout << "THree\n" ;
							cur[i] = cur[j] + 1 ; 
							mark[i] = 1 ; 
							continue ; 
						}
					}
				}
			}
			
			 
		}
		cnt++ ;
		//cur = L ; 
			
	}
	int max = -1 ; 
	for (i = 0 ; i < n ; i++){
		if (max < cur[i])
			max = cur[i] ; 
	}
	cout <<max <<endl ; 

}