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
#define ll long long 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
#define pb push_back
#define sci(x) scanf("%d",&x)
#define scc(c) scanf("%c",&c)
#define mp(x,y) make_pair(x,y) 

char a[2003][2003] ; 


int main(){
	int n ; sci(n) ; 
	forn(i,n){
		string s ; cin >> s ; 
		forn(j,n){
			a[i][j] = s[j] ; 
		}
	}
	vi v ; 
	vvi adj(n,v) ; 
	forn(i,n){
		forn(j,n){
			if (a[i][j] == '1'){
				adj[i].pb(j) ; 
			}
		}
	}
	ll ans = 0 ; 
	forn(i,n){
		for(int j = i+1 ; j < n ; j++){
			if (a[i][j] == '0'){
				forn(k,adj[i].size()){
					if (a[adj[i][k]][j] == '1'){
						ans ++ ; 
						break ; 
					}
				}
			}
		}
	}
	printf("%lld\n",2*ans) ; 
	return 0 ; 

}