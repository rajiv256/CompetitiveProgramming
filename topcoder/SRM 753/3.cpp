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




class MaxCutFree {
	public:
	int adj[1003][1003] ;
	int bri[1003][1003] ;
	int L[1003][2] ;

void dfs(int s, VB& vis, int n){

	vis[s] = true ;
		forn(i, 0, n){
		if (adj[s][i] && !vis[i] && i != s){
			dfs(i, vis, n) ;
		}
	}
return ;

}

int ncomp(int n){
	VB vis(n, false) ;
	int cnt = 0 ;
	for(int i = 0 ; i < n ; i++){
		if (!vis[i]){
			dfs(i, vis, n) ;
		}
	}
	return cnt ;
}
bool is_bridge(int x, int y, int n){
	int nc = ncomp(n) ;
	adj[x][y] = 0 ;
	adj[y][x] = 0 ;
	int nownc = ncomp(n) ;
	return (nc+1 == nownc) ;
}

int dp(int s, int p, int fl, int n){
	if (L[s][fl] != -1) return L[s][fl] ;
	int ret = 0 ;
	if (fl == 0){
		for(int i = 0 ; i < n ; i++){
			if (adj[s][i] && i!=s && i != p){
				L[i][1] = dp(i, s, 1,n) ;
				L[i][0] = dp(i, s , 0,n) ;
				ret += max(L[i][1], L[i][0]) ;
			}
			return ret ;
		}
	}
	if (fl == 1){
		for(int i = 0 ; i < n ; i++){
			if (adj[s][i] && i != s && i != p) {
				L[i][0] = dp(i,s ,0,n) ;
				ret += L[i][0] ;
			}
		}
		return 1+ret ;
	}
	return 0 ;
}

	int solve(int n, vector <int> a, vector <int> b) {


		memset(adj,0,sizeof adj) ;

		forn(i,0,a.size()){
			adj[a[i]][b[i]] = 1 ;
			adj[b[i]][a[i]] = 1 ;
		}
		for(int i = 0 ; i < a.size() ; i++){
			if (is_bridge(a[i], b[i], n)){
				bri[a[i]][b[i]] = 1 ;
				bri[b[i]][a[i]] = 1 ;
			}
		}
		for(int i = 0 ; i < n ; i++) {
			L[i][0] = -1  ; L[i][1] = -1 ;
		}
		for(int i = 0 ; i < n ; i++){
			if (L[i][0] == -1){
				L[i][0] = dp(i, -1, 0, n) ;
			}
			if (L[i][1] == -1){
				L[i][1] = dp(i,-1,1,n) ;
			}
		}
		int ans = L[0][0] ;
		for(int i = 0 ; i < n ; i++){
			ans = max(max(L[i][0], L[i][1]),ans) ;
		}
		return ans ;


	}
};

<%:testing-code%>
// Powered by PopsEdit
