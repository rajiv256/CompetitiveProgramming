#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>


using namespace std ;

#define forn(i,n) for(int i = 0 ; i < n ; i++)
#define lld long long int 

typedef vector<int> vi ; 
typedef vector<bool> vb ; 

int noDigits(lld n){
	int cnt = 0 ; 
	while (n!=0){
		cnt++ ; 
		n /= 10 ; 
	}
	return cnt ; 
}



lld forced(int k , int n) {
	lld res = 1 ;
	//cout << n << "fuck" <<endl ;  
	if (n <= 0){
		return res ; 
	}
	for (int i = k ; i >= k-n+1 ; i--){
		res *= i ; 
	}
	return res ; 
}

lld delicious(lld T , vi& v){
	//cout << "Its " << T << endl ; 
	if (T == 0)
		return 0 ; 
	int ndigits = noDigits(T);
	lld result = 0; 
	if (ndigits > 10){
		result = v[10] ;
		return result ;  
	}
	result = v[ndigits-1];
	//cout << result << endl ; 
	
	vi digits ; digits.resize(ndigits) ; 
	int temp = T ; int k = ndigits -1  ; 
	while (temp != 0){
		digits[k] = temp %10 ; 
		temp /= 10 ; 
		k -= 1 ; 
	}
	vb bmask(10,false) ; 
	
	for (int i = 0 ; i < ndigits ; i++){
		
		if (bmask[digits[i]]){
			for (int j = 0 ; j < digits[i] ; j++){
				if (!bmask[j]){
					if (i == 0 && j == 0){
						continue ; 
					}
					result += forced(10-i-1,ndigits-i-1) ; 
				}
			}
			return result ;
		}
			 

		for (int j = 0 ; j < digits[i] ; j++){
			//cout << j << endl ; 
			if (!bmask[j]){
				if (i == 0 && j == 0){
					continue ; 
				}
				result += forced(10-i-1,ndigits-i-1) ; 
			}
		}
		bmask[digits[i]] = true ; 
	}
	result += 1 ; 
	return result  ; 
}




int main() {

	int t ; cin >> t ; 

	vector<int> v ; 
	v.resize(11) ;
	v[0] = 0 ; 
	v[1] = 9 ; 
	v[2] = 9*9 + v[1] ; 
	v[3] = 9*9*8 + v[2] ; 
	v[4] = 9*9*8*7 + v[3] ; 
	v[5] = 9*9*8*7*6 + v[4] ; 
	v[6] = 9*9*8*7*6*5 + v[5] ; 
	v[7] = 9*9*8*7*6*5*4 + v[6] ; 
	v[8] = 9*9*8*7*6*5*4*3 + v[7] ; 
	v[9] = 9*9*8*7*6*5*4*3*2 + v[8] ; 
	v[10] = 9*9*8*7*6*5*4*3*2*1 + v[9] ;  


	while (t--){
		lld l , r ; 
		cin >> l >> r ; 
		//cout << delicious(l-1,v) << endl ; 
		//cout << delicious (r,v) << endl ; 
		cout << (delicious(r,v) - delicious(l-1,v)) << endl ; 
		
	}
	return 0 ; 
}
