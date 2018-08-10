#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

using namespace std ;

typedef vector<int> vi ; 
typedef unsigned long long ull ;

#define forn(i,n) for(int i = 0 ; i < n ; i++)
#define APSUM(n,d) ((n/2)*(2*n/9+(n+n/9)-1))*d  

int ndigs(int n){
	int cnt = 0 ; 
	while (n != 0){
		cnt ++ ; 
		n /= 10 ; 
	}
	return cnt  ; 
}

int pow(int a , int b){
	if (b == -1){
		return 0 ; 
	}
	if (b == 0)
		return 1 ; 
	return a*pow(a,b-1) ; 
}

int main() {
	int t ; cin >> t ; 

	while (t--){

		int l , r ; 
		cin >> l >> r ; 
		ull res1 = 0 ,res2 = 0; 
		int lds = ndigs(l-1) ;
		int rds = ndigs(r) ; 
		int n ; 
		for (int i = 0 ; i <= lds-1 ; i++){
			n = 9*pow(10,i-1) ;
			res1 += (((n)*(pow(10,i-1)+pow(10,i)-1))/2)*i ;  
		}		
		for (int i = 0 ; i <= rds-1 ; i++){
			n = 9*pow(10,i-1) ; 
			res2 += (((n)*(pow(10,i-1)+pow(10,i)-1))/2)*i  ; 
		}
		//cout << res1 << " " << res2 << endl ; 
		int nn1 = l-1 - pow(10,lds-1)+1 ; 
		int nn2 = r - pow(10,rds-1)+1 ; 
		res1 += (((nn1)*(l-1+pow(10,lds-1)))/2)*lds ; 
		res2 += (((nn2)*(r+pow(10,rds-1)))/2)*rds ;
		//cout << res1 << " " << res2 << endl ; 
		cout << (res2 - res1)%1000000007 << endl ;
		
	}
	return 0 ; 
}