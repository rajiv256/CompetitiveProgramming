/*
	Resilience is the greatest of all virtues.
	Code by rajiv
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <sys/time.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <cmath>

using namespace std ;

#define xx first
#define yy second
#define ll long long
#define ld long double
#define el (char)0x0A
#define sp " "
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define clr(x) memset((x),0,sizeof(x))
#define uint unsigned int
#define CASET  int t;cin>>t;while(t--)
#define forn(i,x,y) for(int i=x;i<y;i++)
#define maxn 100005
#define inf 10000000010
#define mod 1000000007
#define last_set_bit(x) log2((x)&(-x))
#define add(x,y) (x)=((x)+(y))%MOD
#define PI 3.141592653589793

typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

int main(){
	int n , m , h ; cin >> n >> m >> h ; 
	int c[m] ; int r[n] ; int t[n][m] ;
	forn(i,0,m) cin >> c[i] ; 
	forn(i,0,n) cin >> r[i] ; 
	forn(i,0,n) forn(j,0,m) cin >> t[i][j] ; 
	int ans[n][m] ; 
	int mark[n][m] ; 
	memset(mark, false, sizeof mark) ; 
	forn(i,0,n){
		forn(j,0,m){
			if (t[i][j] == 0){
				ans[i][j] = 0 ; 
			}
			else{
				ans[i][j] = -1 ; 
			}
		}
	}
	for(int j = 0 ; j < m ; j++){
		for(int i = 0 ; i < n ; i++){
			if (ans[i][j] == -1){
				if (c[j] <= r[i]){
					ans[i][j] = c[j] ; 
					break ; 
				}
				
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		
		for(int j = 0 ; j < m ; j++){
			if (ans[i][j] == -1){
				int maxi = ans[0][j] ; 
				for(int k = 0 ; k < n ; k++){
					maxi = max(maxi,ans[k][j]) ; 
				}
				if (maxi >= r[i] || maxi <= 0){
					ans[i][j] = r[i] ; 
					break ; 
				}
				else{
					continue ; 
				}
			}
		}
	}

	forn(i,0,n) forn(j,0,m) if (ans[i][j] == -1) ans[i][j] = 1 ; 

	forn(i,0,n){
		forn(j,0,m){
			cout << ans[i][j] << sp;
		}
		cout << el ; 
	}
	return 0 ;


}
































//}
