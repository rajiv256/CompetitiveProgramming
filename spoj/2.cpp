#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <cmath>

using namespace std ; 

bool prime(int n){
	int sqt = int(sqrt(double(n))) ; 
	sqt++ ; 
	int i ; 
	if (n <= 1)
		return false ; 
	for (i = 2 ; i < sqt ; i++){
		if (n % i == 0)
			return false ; 
	}
	return true ;

}

void check(int l , int h){
	int i ; 
	for (i = l ; i <= h ; i++){
		if (prime(i))
			cout << i << endl ; 
	}
	return ;
}



int main (){
	int t ; cin >> t ; 
	while (t--){
		int a , b ; 
		cin >> a ; cin >> b ; 
		//cout << "Yes" ; 
		if (a == 1)
			a = 2 ; 
		if (a % 2 == 0 && a != 2){
			check(a+1,b) ; 
		}
		else 
			check(a,b) ; 
		cout << endl ; 
	}
}
