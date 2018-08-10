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

char a[1003][1003] ; 
int buff[1003][1003] ; 
int l, r , q , k ; 

int solve(int i , int j , char c){
	if (buff[i][j] != -1)
		return buff[i][j] ; 
	if (a[i+1][j] != c || a[i][j+1] != c || a[i+1][j+1] != c){
		return 1 ; 
	}
	
	if (a[i+1][j] == c && a[i][j+1] == c && a[i+1][j+1] == c){
		
		if (buff[i+1][j] == -1)
			buff[i+1][j] = solve(i+1,j,c) ; 
		if (buff[i][j+1] == -1)
			buff[i][j+1] = solve(i,j+1,c) ; 
		if (buff[i+1][j+1] == -1)
			buff[i+1][j+1] = solve(i+1,j+1,c) ; 
		
		return (1+min(buff[i+1][j],min(buff[i][j+1],buff[i+1][j+1]))) ;  

	}

}


int main(){
	sci(l) ; sci(r) ; sci(q) ;
	memset(a,'0',sizeof(a)) ; 
	memset(buff,-1,sizeof(buff)) ; 

	char enl ; 
	forn(i,l){
		string s ; cin >> s ; 
		forn(j,r){
			a[i][j] = s[j] ; 
		}
		 
	} 
	forn(i,l){
		forn(j,r){
			if (buff[i][j] == -1){
				buff[i][j] = solve(i,j,a[i][j]) ; 
			}
			
		}
	}
	
	bool finM[1003] ;
	bool finF[1003] ;  
	memset(finM,false,sizeof(finM)) ; 
	memset(finF,false,sizeof(finF)) ; 
	
	forn(i,l){
		forn(j,r){
			if (a[i][j] == 'M')
				finM[buff[i][j]] |= true ; 
			if (a[i][j] == 'F')
				finF[buff[i][j]] |= true ; 
		}
	}
	int k ; char c ; 
	while (q--){
		sci(k) ; string s1 ; cin >> s1 ; 
		if (s1[0] == 'M'){
				if (finM[k]){
					cout << "yes" << el ; 
					continue ; 
				}
				else {
					cout << "no" << el ; 
			}		
		}
		else {
			if (finF[k]){
				cout << "yes" << el ; 
			}
			else {
				cout << "no" << el  ; 
			}
		}  
		
	}
	return 0 ; 

}