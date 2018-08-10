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
#define hashp 999983 

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 

int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 

	int t ; cin >> t ; 
	while (t--){
		int n ; cin >> n ; 
		if (n == 2){
			int m ; cin >> m ; 
			
			ll max1=INT_MIN , min1 = INT_MAX ;
			
			forn(j,0,m){
				ll x ; cin >> x ; max1 = max(max1,x) ; min1 = min(min1,x) ;  
			} 
			
			cin >> m ; 
			ll max2 = INT_MIN , min2 = INT_MAX ; 
			forn(j,0,m){
				ll x ; cin >> x ; max2=max(max2,x) ; min2 = min(min2,x) ; 
			}
			
			vector<ll> va ; va.pb(min1); va.pb(max1) ; 
			vector<ll> vb ; vb.pb(max2) ; vb.pb(min2) ; 
			
			ll ans = 0 ; 
			forn(i,0,va.size()){
				forn(j,0,vb.size()){
					ans = max(ans,abs(va[i]-vb[j])) ; 
				}
			}
			
			cout << ans << el ; 
			continue ; 
		}
		vector<vector<ll> > v(n,vector<ll>()) ;
		for(int i = 0 ; i < n ; i++){
			int m ; cin >> m ; 
			forn(j,0,m){
				ll x ; cin >> x ; 
				v[i].pb(x) ; 
			}
		} 
		
		vector<vector<pair<ll,ll> > > pairs(n,vector<pair<ll,ll> >()) ; 
		for(int i = 0 ; i < n ; i++){
			
			pairs[i].pb( mp( i*v[i][0] , v[i][v[i].size()-1]*(i+1) ) ) ;

			for(int j = 1 ; j < v[i].size() ; j++){
				
				pairs[i].pb(mp(i*v[i][j],(i+1)*v[i][j-1])) ; 
			
			}
		}

		vector<vector<ll> > dp(n,vector<ll>()) ;
		for(int i= 0 ; i < n ; i++){
			forn(j,0,v[i].size()){
				dp[i].pb((ll)0) ; 
			}
		} 

		for(int i = 0 ; i < n-1 ; i++){
			for(int j = 0 ; j < v[i].size() ; j++){
				for(int k = 0 ; k < v[i+1].size() ; k++){

					dp[i+1][k] = max(dp[i+1][k],dp[i][j]+abs(pairs[i+1][k].xx-pairs[i][j].yy)) ; 
				}
			}
		}
		ll maxi = 0 ; 
		for(int i = 0 ; i < v[n-1].size() ; i++){
			maxi = max(maxi,dp[n-1][i]) ; 
		}
		cout << maxi << el ; 

	} 
}