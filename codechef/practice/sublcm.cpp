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


int last[MXN] ; 
bool prime[MXN] ; 
int dp[MXN/10+2] ; 
vvi divs(MXN,vector<int>()) ; 

void sieve(){
	memset(prime,true,sizeof(prime)) ; 
	
	for(int i = 2 ; i < MXN ; i++){

		if (!prime[i])continue ; 
		divs[i].pb(i) ; 
		for(int j = 2 ; i*j < MXN ; j++){
			prime[i*j] = false ; 
			divs[i*j].pb(i) ; 
		}
	}
}


int main(){
	
	sieve() ;  // filters primes  
	
	

	int t ; sci(t) ; 
	while (t--){
		int n ; sci(n) ; 
		int a[n+1] ; 
		forn(i,1,n+1){
			sci(a[i]) ; 
		}
		memset(dp,0,sizeof(dp)) ; 
		memset(last,0,sizeof(last)) ; 

		dp[1] = 1 ; 

		for(int i = 0 ; i < divs[a[1]].size() ; i++){
			last[divs[a[1]][i]] = 1 ; 
		}	
		

		for(int i = 2 ; i <= n ; i++){
			int ret = 0 ; 

			vi factors = divs[a[i]] ; 
			for(int j = 0 ; j < factors.size() ; j++){
				ret = max(ret,last[factors[j]]) ;
				last[factors[j]] = i ;  
			}
			dp[i] =  min(dp[i-1]+1,i-ret) ;  
		}

		int ans = 0 ; 
		for(int i =1 ; i <= n ;i++){
			ans = max(ans,dp[i]) ; 
		}
		printf("%d\n", (ans>1)?ans:-1);


	}

}