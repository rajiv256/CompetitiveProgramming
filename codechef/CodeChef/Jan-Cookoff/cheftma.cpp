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
#define pb push_back
#define MXN 100003 
#define MOD 1000000007
#define prntv(v) forn(i,v.size()){cout<<v[i]<<sp;}cout<<el
#define mp(a,b) make_pair(a,b)
#define fi(x) x.first
#define se(x) x.second 
#define sci(x) scanf("%d",&x)

int A[MXN], B[MXN] ,C[MXN], D[MXN] ; 


int main() {
	int T ; sci(T) ; 
	while (T--){
		int N, K , M ; 
		sci(N) ; sci(K) ; sci(M) ; 
		memset(A,0,sizeof(A)) ; 
		memset(B,0,sizeof(B)) ; 
		memset(D,0,sizeof(C)) ; 

		forn(i,N){
			sci(A[i]) ; 
		}
		forn(i,N){
			sci(B[i]) ; 
		}
		forn(i,N){
			D[i] = A[i]-B[i] ; 
		}
		forn(i,K+M){
			sci(C[i]) ; 
		}
		sort(D, D+N,std::greater<int>()) ; 
		sort(C,C+K+M,std:: greater<int>()) ; 
		/*forn(i,K+M){
			cout << C[i] << sp ; 
		}
		cout << el ;*/
		int ans = 0 ; int j = 0 ;  
		forn(i,N){
			while (j < K+M){
				if (D[i] >= C[j]){
					D[i] = D[i] - C[j] ; 
					j++ ;
					break ; 
				}
				j++ ; 
			}
			if (j == K+M){
				break ; 
			}
		}
		forn(i,N){
			ans += D[i] ; 
		}
		printf("%d\n",ans) ; 

		/*int buff[C[0]+3] ;
		memset(buff,0,sizeof(buff)) ; 

		buff[C[0]] = C[0] ; 
		int k = 0 ; 
		for (int i = C[0]-1 ; i >= 0 ; i--){
			int j = C[k+1] ;
			if (i >= C[k+1]){
				buff[i] = C[k+1] ; 
			} 
			else {
				k = k + 1 ; 
				buff[i] = C[k+1] ; 
			}
		}
		buff[0] = 0 ; 
		int ans = 0 ; 
		forn(i,C[0]+1){
			cout << buff[i] << sp ; 
		}
		cout << el  ; 
		forn(i,N){
			cout << D[i] << sp << buff[D[i]] << el ; 
			ans += D[i] - buff[D[i]] ; 
		}
		cout << ans << el ; 
*/
	} 
	return 0 ;
}