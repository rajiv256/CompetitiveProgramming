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

int n , q , c, u , v , k , p ,a ,b ; 

int A[1000003] = {0} ; 
int B[1000003] = {0} ; 

void update(){
	A[u] += k ; A[v+1] -= k ; 
}
void query(){
	B[0] = A[0] ; 
	for (int i = 1 ; i < n ; i++){
		B[i] += B[i-1] ; 
	}
}

int main() {
	scanf("%d%d%d",&n,&q,&c) ; 
	forn(i,n) {
		A[i] = c ; 
	}
	char ch ; int qq = 0 ; 
	while (qq < q){
		
		scanf("%c",&ch) ; 
		if (ch == 'S'){
			scanf("%d%d%d",&u,&v,&k) ; u-- ; v-- ;  
			update() ; 
			qq += 1 ; 
			continue ;
		}
		if (ch == 'Q'){
			scanf("%d",&p) ; p-- ; 
			query() ; 
			cout << B[p] << el ; 
			memset(B,0,sizeof(B)) ; 
			qq += 1 ; 
			continue ; 
		}
	}
	return 0 ; 
}