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

ll arr[100][100][100][100] ;


ll solve(int a , int b , int c , int d,int pre){
	cout << a << sp << b << sp << c << sp << d <<sp << pre << el ; 
	if ( arr[a][b][c][d] != -1){
		return arr[a][b][c][d] ; 
	}
	if (a == 0 && b == 0 && c == 0 && d == 0){
		arr[0][0][0][0] = 1 ; 
		return 1 ; 
	}
	
	if (pre == 0){
		if (a == 0 && b!= 0){
			arr[a][b-1][c][d] = solve(a,b-1,c,d,1) ; 
			return arr[a][b-1][c][d] ; 
		}
		else if (b == 0 && a!= 0){
			arr[a-1][b][c][d] = solve(a-1,b,c,d,0) ; 
			return arr[a-1][b][c][d] ; 
		}
		else if (b == 0 && a== 0){
			arr[a][b][c][d] = 0 ; 
			return arr[a][b][c][d] ;  
		}
		else {
			arr[a][b-1][c][d] = solve(a,b-1,c,d,1) ; 
			arr[a-1][b][c][d] = solve(a-1,b,c,d,0) ; 
			return (arr[a-1][b][c][d]+arr[a][b-1][c][d] ) ; 		
		}
	}
	if (pre == 1){
		if (c==0 && d!= 0){
			arr[a][b][c][d-1] = solve(a,b,c,d-1,0) ; 
			return arr[a][b][c][d-1] ; 
		}
		else if (c != 0 && d == 0){
			arr[a][b][c-1][d] = solve(a,b,c-1,d,1) ; 
			return arr[a][b][c-1][d] ;  
		}
		else if (c == 0 && d == 0){
			arr[a][b][c][d] = 0 ; 
			return arr[a][b][c][d] ; 
		}
		else {
			arr[a][b][c-1][d] = solve(a,b,c-1,d,1) ; 
			arr[a][b][c][d-1] = solve(a,b,c,d-1,0) ; 
			return (arr[a][b][c][d-1]+ arr[a][b][c-1][d]) ; 
		}
	}

}



int main(){
	int a , b , c , d ; 
	cin >> a >> b >> c >> d ; 
	
	memset(arr,-1,sizeof(arr)) ; 

	arr[0][0][0][0] = 1 ; 

	arr[a][b][c][d] = solve(a,b,c,d,0) + solve(a,b,c,d,1) ; 
	 

	cout << arr[a][b][c][d] % MOD << el ; 


	return 0 ; 
}