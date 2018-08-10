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
#define MOD 1000000007
#define MXN 100003
#define gc getchar_unlocked	

ll n , m, x , y ; 
ll sz ; 
ll L[MXN][2] ; 
ll a[MXN] ; 

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
ll add(ll lhs , ll rhs , int i){
	cout << i << sp << lhs << " ** " << rhs << el ; 
	if (lhs > rhs){
		return 0 ; 
	}
	
	if (i == 1){
		lhs = max(lhs,L[i][0]+1) ; 
		rhs = min(rhs,L[i][1]-2) ; 
		if (lhs > rhs){
			return 0 ; 
		}
		return (max((ll)0,((rhs-lhs)/2)+1))  ; 
	}
	if (i == sz){
		lhs = max(lhs,L[i][0]+2) ; 
		rhs = min(rhs,L[i][1]-1) ;
		if (lhs > rhs){
			return 0 ; 
		}
		return (max((ll)0,((rhs-lhs)/2)+1)); 
	}
	lhs = max(lhs,L[i][0]+2) ; 
	rhs = min(rhs,L[i][1]-2) ; 
	if (lhs >rhs){
		return 0 ;
	}
	return (max((ll)0,((rhs-lhs)/2)+1)) ; 
}




int main(){
	int t ; sci(t) ; 
	while (t--){
		
		cin >> n >> m >> x >> y ;   
		memset(a,0,sizeof(a)) ; 
		memset(L,0,sizeof(L)) ; 
		sz = n ; 
		forn(i,m){
			sz = 2*sz-1 ; 
		}
		
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i] ; 
			L[i][0] = (ll)i ; L[i][1]= (ll)i ; 
		}
		for(int i = 1; i <= n ; i++){
			ll ad = i ; 
			for(int j= 0 ; j < m ; j++){
				ad = 2*ad-2 ; 
			}
			L[i][0] = max((ll)1,ad); 
			L[i][1] = min(sz,(ll)(2<<(m-1))*i) ;  
		}
		for(int i = 1 ; i <=n ; i++){
			forn(j,2){
				cout << L[i][j] << sp ; 
			}
			cout << el ; 
		}
		ll ans = 0 ; 
		for(int i = 1 ; i <= n ; i++){
			ll lhs , rhs ; 
			if ((y < L[i][0]) || (x > L[i][1])){
				continue ; 
			}
			if (x >= L[i][0]){
				lhs = x ;   
				if (y <= L[i][1]){
					rhs = y ;
				}
				else{
					rhs = L[i][1] ; 
				}
				cout << lhs << sp << rhs <<"...." << el ; 
				ans += ((rhs-lhs+1)*a[i])%MOD ; 
				ans %= MOD ;
				cout << ans << " ^^ " << el ; 
				ans += add(lhs,rhs,i)*a[i] ;
				ans %= MOD ; 
						
			}
			else{
				lhs = L[i][0] ;
				if (y <= L[i][1]){
					rhs = y ; 
				}
				else{
					rhs = L[i][1] ; 
				}
				ans += ((rhs-lhs+1)*a[i])%MOD ; 
				ans %= MOD ; 
				cout << ans << " __ " << el ; 
				ans += add(lhs,rhs,i)*a[i] ;
				ans %= MOD ; 
								 
			
			}
			 
				
		}
		cout << ans << el ;
		
		
	}
	return 0 ; 
}
