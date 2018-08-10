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
	ios_base::sync_with_stdio(0) ;

	int t ; cin >> t ; 
	while(t--){
		ll n ; cin >> n ; 
		ll a[n] ; ll mod = ((1LL)<<32) ;  
		//cout << mod << el ; 
		ll x = mod/n ; ll sum = 0 ; 
		forn(i,0,n){
			a[i] = x ; 
		}
		ll rem = mod%n ; 
		int i = 0 ; 
		while(rem--){
			a[i]++ ; i++ ; 
		}
		a[n-1] = 1 ; 

		for(int i = 0 ;i < n ; i++){
			cout << a[i] << sp ; 
		}
		cout << el ; 
	}

	return 0 ; 
}