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

lld A[100003] ;
lld res = 0 ; 
 
vi v ;

void put(int idx , int li , vi& lt , int ri , vi& rt){
	//cout << idx << sp << li << endl  ; 
	if (idx == lt.size()+1){
		v.clear() ;
		
		for (int i = lt.size()-1 ; i >= 0 ; i--){
			if (lt[i] != -1){
				v.push_back(lt[i]) ; 	
			}
		}
		//cout << "here\n" ; 
		v.push_back(0) ; 
		for (int i = 0 ; i < rt.size() ; i++){
			if (rt[i] != -1){
				v.push_back(rt[i]) ; 
			}
		}
		/*forn(i,v.size()){
			cout << v[i] << sp ; 
		}
		cout << endl ; */
		for (int i = 0 ; i < v.size()-1 ; i++){
			//cout << v[i] << sp << A[v[i]] << sp << sp << v[i+1] << sp << A[v[i+1]] << endl ; 
			res += (lld)((lld) A[v[i]]* (lld) A[v[i+1]]) ; 
		}
		return ; 
	}
	lt[li] = idx ; 
	put(idx+1 , li+1 , lt , ri + 1 , rt) ; 
	lt[li] = -1 ; 
	rt[ri] = idx ; 
	put(idx+1 , li+1 , lt , ri + 1 , rt) ; 
	rt[ri] = -1 ; 
	return ; 

}


int main() {
	int t ; cin >> t ; 
	while (t--){
		int n ; cin >> n;
		//memset(A,0,sizeof(A)) ; 
		
		memset(A,0,sizeof(A)) ;
		forn(i,n+1){
			scanf("%lld",&A[i]) ;   
		}
		/*forn(i,n){
			cout << A[i] << sp ; 
		}
		cout << endl ; */
		//cout <<"heer\n" ; 
		vi rt(n,-1) ; vi lt(n,-1) ; 
		put(1,0,lt,0,rt) ;   
		cout << res %(1000000007) << endl ; 
		res = 0 ; 

	}
	return 0 ; 
}