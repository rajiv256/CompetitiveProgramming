#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <map>
#include <set>



#define forn(i,n) for (int i = 0 ; i < int (n) ; i++)
using namespace std;
typedef map<int,int> mii ; 
typedef std::vector<int> vi ; 

bool prime_check(int n ){

	int sqt =  (int)sqrt((double)n) ; 
	//int sqt = n/2 ; 
	int i ; 
	for (i = 2 ; i <= sqt ; i++){
		if (n % i == 0){
			return false ; 
		}
	}
	return true ; 
}


int main() {
	int n ; cin >> n ; 
		
	if (prime_check(n)){
		cout << "1\n" ; 
		cout << n ; 
		return 0 ; 
	}

	int p1 = n-2 ; 
	
	while (prime_check(p1)== false) {
		p1-- ; 
	}
	vi v ; v.push_back(p1) ;
	int p2 = n-p1 ; 
	int i ; 
	for (i = 2 ; i <= p2 ; i++){
		if (prime_check(i)){
			if (p2-i == 0){
				v.push_back(i);
				break ;
			}
			if (prime_check(p2-i)){
				v.push_back(i); v.push_back(p2-i) ; 
				break ; 
			}
		}
	}
	cout << v.size()<<"\n" ; 
	forn(i,v.size()){
		cout << v[i] << " " ; 
	}
	return 0 ; 

}