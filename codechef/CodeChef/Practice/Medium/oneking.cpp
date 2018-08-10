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
#define sci(x) scanf("%d",&x)
#define mp(x,y) make_pair(x,y) 

int main(){
	int t ; sci(t); 
	while(t--){
		int n ; sci(n) ; 
		int a , b ; 
		vp A ; A.rsz(n) ; 
		vp B ; B.rsz(n) ; 
		
		forn(i,n){
			sci(a) ; sci(b) ; 
			A[i] = mp(b,a) ;
		}
		sort(all(A)) ; 
		forn(i,n){
			B[i] = mp(A[i].yy,A[i].xx) ; 
		}
		int ans = 0 ; int pre = 0 ; 
		while (pre < n ){
			int preb = B[pre].yy ; 
			ans += 1 ; 
			int maxb = preb ; 
			pre += 1 ; 
			while (pre < n){
				if (B[pre].xx <= preb){
					pre += 1 ; 
					continue ; 
				}
				else {
					break ; 
				}
			}
		}

		printf("%d\n",ans) ; 
	}
	return 0 ; 
}