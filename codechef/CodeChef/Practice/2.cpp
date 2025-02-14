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
#define MXN 1000000 
#define MOD 1000000007
#define prntv(v) forn(i,v.size()){cout<<v[i]<<sp;}cout<<el
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
	int t ; cin >> t ; 
	while (t--){
		int n , m , q ; cin >> n >> m >> q ; 
		set<int> sh  ; set<int> sv ; 
		sh.insert(1) ; 
		sh.insert(n) ;
		sv.insert(1) ; 
		sv.insert(m) ; 
		int a , b ; 
		while (q--){
			cin >> a >> b ;
			sh.insert(a) ; 
			sv.insert(b) ; 
		} 
		int reg = (sh.size()-1)*(sv.size()-1) ; 
		int midh = INT_MAX; int midv = INT_MAX ; int madh = INT_MIN ; int madv = INT_MIN ;  
		
		vi vh(sh.size(),0) ; vi vv(sv.size(),0) ; 
		int k = 0 ; 
		for(set<int> :: iterator it = sh.begin(); it != sh.end() ; it++){
			vh[k] = *it ;
			k += 1 ; 
		}
		k = 0 ; 
		for(set<int> :: iterator it = sv.begin(); it != sv.end() ; it++){
			vv[k] = *it ;
			k += 1 ; 
		}

		forn(i,vh.size()-1){
			midh = min(midh,vh[i+1]-vh[i]) ; 
			madh = max(madh, vh[i+1]-vh[i]) ; 
		}
		forn(i,vv.size()-1){
			midv = min(midv,vv[i+1]-vv[i]) ; 
			madv = max(madv, vv[i+1]-vv[i]) ; 
		}
		cout << reg << sp << midv*midh << sp << madv*madh << el ; 
	}
	return 0 ; 
}