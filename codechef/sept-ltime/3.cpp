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
#define MOD 1000000009
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 

ll sum(ll x){
	if (x&1){
		return ((x/2+1)*(x/2+1)) ; 
	}
	else{
		return (x/2)*(x/2+1) ; 
	}
}

int main(){
	int t ; sci(t) ; 
	while (t--){
		ll N , K ; scll(N) ; scll(K) ;  

		ll idx[K] ; ll val[K] ; 

		forn(i,0,K){
			scll(idx[i]) ; scll(val[i]) ; 
			idx[i]-- ; 
		}

		if (K==0){
			printf("%lld\n", sum(N)) ;
			continue ; 
		}
		ll D[K-1] ; 
		for(int i = 0 ; i < K-1 ; i++){
			D[i] = idx[i+1]-idx[i] ; 
		}
		ll ans = 0 ; 
		
		// Case 1: Palindromes that contain only zeroes. 

		vector<ll> L0 ; 
		for(int i = 0 ; i < K ; i++){
			L0.pb(idx[i]-((i==0)?0:(idx[i-1]+1))) ; 
		}
		L0.pb(N-1-idx[K-1]) ; 

		for(int i = 0 ; i < L0.size() ; i++){
			ans += sum(L0[i]) ; 
		}

		vector<ll> Hv(K+1,0) , Hvi(K+1,0) , Hd(K,0) , Hdi(K,0) , pp(K+1,1) ; 
		ll mod = 1000000009 ; ll p = 999983 ; 

		for(int i =0; i < K; i++) Hv[i+1] =(p*Hv[i]+val[i]+1)%mod;
		for(int i =0; i < K-1; i++) Hd[i+1] =(p*Hd[i]+D[i])%mod;
		for(int i =K-1; i >= 0; i--) Hvi[i] =(p*Hvi[i+1]+val[i]+1)%mod;
		for(int i =K-2; i >= 0; i--) Hdi[i] =(p*Hdi[i+1]+D[i])%mod;
		for(int i =1; i <= K; i++) pp[i] =(pp[i-1]*p)%mod;


		// Case 2: Palindromes with centre as a non-zero number.

		for(ll i =0; i < K; i++) {
			// centered at P[i]
			ll a =0, b =min(i+1,K-i);
			while(b-a > 1) {
				ll c =(a+b)/2;
				ll hv =Hv[i+c+1]-Hv[i-c]*pp[2*c+1], hvi =Hvi[i-c]-Hvi[i+c+1]*pp[2*c+1];
				ll hd =Hd[i+c]-Hd[i-c]*pp[2*c], hdi =Hdi[i-c]-Hdi[i+c]*pp[2*c];
				if((hv-hvi)%mod == 0 && (hd-hdi)%mod == 0) a =c;
				else b =c;
			}
			ll l =idx[i]+1, r =N-idx[i];
			if(i-b >= 0) l =min(l,idx[i]-idx[i-b]);
			if(i+b < K) r =min(r,idx[i+b]-idx[i]);
			ans +=min(l,r);
		}


		// Case 3: Palindromes with centre as zero and contains atleast one non-zero number. 

		for(ll i =0; i < K-1; i++) if(D[i]%2 == 0 && val[i] == val[i+1]) {
			// centered between P[i] and P[i+1]
			ll mid =(idx[i]+idx[i+1])/2;
			ll a =0, b =min(i+1,K-1-i);
			while(b-a > 1) {
				ll c =(a+b)/2;
				ll hv =Hv[i+c+2]-Hv[i-c]*pp[2*c+2], hvi =Hvi[i-c]-Hvi[i+c+2]*pp[2*c+2];
				ll hd =Hd[i+c+1]-Hd[i-c]*pp[2*c+1], hdi =Hdi[i-c]-Hdi[i+c+1]*pp[2*c+1];
				if((hv-hvi)%mod == 0 && (hd-hdi)%mod == 0) a =c;
				else b =c;
			}
			ll l =mid+1, r =N-mid;
			if(i-b >= 0) l =min(l,mid-idx[i-b]);
			if(i+1+b < K) r =min(r,idx[i+1+b]-mid);
			ans +=min(l,r)-(mid-idx[i]);
		}

		cout << ans << el ; 
	}	
	return 0 ; 
}