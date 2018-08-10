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
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define LIM 1000000000
#define sp " " 
#define el "\n"
#define lld long long int 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
#define pb push_back
#define sci(x) scanf("%d",&x)
#define mp(x,y) make_pair(x,y) 

 

int main(){
	int T ; sci(T) ; 
	while (T--){
		//cout << "What?" << el ; 
		int N ; sci(N) ; 
		vi v  ; mi m ; int x ;  
		int k = pow(2.0,(double)N) ; 
		forn(i,k){
			cin >> x ; v.pb(x) ; 
			m[x] += 1 ;  
		}
		v.rsz(k);  

		//cout << "What1?" << el ; 
		//sort(all(v)) ; 
		vi res ; 
		for(int i = 1 ; i < v.size() ; i++){
			int fl = 0 ; 
			forn(j,res.size()){
				if (m[res[j]+v[i]] == 0){
					fl = 1 ;
					break ;  
				}
			}
			if (fl == 0){
				res.pb(v[i]) ; 
			}
		}
		//cout << "What2?" << el ; 
		forn(i,res.size()){
			printf("%d ",res[i]) ; 
		}
		cout << el ; 

	}
	return 0 ; 
}