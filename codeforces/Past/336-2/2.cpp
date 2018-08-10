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

int abs(int x){
	if (x < 0)
		return -x ; 
	return x ; 
}


int main(){
	string a , b ; 
	cin >> a >> b ; 

	mii mz ; mii mo ; int nz = 0 ; int no = 0 ; 

	forn(i,b.size()){
		if (b[i] == '0'){
			nz += 1 ; 
		}
		else{
			no += 1 ; 
		}
		mz[i] = nz ; 
		mo[i] = no ; 
	} 
	mz[-1] = 0 ; 
	mo[-1] = 0 ; 

	ll ans = 0 ;  int tmp = b.size()-a.size() ; 
	forn(i,a.size()){
		if (a[i]=='0'){
			ans += mo[tmp+i] - mo[i-1] ; 
		}
		else{
			ans += mz[tmp+i] - mz[i-1] ; 
		}
	}
	cout << ans << el ; 
}