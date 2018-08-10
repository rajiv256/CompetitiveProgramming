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
#define MXN 10003 
#define MOD 1000000007
#define prntv(v) forn(i,v.size()){cout<<v[i]<<sp;}cout<<el

int gcd(int a ,  int b){
	if (b == 0){
		return a ; 
	}
	if (b > a){
		return gcd(b,a) ; 
	}
	return gcd(b,a%b) ; 
}



int main() {
	int t ; scanf("%d",&t) ; 
	//sieve() ; 

	while(t--){
		int N ; scanf("%d",&N) ;
		int A[N] ; 
		memset(A,0,sizeof(A)) ;  
		forn(i,N){
			scanf("%d",&A[i]) ; 
		}
		int compensation = 0 ; 
		forn(i,N){
			for (int j = i+1 ; j < N ; j++){
				if (A[j] < A[i]){
					compensation += A[i] - A[j] ; 
					A[j] = A[i] ; 
				}
			}
		}
		//memset(C,false,sizeof(C)) ; 
		// if (lgcd(N) != 1){
		// 	cout << "0\n" ; 
		// 	//ans = 0 ; 
		// 	continue ; 
		// }
		/*int maxi = -1 ; 
		forn(i,N){
			maxi = max(maxi,A[i]) ; 
		}
		*/
		int ans = INT_MAX ;
		for (int i = 2 ; i <= 10003 ; i++){
			int res = 0 ; 
			forn(j,N){
				if (A[j]%i == 0){
					continue ; 
				}
				res += (i-(A[j]%i)) ; 
				if (res > ans){
					break ;
				}
			}
			ans = min(ans,res) ; 
		}

		cout << ans+compensation << el; 
	}
	return 0 ; 
}