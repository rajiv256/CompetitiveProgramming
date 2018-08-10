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

// Two test cases TLE.
int main() {
	int n ; sci(n) ;
	string a , b ; cin >> a ; cin >> b ; 
	vi v ; 
	forn(i,b.size()){
		if (b[i] == a[0])
			v.pb(i) ; 
	}
	//v.rsz(v.size()) ; 
	int len = 0 ,maxl = 0 , maxi = -1 ; 
	forn(i,v.size()){
		//cout << v[i] << el; 
		len = 0 ; 
		int j = 0 ; 
		if (maxl >= 2*n - v[i] )
			break ;
		while ((a[j] == b[(v[i]+j)%b.size()]) && j < n){
			len += 1 ; 
			j++ ; 
		}
		if (maxl < len){
			maxl = len ; maxi = v[i] ; 
		}
		if (maxl == n){
			break ; 
		}
	}
	cout << maxi << el ; 
	return 0 ; 
}