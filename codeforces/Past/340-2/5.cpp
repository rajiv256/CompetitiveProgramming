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

int a[100003] ; 
//int L[100003][100003] ; 

int main(){
	int n , m , k ; 
	cin >> n >> m >> k ;
	
	memset(a,0,sizeof(a)) ; 
	forn(i,n){
		sci(a[i]) ; 
	}
	//int x[n] ; 
	//x[0] = a[0] ; 
	for(int i = 1 ; i < n ; i++){
		a[i] = a[i]^a[i-1] ; 
	}
	
	// int **L = (int**)malloc(sizeof(int*)*n) ; 
	// forn(i,n){
	// 	L[i] = (int*)malloc(sizeof(int)*n) ; 
	// }

	// forn(i,n){
	// 	forn(j,n){
	// 		if (i == 0){
	// 			L[i][j] = a[j] ; 
	// 		}
	// 		else {
	// 			L[i][j] = a[j]^a[i-1] ; 
	// 		}
	// 		//cout << L[i][j] << sp ; 
	// 	}
	// 	//cout << el ; 
	// }
	int l , r ; 
	while (m--){
		cin >> l >> r ; l-- ; r-- ;   
		int ans =  0; 
		for(int i = l ; i <= r ; i++){
			for(int j = l ; j <= r ; j++){
				if (i <= j ){
					if (i == 0 && a[j] == k)
						ans += 1 ;
					if (i != 0 && (a[j]^a[i-1]) == k)
						ans += 1 ;  
				}
			}
		}
		cout << ans << el ; 
		ans = 0 ; 
	}	
	return 0 ; 
}