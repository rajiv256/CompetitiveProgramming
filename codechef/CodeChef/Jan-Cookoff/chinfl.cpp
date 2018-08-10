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
typedef vector<vector<pair<int,int > > > vvp ; 
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
#define pb push_back
#define MXN 100003 
#define MOD 1000000007
#define prntv(v) forn(i,v.size()){cout<<v[i]<<sp;}cout<<el
#define mp(a,b) make_pair(a,b)
#define fi(x) x.first
#define se(x) x.second 
#define sci(x) scanf("%d",&x)
#define ff first 
#define ss second

int N , M , D ; 


ull ans = 0 ;
ull buff[1000][1000] ; 

int abs(int a){
	if (a >= 0 ){
		return a ; 
	}
	else 
		return -a ; 
}




ull solve(vvp& table,int time,int i ,int pc , int d) {
	cout << i << sp << time <<sp << pc << sp << d << el ; 
	if (time >= M){
		return pc ; 
	}
	if (buff[i][time] != 0){
		return buff[i][time] ; 
	}
	ull maxi = 0 ; 
	
}







int main(){
	sci(N) ; sci(M) ; sci(D) ; 
	vp v ; 
	vvp table(N,v) ;
	int s , b ; 

	forn(i,N) {
		forn(j,M){
			sci(s) ; sci(b) ;
			table[i].pb(mp(s,b)) ;		
		}
	} 
	memset(buff,0,sizeof(buff)) ; 
	int time = 0 ; ull maxi = 0 ; int pc = D ; int d = 0 ; 
	forn(i,N){
		cout << i << el ; 
		buff[i][0] = solve(table,time,i,pc,d) ;
		maxi = max(maxi,buff[i][0]) ;  	
	}
	cout << maxi << el ; 

					
}
