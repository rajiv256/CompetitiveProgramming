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
#define MXN 100000
#define MOD 1000000007
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

int arr[30005] ; 

int findMatch(int curr, string s){
	int maxi = 0 ; 
	int temp = curr ; 
	for(int i = 0 ; i < curr ; i++){
		if (s[i]== s[curr]){
			temp = curr ; int start = i ; int len = 0 ; 
			while (temp < s.size() && start < curr ){
				if (s[temp] == s[start]){
					len++ ; temp++ ; start++ ; 
				}
				else {
					break ; 
				}
				
			}
			maxi = max(maxi, len) ; 
		}
	}
	return maxi ; 
}

int solve(vi& lcs , int pre,int a , int b , int n){
	if (arr[pre] != -1)
		return arr[pre] ; 
	if (pre >= n){
		return 0 ; 
	}	
	if (lcs[pre] == 0){
		arr[pre+1] = solve(lcs,pre+1,a,b,n) ; 
		return a+arr[pre+1] ; 
	}
	else {
		arr[pre+1] = solve(lcs,pre+1,a,b,n) ; 
		arr[pre+lcs[pre]] = solve(lcs,pre+lcs[pre], a, b , n) ; 
		return (min(a+arr[pre+1], b+arr[pre+lcs[pre]])) ; 
	}
}

int main(){
	
	int t ; cin >> t ; 
	while (t--){
		memset(arr,-1,sizeof(arr)) ; 
		int n , a , b ; cin >> n >> a >> b ; 
		string s ; cin >> s ; 
		// map<char,vi > m ; 
		// forn(i,s.size()) {
		// 	m[s[i]].pb(i) ; 
		// }
		int mini = a ; 
		int curr = 1 ; 
		int len = 0 ; 
		vi lcs ; lcs.rsz(n) ; 
		
		lcs[0] = 0 ; 
		for(int i =1 ; i < n  ; i++){
			lcs[i] = findMatch(i,s) ; 
		}
		arr[1] = solve(lcs,1,a,b,n) ; 
		mini += arr[1] ; 
		cout << mini << el ; 
	}

	return 0 ; 
}