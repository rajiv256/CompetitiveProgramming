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

int a[6][6] ; 

int main() {
	memset(a,0,sizeof(a)) ; 
	forn(i,6){
		forn(j,6){
			sci(a[i][j]) ; 
		}
	}
	int maxi = -100000 ; 
	forn(i,4){
		forn(j,4){
			int sum = 0 ; 
			sum += a[i][j] ; sum += a[i][j+1] ; sum += a[i][j+2] ; 
			sum += a[i+1][j+1] ; sum += a[i+2][j] ; sum += a[i+2][j+1] ; sum += a[i+2][j+2] ; 
			maxi = max(maxi, sum ) ; 
		}	
	}
	cout << maxi << el ; 
	return 0 ; 
}