#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath> 

using namespace std;

#define ull unsigned long long 



int lsPos(ull n){
	int bitpos = 0 ; 
	
	bitpos = log(n)/log(2) ; 
	bitpos += 1 ; 
	return bitpos ; 


}

int rsPos(ull n){
	int bitpos = 0 ; 
	while (n != 0){
		n = n << 1 ; 
		bitpos += 1 ; 
	}
	return (64-bitpos+1) ; 
}

void play(int n){
	int flag = 0 ; 
	while (n != 1){
		//cout << rsPos(n) << " " <<lsPos(n) << endl ;
		if (rsPos(n) == lsPos(n)){
				n /= 2 ; 
		}
		else {
			n -= 1 << (lsPos(n)-1) ; 
		}
		flag = 2 + ~flag ; 
	}

	if (flag == 0){
		cout << "Richard\n" ; 
	}
	else {
		cout << "Louise\n" ; 
	}
	return ; 



}



int main() {

	int t ; cin >> t ;  
 
	while (t--){
		ull n ; cin >> n ;
			
		play(n) ;	 
	}

   	return 0;
}

