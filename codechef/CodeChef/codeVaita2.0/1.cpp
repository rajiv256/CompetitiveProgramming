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

double a[1000003] ; 
int n , q ; 

int binSearch(double num , int st , int en){
	int mid = (st+en)/2 ; 
	if (st == en){
		if (a[st] == num){
			return st ; 
		} 
		else if (num < a[st]){
			return st-1 ; 
		}
		else{
			return st+1 ; 
		}
	}
	if (num == a[mid]){
		return mid ; 
	}
	else if (num < a[mid]){
		return binSearch(num,st,mid) ; 
	}
	else {
		return binSearch(num,mid+1,en) ; 
	}
}








int main(){
	int T ; sci(T) ; 
	while (T--){
		memset(a,0.0,sizeof(a)) ; 
		sci(n) ; sci(q) ; 
		forn(i,n){
			scanf("%lf",&a[i]) ; 
		}
		sort(a,a+n) ; 
		int res = 0 ; double num = 0.000 ; int ans = 0 ; 
		while (q--){
			scanf("%lf",&num) ; 
			res = binSearch(num,0,n-1) ; 
			ans = max(0,n-res-1) ; 
			printf("%d\n",ans) ; 
		}
	}
	return 0 ; 
}