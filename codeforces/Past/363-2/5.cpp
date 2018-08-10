#include <bits/stdc++.h>

using namespace std  ; 

#define ll long long 
#define el endl 
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define clear(x) memset(x,0,sizeof(x))
#define MXN 100003 
#define INF 10000000000
#define MOD 1000000007

double dp[(1<<20)+10] ; 
double ff[100] ; 
double ans[20] ; 
int n,k  ;
void solve(double pr , int idx, double a[]){
	if (fabs(pr)<=1e-9) {
		ans[idx] = 0.0 ; 
		return;
	}
	dp[0] = pr ; 
	 
	forn(i,0,n){
		ff[i] = 0 ; 
	}
	ff[0] = pr ; 
	
	forn(S,1,(1<<n)){
		if ((S&(1<<idx))==0){
			dp[S] = 0 ; 
			double prob = 1 ; 
			forn(j,0,n){
				if ((S&(1<<j))!=0){
					prob -= a[j] ; 
					dp[S] += dp[(S^(1<<j))]*a[j] ; 
 				}
			}
			dp[S]/= prob ; 

			ff[__builtin_popcount(S)] += dp[S] ; 
		}
	}
	double v =0.0  ; 
	forn(i,0,k) 
		v+=ff[i] ; 
	ans[idx] = v ; 




}
int main(){
	ios_base::sync_with_stdio(false) ; 
	cin.tie(0) ; 
	cin >> n >> k; 
	double a[n] ;
	clear(ans) ;  
	forn(i,0,n){
		cin >> a[i] ; 
	}
	forn(i,0,n){
		
		solve(a[i],i,a) ; 
	}
	forn(i,0,n){
		printf("%.10f\n",ans[i]) ; 
	}
}