#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;

#define forn(i,n) for(int i = 0; i < n ; i++)
#define INF 1000000
#define LIM 1000000000
#define sp " "
#define el endl
#define ll long long
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define MXN 100003
#define MOD 1000000007
#define gc getchar_unlocked	

int abs(int i){
	if (i < 0){
		return -i ; 
	}
	return i ; 
}


int main(){
	int t ; sci(t) ; 
	while (t--){
		ll n , k ; 
		vector<ll> vpos ; vector<ll> vneg ; 
		ll x ; 
		forn(i,n){
			cin >> x  ; 
			if (x< 0){
				vneg.pb(x) ; 
			}
			else{
				vpos.pb(x) ; 
			}
		}
		sort(all(vpos)) ; 
		sort(all(vneg)) ; 
		reverse(all(vneg)) ; 
		if (vpos.size()==0){
			ll ans = 1 ; 
			if (k&1){
				forn(i,k){
					ans *= vneg[i]; 
					while (ans <0) ans+=MOD;
					ans %= MOD ;
				}
				cout << ans << el ; 
				continue ; 
			}
			else{
				int idx = vneg.size()-1 ; 
				int cnt = 0 ; 
				while (cnt < k){
					ans *= vneg[idx] ; while(ans <0) ans+=MOD ; 
					idx-- ; cnt++ ; 
					ans %= MOD ; 
				}
				cout << ans << el; 
				continue; 
			}
		}
		else if (vneg.size()==0){
			int idx = vpos.size()-1 ; int cnt = 0 ; 
			while  (cnt <k){
				ans*= vpos[idx]; 
				ans%= MOD ; 
			}
			cout << ans << el ; 
			continue ; 
		}
		
		int negCnt= 0 ; ll ans = 1 ; 
		for(negCnt = 0 ; negCnt <= k ; negCnt += 2){
			if (k-negCnt > vpos.size()){
				continue ; 
			}
			if (negCnt > vneg.size()){
				break ; 
			}
			
		}
		
		
		
		
		
	}
}














