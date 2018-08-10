#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std ; 

typedef std::vector<int> vi ; 

bool check(const vi& v, int st , int p){

	int temp = st ; int n = v.size() ; 
	st =  st+p ; int in ;
	st = st%n ;   
	while (st != temp){
		 
		if (v[temp] < v[st]){
			return false ;
		}
		st += p ;
		st = st %n ; 
	}
	return true ; 
}


int main(){
	int n ; cin >> n ; 
	vi v ; v.resize(n) ; 
	int i = 0 ; 
	while (i < n ){
		cin >> v[i] ; 
		i++ ; 
	}

	int count = 0 ; int j ; 
	for (j = 0 ; j < n ; j++){
		for (i = 0 ; i < n ; j++){
			//cout << "check!\n" ; 
			int k = 0 ; 
			for (k = 0 ; k < j ; k++){
				if (check(v , (i+k)%n , j) == false) 
					break ; 
			}
			if (k == j)
				count++ ; 	 
		}
 	}
	cout << count << endl ; 

	return 0 ; 


}