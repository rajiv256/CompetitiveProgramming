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

int solve(vi& v , int st , int en){
	
}

int solve(vi& v , int st , int en , vvi& D){
	//cout << st << sp << en << el ; 
	if (st > en){
		return 0 ; 
	}
	if (en == st){
		return 1 ; 
	}
	if (D[st][en] != -1){
		return D[st][en] ; 
	}
	int mini = INT_MAX ;
	D[st+1][en] = solve(v,st+1,en,D) ; 

	mini = min(mini,1+D[st+1][en]) ; 

	if (v[st] == v[st+1]){
		D[st+2][en] = solve(v,st+2,en,D) ; 
		mini = min(mini,1+D[st+2][en]) ; 
	}

	for(int i = st+2 ; i <= en ; i++){
		if (v[i] == v[st]){
			D[st+1][i-1] = solve(v,st+1,i-1,D) ; 
			D[i+1][en] = solve(v,i+1,en,D) ; 
			mini = min(mini,D[st+1][i-1]+D[i+1][en]) ; 
		}
	}
	D[st][en] = mini ; 
	return D[st][en] ; 


}







int main(){
	int n ; cin >> n ; 
	vi v ; v.rsz(n) ; 
	forn(i,n){
		cin >> v[i] ; 
	}
	vi vv(n+1,-1) ; 
	vvi D(n+1,vv) ; 
	D[0][n-1] = solve(v,0,n-1,D) ; 

	cout << D[0][n-1] << el ; 



}