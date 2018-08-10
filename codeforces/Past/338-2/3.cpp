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
#include <bits/stdc++.h> 
 
 
using namespace std ;
 
#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp ' '
#define el '\n'
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define pb push_back
#define MXN 100003 
#define MOD 1000000007

#define mp(a,b) make_pair(a,b)
#define fi(x) x.first
#define se(x) x.second 
#define sci(x) scanf("%d",&x)
#define pii pair<int,int>
#define ff first 
#define ss second 
#define mem(x,n) memset(x,n,sizeof(x))  
#define abs(a) ((a > 0 ? a : -a))




typedef vector<int> vi ; 
typedef vector<char> vc ;
typedef vector<pair<int,int> > vpii ;
//typedef vector<pair<ll,ll> > vpll ;
typedef vector<pair<int,pair<int,int> > > vpp ; 
typedef vector<bool> vb ;
typedef set<int> si ; 
typedef map<int,int> mii ; 
typedef map<int,vector<int> > miv ; 
typedef unsigned long long ull ; 
typedef long long ll ; 

int abs(int a){
	if (a > 0)
		return a ; 
	return -a ; 
}



int main(){
	string s , t ; 
	cin >> s >> t ; vpii result ;
	vi sc(26,0) ; vi tc(26,0) ; 
	forn(i,s.size()){
		sc[s[i]-'a'] += 1 ; 
	}
	forn(i,t.size()){
		tc[t[i]-'a'] += 1 ; 
	}
	int rep = 0 ; int maxi = 0 ; 
	forn(i,26){
		if (tc[i] != 0){
			if (sc[i] == 0){
				cout << "-1" ; 
				return 0 ; 
			}
		}
	}
	map<int,vi > m ; 
	forn(i,s.size()){
		m[s[i]-'a'].pb(i) ; 

	}
	
	int tt = 0 ; 
	while (tt < t.size()){
		int ll = -1  , rl = -1; 
		int curr = 0  , maxi = -1 , res = 0 ; 
		//cout << tt << el ; 
		//cout << t[tt] << sp << m[t[tt]].size() << el ; 
		forn(j,m[t[tt]-'a'].size()){
			//cout << "Enter" ; 
			curr = m[t[tt]-'a'][j] ; 
			int lr = 0 , rr = 0 ; 
			int ttt1 = tt+1 , ttt2 = tt+1 ; 
			int k1 ; 
			for(k1 = curr-1 ; k1 >= 0 ; k1--){
				if (s[k1] == t[ttt1]){
					ttt1 += 1 ; 
					lr += 1 ; 
				}
				else {
					break ; 
				}
			}
			k1 += 1 ; 
			int k2 ; 
			for (k2 = curr + 1 ; k2 < s.size() ; k2++){
				if (s[k2] == t[ttt2]){
					ttt2 += 1 ; 
					rr += 1 ; 
				}
				else{
					break ; 
				}
			}
			k2 -= 1 ; 
			int lll , lrl ; 
			if (lr > rr){
				lll = curr ; lrl = k1 ; 

			}
			else {
				lll = curr ; lrl = k2 ; 
			}
			//lll += 1 ; lrl += 1 ; 
			//cout << lll << sp << lrl << el ; 
			if (abs(lrl - lll) > maxi ){
				maxi = abs(lrl - lll) ; 
				ll = lll ; rl = lrl ; 
			}

		}
		tt += abs(rl-ll)+1 ; 

		result.pb(mp(ll,rl)) ; 

	}
	cout << result.size() << el ; 
	forn(u , result.size()){
		cout << result[u].ff+1 << sp << result[u].ss+1 << el ; 
	}
	return 0 ; 
}