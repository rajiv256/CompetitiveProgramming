#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath> 

using namespace std;

typedef vector<int> vi ; 
typedef vector<bool> vb ; 

typedef vector<pair<int,int> > vp ;

#define forn(i,n) for (int i = 0 ; i < n ; i++)
#define lld long long int 
#define vvi vector<vector<int> >

long long int dp(int n, int idx, vi& a, vector<vector<long long int> >& cc){
	//cout << n << "  " << idx << endl ; 
	//cout << cc[n][idx] << endl ; 
	if (n == 0){
		cc[n][idx] = 1 ;  
		return 1; 
	}
	if (n!=0){
		if (n < a[idx]){
			cc[n][idx] = 0 ; 
			return 0; 
		}
	}
	if (idx == a.size()){
		cc[n][idx] = 0 ; 
		return 0; 
	}

	if (cc[n][idx] != -1){ 
		 return cc[n][idx] ; 
	}
	//cout << a[idx] << endl ; 
	long long int x = dp(n-a[idx],idx,a,cc) ; 
	long long int y = dp(n,idx+1,a,cc) ; 
	cc[n][idx] = x + y ; 
	return cc[n][idx] ; 



}




int main() {
	int n, m ; cin >> n >> m ; 
	vi a ; a.resize(m) ; 
	forn(i,m){
		cin >> a[i] ; 
	}
	sort(a.begin() , a.end()) ;
	
	vector<long long int> v(m,-1) ;  
	vector<vector<long long int> > cc(n+1,v) ; 

	
	
	long long int k = dp(n,0,a,cc) ; 
	
	cout << k << endl ; 
    return 0 ; 
}