/* 
        Code written by rajiv. 
        God speed!
*/
#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define sclf(x) scanf("%lf",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100005
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 

int dp[10005] ; 

int main(){
	int t ; sci(t) ; 
	


	forn(i,0,10005){
		dp[i] = INF ; 
	}
	for(int i = 1 ; i*i < 10005 ; i++){
		dp[i*i] = 1 ; 
	}
	for(int i = 2 ; i < 10005 ; i++){
		for(int j = 1 ; j*j < i ; j++){
			dp[i] = min(dp[i],dp[j*j]+dp[i-j*j]) ; 
		}
	}
	int kase = 1 ; 

	while (t--){
		int n ; sci(n) ; 
		printf("Case #%d: %d\n",kase++, dp[n] );
	}
}