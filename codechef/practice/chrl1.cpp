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
#define MXN 1000005
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

ll maxwt = 0 ; 
ll N  , K  , W ; 
ll cost[12] ;
ll weight[12] ;  
ll a[12] ; 

void solve(int idx, ll spent, ll wt){
	if (idx == N){
		if (spent <= K){
			maxwt = max(maxwt,wt) ; 
		}
		return ; 
	}
	solve(idx+1,spent,wt) ; 
	solve(idx+1,spent+cost[idx],wt+weight[idx]) ; 
}







int main(){

	int t ; sci(t) ; 
	while (t--){
		scll(N) ; scll(K) ; 
		clr(cost) ; clr(weight) ; clr(a) ; 
		for(int i = 0 ; i < N ; i++){
			scll(cost[i]) ; scll(weight[i]) ;  
		} 
		maxwt = 0 ; 
		solve(0,0,0) ; 
		printf("%lld\n", maxwt);

	}


}