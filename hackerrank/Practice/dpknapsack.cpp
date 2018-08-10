#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std ;
#include <bits/stdc++.h> 
typedef vector<int> vi ; 
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ; 
typedef vector<pair<int,pair<int,int> > > vpp ; 
typedef vector<bool> vb ;
typedef set<int> si ; 
typedef map<int,int> mii ; 
typedef map<int,vector<int> > miv ; 
typedef unsigned long long ull ; 


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp " " 
#define el "\n"
#define lld long long int 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 


bool solve(vi& a , int idx , int w , int k){
	if (w == 0){
		return true ; 
	}
	if (idx == a.size() && w != 0 ){
		return false ;
	}
	if (w % a[idx] == 0){
		return true ; 
	}
	
	bool res = false ; 
	for (int i = 0 ; i*a[idx] <= w ; i++){
		res = res|| solve(a,idx+1,w - a[idx]*i , k) ; 
	}
	return res ;

	 

}



int main(){
	int t ; cin >> t ; 
	while (t--){
		int n , k ; cin >> n >> k ; 
		vi a ; a.rsz(n) ; 
		forn(i,n){
			cin >> a[i] ; 
		}
		for (int i = k ; i >= 0 ; i--){
			if (solve(a,0,i,k)){
				cout << i << el ; 
				break ; 
			}
		}


	}



}