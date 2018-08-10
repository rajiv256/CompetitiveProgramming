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
typedef vector<vector<int> > vvi ;
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
#define YES "YES\n"
#define NO "NO\n"

int main(){
	int n ; sci(n) ; 
	vector<ll> a ; 
	vector<pair<ll,ll> > b ; 
	map<ll,ll> m ; ll x ; 
	forn(i,0,n){
		scll(x) ; a.pb(x) ; 
	} 
	forn(i,0,n){
		scll(x) ; b.pb(mp(x,i)) ; 
	}
	sort(all(b)) ; 
	sort(all(a),greater<int>()) ; 
	forn(i,0,n){
		m[b[i].yy] = a[i] ; 
	}
	for(map<ll,ll>:: iterator it = m.begin() ; it != m.end() ; it++){
		printf("%lld ", (*it).yy) ;
	}
	return 0 ; 



}