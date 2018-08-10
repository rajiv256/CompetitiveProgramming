#include <bits/stdc++.h>

using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)	
#define scll(x) scanf("%lld",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100003
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()


typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<int,int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

int main(){
	int t; cin >> t ; 
	while (t--){
		int n ; cin >> n ; ll a[n] ; 
		forn(i,0,n) cin >> a[i] ; 

		ll pre[n] ; ll suf[n] ; 
		pre[0] = a[0] ; suf[n-1] = a[n-1] ; 
		for(int i = 1 ; i < n ; i++){
			pre[i] = a[i]+pre[i-1] ;  
		}
		for(int i = n-2 ; i >= 0 ; i--){
			suf[i] = a[i]+suf[i+1] ; 
		}
		int idx = 0 ; 
		ll sum = pre[0]+suf[0] ; 
		for(int i = 0 ; i < n ; i++){
			if (sum > pre[i]+suf[i]){
				sum = pre[i]+suf[i] ; 
				idx = i ; 
			}
		}
		cout << idx+1 << el; 
	}
}