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
#define abs(a) (a>0?a:-a)


int n , t ; 
int a[100003] ; 
char c[100003] ; 
int main(){
	sci(t) ; 
	while (t--){
		sci(n) ; 
		memset(a,0,sizeof(a)) ;
		memset(a,'~' , sizeof(c)) ;  
		forn(i,n){
			sci(a[i]) ; 
		}
		string s = "/*+-" ; 
		int st = 0 , ind = 0 ;  
		while (ind < n){
			forn(j,4){
				c[ind] = s[(st+j)%4] ;
				ind++ ;  
			}
			st = (st+1)%4 ; 
		}
		forn(i,n-1){
			cout << c[i] << sp ; 
		}
		cout << el ; 
		int ans = a[0] ; 
		forn(i,n-1){
			if (c[i] == '+'){
				ans += a[i+1] ; 
			}
			if (c[i] == '-'){
				ans -= a[i+1] ; 
			}
			if (c[i] == '/'){
				ans /= a[i+1] ; 
			}
			if (c[i] == '*'){
				ans *= a[i+1] ; 
			}
		}
		printf("%d\n", ans) ; 

	}
	return 0 ; 
}