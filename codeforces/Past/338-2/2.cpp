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
#include <bits/stdc++.h> 
 
 
using namespace std ;
 
#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp ' '
#define el '\n'
#define ll long long 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define pb push_back
#define MXN 100003 
#define MOD 1000000007
#define prntv(v) forn(i,v.size()){//cout<<v[i]<<sp;}//cout<<el
#define mp(a,b) make_pair(a,b)
#define fi(x) x.first
#define se(x) x.second 
#define sci(x) scanf("%d",&x)
#define pii pair<int,int>
#define ff first 
#define ss second 
#define mem(x,n) memset(x,n,sizeof(x))  

typedef vector<int> vi ; 
typedef vector<char> vc ;
typedef vector<pair<int,int> > vpii ;
typedef vector<pair<ll,ll> > vpll ;
typedef vector<pair<int,pair<int,int> > > vpp ; 
typedef vector<bool> vb ;
typedef set<int> si ; 
typedef map<int,int> mii ; 
typedef map<int,vector<int> > miv ; 
typedef unsigned long long ull ; 





int main(){
	int n , m ; cin >> n >> m ; 
	vi v ; vvi adj(n,v) ; 
	int a , b ; 
	forn(i,m){
		cin >> a >> b ; a-- ; b-- ; 
		adj[a].pb(b) ; 
		adj[b].pb(a) ; 
	}
	
	vi dp(n,1) ; 
	dp[0] = 1 ; 
	for(int i = 0 ; i < n ; i++){
		for (int j = 0 ; j < adj[i].size(); j++){
			if (adj[i][j] > i ){
				if (dp[adj[i][j]] < 1 + dp[i]){
					dp[adj[i][j]] = 1 + dp[i] ; 
				}
			}
		}
	}	
	
	
	ll res = 0 ; ll maxi = 0 ; 
	forn(i,n){
		res = (ll)dp[i]*adj[i].size() ;
		maxi = max (maxi , res) ;  
	}
	cout << maxi << el ; 
	return 0 ; 

}