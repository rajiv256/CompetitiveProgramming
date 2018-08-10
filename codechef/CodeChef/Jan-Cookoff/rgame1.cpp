#include <iostream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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
#define pb push_back
#define MXN 100003 
#define MOD 1000000007
#define prntv(v) forn(i,v.size()){cout<<v[i]<<sp;}cout<<el



lld A[MXN] ; 
lld ans = 0 ; 

int abs(int a){
	if ( a >= 0){
		return a ;
	}
	return -a ; 
}

int pow (int a , int p){
	if (p == 0)
		return 1 ; 
	int k = pow(a,p-1) ; 
	return a*k ; 
}

int main(){
	int t ; scanf("%d",&t) ; 
	while (t--){
		int n ; scanf("%d",&n) ;
		memset(A,0,sizeof(A)) ;  
		forn(i,n+1){
			scanf("%lld",&A[i]) ; 
		}
		int L[n+1][n+1] ; 
		memset(L,0,sizeof(L)) ; 

		vi v ; v.rsz(n+1) ;
		
		for (int i = 0 ; i < n+1 ; i++){
			for (int j = 0 ; j < n+1 ; j++){
				if (i == j){
					continue ; 
				}
				
				L[i][j] = pow(2,max(0,n-j+i-1)) ; 
			}
		} 
		forn(i,n+1){
			forn(j,n+1){
				ans += (L[i][j]*(A[j]*A[i])) %MOD ; 
			}
		}
		ans /= 2 ; 
		cout << ans << el ; 
		ans = 0 ; 

	}
	return 0 ; 
}	