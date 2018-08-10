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


char a[16][16] ; 
bool b[16][16] ; 
int res[16][16] ; 


int plusLen(int x , int y , int n , int m){
	int len = 0 ; 
	while (true){
		if (x+len < 0 || x+len >= n || a[x+len][y] == 'B'){
			break ;  
		}
		if (x-len < 0 || x-len >= n || a[x-len][y] == 'B'){
			break ;  
		}
		if (y+len < 0 || y+len >= m || a[x][y+len] == 'B'){
			break ;  
		}
		if (y-len < 0 || y-len >= m || a[x][y-len] == 'B'){
			break ;  
		}
		len += 1  ; 
	}
	return len-1; 

}

bool overlaps(pair<int,pair<int, int > > a, pair<int,pair<int, int > > b ){
	int x1 = a.yy.xx ; int x2 = b.yy.xx ; 
	int y1 = a.yy.yy ; int y2 = b.yy.yy ; 
	int len1 = a.xx  ; int len2 = b.xx ; 

	int t1 = x1+len1 ; int t2 = y1+len1 ; 
	int t3 = x2-len2 ; int t4 = y2-len2 ; 

	if (x1 == x2){
		if (len1+len2 >= y2-y1){
			return true ; 
		}
	}
	if (y1 == y2){
		if (len1+len2 >= x2-x1){
			return true ; 
		}
	}

	if (x1 >= x2-len2){
		if (y1+len1 >= y2){
			return true ; 
		}
	}

	if (y1 >= y2-len2){
		if (x1+len1 >= x2){
			return true ; 
		}
	}
	return false ; 

}

int main(){
	int n , m ; cin >> n >> m ; 
	//cout << n << sp << m << el ;  
	memset(res,0,sizeof(res)) ; 
	forn(i,n){
		string s ; cin >> s ; 
		forn(j,m){
			a[i][j] = s[j] ;   
		}
		//char nl ; 
		//scanf("%c",&nl) ; 
	}
	forn(i,n){
		forn(j,m){
			res[i][j] = plusLen(i,j,n,m) ; 
		}
	}
	
	vpp fin ; 
	forn(i,n){
		forn(j,n){
			if (a[i][j] == 'G'){
				fin.pb(mp(res[i][j],mp(i,j))) ; 
			}
		}
	}

	int ans = 0 ; int a1 =1  , a2 = 1 ; 
	forn(i,fin.size()){
		for(int j = i+1 ; j < fin.size() ; j++){
			if (!overlaps(fin[i],fin[j])){
				a1 = 4*fin[i].xx+1 ; 
				a2 = 4*fin[j].xx+1 ; 

				ans = max(ans,a1*a2) ; 
			}
		}
	}
	cout << ans << el ; 
	return 0 ; 

}