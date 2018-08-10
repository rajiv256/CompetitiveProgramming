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
typedef map<int,int> mi ; 
typedef map<int,vector<int> > miv ; 
typedef unsigned long long ull ; 


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pi pair<int,int> 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define LIM 1000000000
#define sp " " 
#define el "\n"
#define ll long long 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
#define pb push_back
#define sci(x) scanf("%d",&x)
#define mp(a,b) make_pair(a,b)
ll dist(pair<ll , ll > p1 , pair <ll , ll > p2){
	return (p1.xx-p2.xx)*(p1.xx-p2.xx) + (p1.yy-p2.yy)*(p1.yy-p2.yy) ; 
}

int main(){
	ll n , x1 , y1 , x2 , y2 ; 
	cin >> n >> x1 >> y1 >> x2 >> y2 ; 
	vector<pair<ll , ll > >  cn ; cn.rsz(n) ; 
	forn(i,n){
		cin >> cn[i].xx >> cn[i].yy ; 
	}
	ll r1sq = 0 ; ll r2sq = 0 ; 
	int maxr1sq = 0 , maxr2sq = 0 ; 
	//ll ans = 1E20 ; 
	vector<ll> v1 , v2 ; v1.rsz(n); v2.rsz(n) ; 

	forn(i,n){
		ll t1 = dist(mp(x1,y1),cn[i]) ; 
		ll t2 = dist(mp(x2,y2),cn[i]) ; 
		//cout << t1 << sp << t2 << el ;
		v1[i] = t1 ; 
		v2[i] = t2 ; 
	}
	ll ans = 1000000000000000 ; 
	forn(i,n){
		r1sq = v1[i] ; 
		forn(j,n){
			if (r1sq < v1[j]){
				r2sq = max(r2sq,v2[j]) ; 
			}
		}
		//cout << r1sq << sp << r2sq << el ; 
		ans = min(ans,r1sq+r2sq); 
		r1sq = 0 ; r2sq = 0  ;
	}
	forn(i,n){
		r2sq = v2[i] ; 
		forn(j,n){
			if (r2sq < v2[j]){
				r1sq = max(r1sq,v1[j]) ; 
			}
		}
		//cout << r1sq << sp << r2sq << el ; 
		ans = min(ans,r1sq+r2sq); 
		r1sq = 0 ; r2sq = 0  ;
	}	 
	cout << ans << el ; 
	return 0 ; 
}