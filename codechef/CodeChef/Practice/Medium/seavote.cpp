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

int main(){
	int T ; scanf("%d",&T) ;  
	while (T--){
		int N ; scanf("%d",&N) ;  
		int sum1 = 0 , sum2 = 0 ; int temp = 0 ; 
		forn(i,N){
			scanf("%d",&temp) ; 
			if (temp == 0){
				sum1 += temp ; 
				sum2 += temp ; 
			}
			else {
				sum1 += temp ; 
				sum2 += temp-1 ;	
			}
			 
		}
		if (sum2 < 100 && sum1 >= 100){
			cout << "YES\n" ; 
		}
		else {
			cout << "NO\n" ; 
		}
	}
	return 0 ; 
}