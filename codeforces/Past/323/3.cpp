#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <algorithm>
#include <iterator>
#define forn(i,n) for (int i = 0 ; i < int(n) ; i++)

using namespace std ; 


typedef vector<int> vi ; 

int gcd(int a , int b ){
	if (a < b){
		return gcd(b,a) ;
	}
	if (b == 0 )
		return a ; 
	if (a == b){
		return a ; 
	}
	return gcd(b,a%b) ; 
}



int main(){

	map<int,int> m ; 
	int n,a ; cin >> n ; 
	vi ans(n,0) ; int sz = 0  ; 
	
	forn(i,n*n){
		cin >> a ; 

		m[-a]++ ; 
	} 

	 

	int pos = n-1 ; 
	for (map<int,int> :: iterator it = m.begin() ; it != m.end() ; it++){
		int x = -it->first ; 
		//cout << "hey!   " <<x <<"\n" ;
		while (it->second){
			//cout << "hey1! \n" ;
			ans[pos] = x ; 
			--it->second ;  
			
			for (int j = pos + 1 ; j < n ; j++){
				m[-gcd(x,ans[j])] -= 2 ; 
			}
			
			pos-- ; 
		}
	}
	forn (k , n){
		cout << ans[k] << " " ; 
	}
	return 0 ; 

}
