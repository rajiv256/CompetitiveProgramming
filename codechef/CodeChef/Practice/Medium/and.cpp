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

long long pow(long long  a , long long b ){
	if (b == 0)
		return 1 ;
	long long k = pow(a,b-1); 
	return a*k ; 
}

int main(){
	int n ; cin >> n ; 
	long  long A[32] ; 
	memset(A,0,sizeof(A)) ; 
	vi v ; v.resize(n) ; 	
	forn(i,n){
		cin >> v[i] ; 
	}

	for(int r = 0 ; r < 32 ; r++){
		forn(i,n){
			if (v[i]>>r & 1 == 1){
				A[r] += 1 ; 
			}
		}
	}
	long long ans = 0 ; 
	forn(i,32){
		ans += ((A[i]*(A[i]-1))/2)* (pow(2,(long long)i)) ; 
	}
	cout << ans << el ; 
}