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
	int n ; sci(n) ; 
	vi v ; v.rsz(n) ; 
	forn(i,n){
		sci(v[i]) ; 
	}

	vi buff ; int ans  = 0 ; 
	int flag = 0 ; 
	if (v[0] < 0) 
		flag = -1 ; 
	else 
		flag = 1 ; 
	int sum = 0 ; int pos = 0 ; 
	while (pos < n ){
		if (v[pos] > 0){
			if (flag == 1){
				sum += v[pos] ; 
				pos++ ; 
				continue ; 
			}
			else if (flag == -1){
				buff.pb(sum) ; 
				flag = 1 ; 
				sum = v[pos] ;
				pos++ ;  
				continue ; 
			}
		}
		if (v[pos] == 0){
			buff.pb(sum) ; 
			while (v[pos] == 0)
				pos++ ; 
			sum = 0 ; 
			buff.pb(0); 
			
			continue ; 
		}
		if (v[pos] < 0){
			if (flag == 1){
				buff.pb(sum) ; 
				flag = -1 ;
				sum = v[pos] ;  
				pos++  ; 
				continue ; 
			}
			else if (flag == -1){
				sum += v[pos] ; 
				pos++ ; 
				continue ; 
			}
		}
		
	}
	buff.pb(sum)  ;
	// forn(i,buff.size()){
	// 	cout << buff[i] << el ; 
	// }
	int asum = 0 ; int maxi = 0 ; 
	int k = 0 ; 
	while (k < buff.size()){
		if (buff[k] < 0){
			maxi = max(asum,maxi) ; 
			if (asum+buff[k] < 0){
				asum = 0 ; 
			}
			else {
				asum += buff[k] ; 
			}
			k++ ; 
			continue ; 
		}
		else if (buff[k] == 0){
			maxi = max(asum , maxi) ; 
			asum = 0 ; 
			k ++ ; 
			continue ; 
		}
		else {
			asum += buff[k] ; 
			k ++ ; 
			continue ; 
		}
	}
	maxi = max(asum , maxi) ; 
	cout << maxi << el ; 

}