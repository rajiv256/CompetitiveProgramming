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

lld A[MXN] ; 
lld res = 0 ; 
int u = 0 ; int v = 0 ;  
void solve(int idx , int lpre ,lld lun, int rpre ,lld run, int n){
	//cout << idx << sp << lpre << sp << rpre << el ; 
	if (idx == n+1){
		//v += 1 ; 
		//cout << "ended" << sp << v <<  el ; 
		return ; 
	}
	res += ((A[idx]*A[lpre])+run)%MOD ; 
	//u += 1 ; 
	//cout << "created" << sp << u << el ;  
	solve(idx+1 , idx ,lun + A[idx]*A[lpre] , rpre ,run, n) ; 
	
	res += ((A[idx]*A[rpre])+lun)%MOD ; 
	//u += 1 ; 
	//cout << "created"<< sp << u << el ;
	solve(idx+1,lpre,lun,idx,run + A[idx]*A[rpre] ,n) ;
	//v += 1 ; 
	//cout << "ended" << sp << v <<  el ;
	return ;  

}

int main(){
	int t ; scanf("%d",&t) ; 
	while (t--){
		int n ; scanf("%d",&n) ;
		memset(A,0,sizeof(A)) ;  
		forn(i,n+1){
			scanf("%lld",&A[i]) ; 
		}
		solve(1,0,0,0,0,n) ; 
		cout << res % MOD << el ; 
		res = 0  ; 
	}
}
