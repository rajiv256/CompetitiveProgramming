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
#define SZ 500003
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

int** buff ; 

int exp(int a , int b){
	if (b == 0)
		return 1 ; 
	int k = exp(a,b-1); 
	return a*k ; 
}

double logx(int a , int b){
	return (log2(a)/log2(b)) ; 
}

int check_palin(vc& v , int st , int en , int p){
	//cout << st << sp << en << el  ; 
	
	int fi = exp(p,st) ; int ei = fi*(exp(p,en-st)) ; 
	if (v[fi] != v[ei]){ 
		return 0 ; 
	}
	else {
		if (st == en || st+1 == en){
			return 1 ; 
		}
		else {
			//buff[st][en] = buff[st+1][en-1] = check_palin(v,st+1,en-1,p) ; 
			return  check_palin(v,st+1,en-1,p) ; 
		}
	}
}
int main(){
	int T ; sci(T) ;  
	//cout <<"Atleast here" ;

	while (T--){
		
		vc v ; 
		
		v.pb('@') ;  
		char c ; 
		scanf("%c",&c) ; 
		int ind = 1 ; 
		while (true){
			scanf("%c",&c) ; 
			if (c == '\n')
				break ;
			v.pb(c) ;   
		}
		v.rsz(v.size()) ; 

		int N = v.size()-1 ; 
		
		int p = 2 , count = 0 ; 

		for(p = 2 ; p <= N ; p++){
			//cout << p <<" @" <<sp;
			for(int st = 0 ; exp(p,st) <= N ; st++){
				//count++ ;
				//cout << st << " $" << sp ;  
				for(int en = st ; exp(p,en)<= N ; en++){
					//cout <<p << sp << st << sp <<  en  << el ;  
					if (!(st == 0 && en == 0))
					if (check_palin(v,st,en,p)){
						count++ ; 
						//cout << "YES" ; 
					}
					//cout << el ; 
				}
			}
		}
		for(int p1 = 2 ; p1 <= N ; p1++){
			for (int j = 2 ; exp(p1,j) <= N ; p1++){
				count-- ; 
			}
		}
		count += 1; 
		cout << count << el ; 



	}
	return 0 ; 
}