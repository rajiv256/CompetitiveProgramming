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

int solve(vi& a ,int idx , int n){
	if (idx == n){
		return 0 ; 
	}

	int res = solve(a,idx+1,n) ; 
	cout << res << sp << idx << el ; 
	return (a[idx] +res + a[idx]^res) ; 

}


int main() {
	int t ; cin >> t ; 
	while (t--){
		int n ; cin >> n ;
		vi a ; a.rsz(n) ; 
		forn(i,n){
			cin >> a[i] ; 
		}
		int count = solve(a,0,n); 
		cout << (count %(1000000007)) << el ; 
	}
}