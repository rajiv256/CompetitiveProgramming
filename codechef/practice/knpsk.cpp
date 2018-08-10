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


int main(){

	ll n ; scll(n) ; 
	vector<ll> ones ; vector<ll> twos ; 
	ll c , w ; ll sum = 0 ; 
	for(int i = 0 ; i < n ; i++){
		scll(w) ; scll(c) ; 
		sum += w ; 
		if (w==1) ones.pb(c) ; 
		else twos.pb(c) ; 
	}
	sort(all(ones),greater<int>()) ;
	sort(all(twos),greater<int>()) ; 

	for(int i = ones.size() ; i < 2*MXN+1 ; i++){
		ones.pb((ll)-1000000003) ; 
	}
	for(int i = twos.size() ; i < 2*MXN+1 ; i++){
		twos.pb(-1000000003) ; 
	}

	pair<pair<ll,ll>,ll> dp[2*MXN] ; 

	dp[0] = mp(mp(-1,-1),0) ; 
	dp[1] = mp(mp(0,-1),ones[0]) ; 

	for(int i = 2 ; i <= sum ; i++){
		pair<pair<ll,ll>,ll> oneless, twoless ; 
		oneless = dp[i-1] ; ll o1 = oneless.xx.xx ; ll o2 = oneless.xx.yy ; ll ov = oneless.yy ; 
		twoless = dp[i-2] ; ll t1 = twoless.xx.xx ; ll t2 = twoless.xx.yy ; ll tv = twoless.yy ; 

		ll ret = ov+ones[o1+1] ; 
		dp[i] = mp(mp(o1+1,o2),ret) ; 

		ll k1 = ones[t1+1]+ones[t1+2] ; 
		ll k2 = twos[t2+1] ; 
		if ( k1 >= k2){
			if (dp[i].yy < k1+tv){
				dp[i] = mp(mp(t1+2,t2),k1+tv); 
			}
		}
		else {
			if (dp[i].yy < k2+tv){
				dp[i] = mp(mp(t1,t2+1),k2+tv); 
			}
		}
	}
	ll maxcosttill = dp[0].yy ; 
	for(int i = 1 ; i <= sum ; i++){
		if (maxcosttill <= dp[i].yy){
			maxcosttill = dp[i].yy ; 
		}
		else{
			dp[i].yy = maxcosttill ; 
		}
	}

	for(int i = 1 ; i <= sum ; i++){
		printf("%lld ", dp[i].yy);
	}


	return 0 ; 

}
























