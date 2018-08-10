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
#define sci(x) scanf("%d",&x)

int maxi = 0 ; 






int main(){
	int N ; sci(N) ;
	vi v ; v.rsz(N) ; 
	forn(i,N){
		sci(v[i]) ; 
	}
	vb vv(32,false) ; 
	vector<vector<bool> > A(N,vv) ; 
	forn(i,N) {
		forn(r,32){
			A[i][r] = (v[i]>>r)& 1 ; 
		}
	}
	
	vi s ; 
	forn(i,N){
		s.pb(i) ; 
	}
	vi bs ; 
	for (int r = 31 ; r >= 0 ; r--){
		bs.clear() ; 
		for (int i = 0 ; i < s.size() ; i++){
			if (A[s[i]][r]){
				bs.pb(s[i]) ; 
			}
		}
		if (bs.size() == 2){
			cout << (v[bs[0]] & v[bs[1]]) << el ; 
			//cout << v[bs[0]] & v[bs[1]]  ;
			return 0 ;  
		}
		if (bs.size() > 2){
			s = bs ; 

		}
	}
	cout << (v[s[0]] & v[s[1]]) <<  el ; 
	//cout << v[s[0]] & v[s[1]] ; 
	return 0  ;

}