#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std; 
#define lld long long int

int dd(lld n){
	int res= 0 ; 
	while (n != 0) {
		int c = n % 10 ; 
		if (c%2 != 0){
			res += c ; 
		}
		else {
			res += 2*c ; 
		}
		n /= 10 ; 
	}
	return res%10  ; 
}


int tot(lld n){
	if (n%10 == 0){
		return (45*n/10) ; 

	}
	else {
		lld t1 = tot(n-1) ; 
		return (t1+ dd(n-1)) ; 
	}
}


int main() {
	int t ; cin >> t ; 
	while (t--){
		lld a ,b ; cin >> a >> b ; 
		cout<< (tot(b+1) - tot(a)) << endl ;  
	}
	return 0 ; 
}
