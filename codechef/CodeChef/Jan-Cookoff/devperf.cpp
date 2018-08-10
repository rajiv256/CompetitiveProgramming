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
#define MXN 10003 
#define MOD 1000000007
#define prntv(v) forn(i,v.size()){cout<<v[i]<<sp;}cout<<el
#define mp(a,b) make_pair(a,b)
#define fi(x) x.first
#define se(x) x.second 



bool A[1003][1003] ; 

int abs(int a){
	if (a >= 0)
		return a ; 
	return -a ; 
}

int main() {
	int t ; scanf("%d",&t ) ; 
	vp xx ; vp yy ; string s ;
	while (t--){
		int N , M ; scanf("%d%d",&N,&M) ; 
		char c ; 
		memset(A,false,sizeof(M)) ; 
		xx.clear() ; yy.clear() ;   
		forn(i,N){
			 cin >> s ; 
			forn(j,M){
				c = s[j] ; 
				//scanf("%c",&c); 
				if (c == '*'){
					A[i][j] = true; 
					xx.pb(mp(i,j)) ; 
					yy.pb(mp(j,i)) ; 
				}
				else {
					A[i][j] = false ; 
				}
			}
		}
		if (xx.size() == 0){
			cout << "0\n" ; 
			continue ; 
		}
		sort(all(xx)) ; sort(all(yy)) ; 


		int ans = INT_MAX ; 
		forn(i,N){
			int resx = 0 ; 
			if (i < fi(xx[0])){
				resx = max(resx , fi(xx[xx.size()-1])-i) ; 
				
			}
			else if (i >= fi(xx[0]) && i <= fi(xx[xx.size()-1])){
				resx = max(resx,max(abs(fi(xx[0])-i),abs(fi(xx[xx.size()-1])-i))) ; 
				
			}
			else if (i > fi(xx[xx.size()-1])){
				resx = max(resx,i-fi(xx[0])) ; 
			}

			//cout << i << sp <<resx << el ; 
			forn(j,M){ 
				int resy = 0 ; 
				if (j < fi(yy[0])){
					resy = max(resy , fi(yy[yy.size()-1])-j) ; 
					
				}
				else if (j >= fi(yy[0]) && j <= fi(yy[yy.size()-1])){
					resy = max(resy,max(abs(fi(yy[0])-j),abs(fi(yy[yy.size()-1])-j))) ; 
					
				}
				else if (j > fi(yy[yy.size()-1])){
					resy = max(resy,j-fi(yy[0])) ; 
					
				}
				//cout << j << sp << resy << el ; 
				int res = max(resx,resy) ; 
				ans = min(ans,res) ; 		
			}
		}
		cout << ans+1 << el ; 
		
	}
	return 0 ; 
}