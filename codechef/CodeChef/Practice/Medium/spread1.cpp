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


int n = 0 , q = 0, u = 0, v = 0, k = 0, a = 0 , c = 0, p = 0 ; 

int A[1000003] = {0} ; 
long long BIT[1000003] = {0} ; 

void update(int index , int val){
	index += 1 ; 
	//cout << index << el  ;
	while (index <= n){
		//cout << index << el ; 
		BIT[index] += val ; 
		index += (index & -index) ; 
	}
	/*forn(j,n){
			cout << BIT[j+1] << sp ; 
		}
		cout << el ;*/
}

long long query(int index) {
	index += 1 ; 
	long long res = 0 ; 
	while (index > 0){
		//cout << index << el ; 
		res += BIT[index] ; 
		index -= (index & -index) ; 
	}
	return res ; 
}


int main(){
	//cout << "Enter main" << el ; 
	scanf("%d%d%d",&n,&q,&c) ; 
	int qq = 0 ; 
	/*forn(i,n){
		A[i] = c ; 
		update(i,c) ; 
	}*/
	//cout << "came" << el ; 
	char ch ; 
	while (qq < q){
		//cout << qq << el ; 
		
		scanf("%c",&ch) ; 
		if (ch == 'S'){
			scanf("%d%d%d",&u,&v,&k) ; u-- ; v-- ;  
			update (u ,k) ; 
			update (v+1,-k) ; 
			qq += 1 ; 
			
		}
		else if (ch == 'Q'){
			scanf("%d",&p) ; p -- ;  
			
			long long ans = c; 
			ans += (long long) query(p) ;  
			
			cout << ans << el ; 
			qq += 1 ; 
			
		}
		


	}
	return 0 ; 

}