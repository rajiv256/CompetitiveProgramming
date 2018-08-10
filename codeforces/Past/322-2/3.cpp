#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>

using namespace std; 

typedef vector<int> vi ; 

#define forn(i,n) for (int i = 0 ;i < n ; i++)



bool mcmp(int a , int b){
	return (a%10) > (b%10) ; 
}


int main() {

	int n , k ; cin >> n >> k ; 
	vi v ; v.resize(n) ; 
	forn(i,n) {
		cin >> v[i] ;
	}

	vi rem(n,0) ; 
	forn(i,n){
		rem[i] = (10-(v[i]%10))%10 ;
	}
	int result = 0 ; 
	int req = 0 ; 
	
	forn(i,n){
		req += rem[i] ;  
	}
	if (req <= k){
		forn(i,n){
			v[i] += rem[i] ; 
			v[i] = min(100,v[i]) ; 
		}
		forn(i,n){
			result += v[i]/10 ; 
		}

		result += (k-req)/10 ; 
		result = min(result,10*n) ; 
		cout << result << endl ;
		return 0 ;
	}
	sort(v.begin(),v.end(),mcmp) ; 
	//vi rem(n,0) ; 
	forn(i,n){
		rem[i] = (10-(v[i]%10))%10 ;
	}
	
	
	result = 0 ; 
	int index = 0 ; 
	while (k >= 0  && index != n){
		if (k -rem[index] < 0){
			break ; 
		}
		v[index] += rem[index] ; 
		v[index] = min(100,v[index]) ; 
		k -= rem[index] ; 
		index += 1 ; 
	}

	forn(i,n){
		//cout << v[i] << " " ;
		result += v[i]/10 ; 
	}
	cout << result << endl ; 
	return 0 ; 



}

