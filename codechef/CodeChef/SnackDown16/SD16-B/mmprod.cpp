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

void sci(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int main(){
	int t ; sci(t) ; 
	while (t--){
		ll n , k ; cin >> n >> k ; 
		ll a[n] ; int npos = 0 , nneg = 0 ; 
		forn(i,n){
			cin >> a[i] ; 
			if (a[i]<0){
				nneg++ ; 
			}
			else{
				npos++  ; 
			}
		}
		vp v  ; 
		forn(i,n){
			if (a[i] < 0){
				v.pb(mp(-a[i],-1)) ; 
			}
			else{
				v.pb(mp(a[i],1)) ; 
			}
		}
		sort(all(v)) ; 
		reverse(all(v)) ; 
		ll ans = 1 ; 
		if (npos==0){
			if (k&1){
				for(int i = n-1 ; i >= n-k ; i--){
					ans *= -v[i].xx ; 
					if (ans < 0) ans+= MOD ; 
					ans %= MOD ; 
				}
				cout << ans%MOD << el ; 
				continue ;
			}
			else{
				forn(i,k){
					ans *= -v[i].xx ; 
					if (ans < 0) ans+= MOD ; 
					ans = ans%MOD ; 
				}
				cout << ans << el ; 
				continue ; 
			}
		}
		ans = 1 ; int nn = 0 ; 
		forn(i,k){
			ans *= v[i].xx ; 
			nn += (int)(v[i].yy==-1) ; 
			ans %= MOD ; 
		}
		if (nn&1){ 
			int it1 = k ; int it2 = k+1; 
			while (it1 >= 0){
				if (v[it1].yy==-1){
					break ; 
				}
				it1-- ; 
			}
			while (it2 < n){
				if (v[it2].yy==1){
					break ; 
				}
				it2++ ; 
			}
			ans = 1 ; 
			for(int i = 0 ; i<k && i!=it1; i++){
				ans *= v[i].xx ; ans %= MOD ; 
			}
			ans *= v[it2].yy ; ans %= MOD ; 
			cout << ans << el ; 
			continue ; 
			
		}
		else{
			cout << ans << el ; 
			continue; 
		}
		
		
		
	}
}

