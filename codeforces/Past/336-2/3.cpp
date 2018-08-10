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

int dp[MXN] ;  


int main(){
	int n ; cin >> n ; 
	int a , b ; 
	vpii pos ; pos.rsz(n) ; 
	forn(i,n){
		cin >> a >> b ; 
		pos[i] = mp(a,b) ;  
	}
	sort(all(pos)) ; 

	forn(i,n){
		dp[i] = 1 ; 
	}
	int maxi = 1 ; dp[0] = 1 ; 
	for (int i = 1 ; i < n ; i++){
		dp[i] = 1; int x = pos[i].ff - pos[i].ss ;
		if (x <= pos[0].ff ){
			continue ; 
		}  
		//cout << x << el ; 
		for (int j = i-1 ; j >=0  ; j--){
			if (x > pos[j].ff){
				dp[i] = max(dp[i],1+dp[j]) ; 
				break ; 
			}
		}
		
		maxi = max(maxi,dp[i]) ; 
	}
	cout << n-maxi << el ; 




}