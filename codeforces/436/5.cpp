/* 
        Code written by rajiv. 
        God speed!
*/
#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(ll i=st;i<en;i++)
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

typedef vector<ll> vi ; typedef vector<char> vc ; typedef vector<pair<ll,ll> > vp ; typedef vector<vector<ll> > vvi ;
typedef vector<vector<pair<ll,ll> > > vvp  ;typedef vector<pair<pair<ll,ll>,ll > > vpp ;typedef vector<bool> vb ;
typedef set<ll> si ;typedef map<ll,ll> mii ;typedef map<ll,vector<ll> > miv ; typedef unsigned long long ull ; 

int main(){
	ll n ; scll(n) ; 
	ll dis[102] ; 
	ll pis[102] ; 
	ll tis[102] ; 
	vector<pair<pair<ll,pair<ll,ll> >,ll> > vv ; 
	forn(i,1,n+1){
		scll(tis[i]); scll(dis[i]) ; scll(pis[i]) ;
		vv.pb(mp(mp(dis[i],mp(tis[i],pis[i])),i)) ;  
	}
	sort(all(vv)) ; 
	for(ll i= 0 ; i < n ; i++){
		dis[i+1] = vv[i].xx.xx ; 
		tis[i+1] = vv[i].xx.yy.xx ; 
		pis[i+1] = vv[i].xx.yy.yy ; 
	}

	ll dp[102][2002] ; clr(dp) ; pair<ll,ll> parent[102][2002]  ; 
	for(ll i = 0 ; i <= 101 ; i++){
		forn(j,0,2002){
			parent[i][j] = mp((ll)-1,(ll)-1) ; 
		}
	} 
	
	for(ll i = 1 ; i <= n ; i++){
												//dp[i][j] is given I is the last element taken at time 'j' 
		for(ll j = 0 ; j < 2002 ; j++){

			for(ll k = 0 ; k < i ; k++){

				dp[i][j] = max(dp[k][j],dp[i][j]) ; 


				if (j <= dis[i]){

					if (j-tis[i] > 0){

						if (dp[i][j] < dp[k][j-tis[i]]+pis[i]){
							
							dp[i][j]  = dp[k][j-tis[i]]+pis[i] ; 
							
							parent[i][j] = mp(k,j-tis[i]) ; 
						
						}
					}
				}	
			}
		}
	}

	ll ans = 0 ; pair<ll,ll> root = mp((ll)0,(ll)0) ; 
	for(ll i = 1 ; i <= n ; i++){
		for(ll j =0 ; j < 2002 ; j++){
			if (ans < dp[i][j]){
				ans = dp[i][j] ; 
				root = mp(i,j) ; 
			}
		}
	}
	vector<ll> v ; 
	while (root != mp((ll)-1,(ll)-1)){
				
		v.pb(vv[root.xx-1].yy) ; 
		root = parent[root.xx][root.yy] ; 
	}
	cout << ans << el ; 
	cout << v.size()-1 << el ; 
	reverse(v.begin(),v.end()-1) ; 
	forn(i,0,v.size()-1){
		cout << v[i] << sp ; 
	}
	cout << el ; 


}