#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<int> vi ; 

bool search(vi& v1 , vi& v2 , int ind , int flag , vector< vector<int> >& L){
	if (ind == v1.size()-1){
		return true ; 
	}
	if (L[flag][ind] == 1){
		return true ; 
	}
	if (L[flag][ind] == -1){
		return false ; 
	}
	bool result = false ; 
	if (flag == 0){
		if (v1[ind] <= v1[ind+1]){
			result = result || search(v1,v2,ind+1,0,L) ; 
		}
		if (v1[ind] <= v2[ind+1]){
			result = result || search(v1,v2,ind+1,1,L) ; 
		}
	}
	if (flag == 1){
		if (v2[ind] <= v1[ind+1] ){
			result = result || search(v1,v2,ind+1,0,L) ; 
		}
		if (v2[ind] <= v2[ind+1]){
			result = result || search(v1,v2,ind+1,1,L) ; 
		}
	}

	if (result == true) 
		L[flag][ind] = 1 ; 
	else
		L[flag][ind] = -1 ; 

	return result ; 
}





int main() {
    int t ; cin >> t ; 
    while(t--){
    	int n ; cin >> n ; 
    	vi v1 ; vi v2; v1.resize(n) ; v2.resize(n) ; 
    	for (int i =  0 ; i < n ; i++){
    		cin >> v1[i] ; 
    	}
    	for (int i =  0 ; i < n ; i++){
    		cin >> v2[i] ; 
    	}
    	vi v(n,0) ; 
    	vector< vector<int> > L(2,v) ; 
    	if (search(v1,v2,0,0,L) || search(v1,v2,0,1,L))
    		cout << "YES\n" ; 
    	else{
    		cout << "NO\n" ; 
    	}
    	L.clear() ; 
    	v1.clear() ; v2.clear() ; 
    }

    



    
    return 0 ;
    	
    	
}
