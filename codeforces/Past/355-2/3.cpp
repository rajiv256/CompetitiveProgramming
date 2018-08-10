#include <bits/stdc++.h>
using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mi ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> >
#define pi pair<int,int>
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >
#define INF 1000000
#define MOD 1000000007
#define sp " "
#define el "\n"
#define ll long long
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x)
#define MXN 1000003
#define gc getchar_unlocked

int main(){
	
	
	string s ; cin >> s ; 
	int as[64] ; 
	forn(i,64){
		as[i] = 0 ; 
	}
	map<int,int> m ; 
	
	forn(i,64){
		forn(j,64){
			int x = (i&j) ; 
			m[x] += 1 ; 
			//cout << m[61] << el ; 
		}
	}
	
	vi v ; 
	forn(i,s.size()){
		if (s[i]>='0' && s[i] <='9'){
			v.pb(s[i]-'0') ; 
		}
		if (s[i]>='A' && s[i]<='Z'){
			v.pb(s[i]-'A'+10) ; 
		}
		if (s[i]>='a' && s[i]<='z'){
			v.pb(s[i]-'a'+36) ; 
		}
		if (s[i] == '-'){
			v.pb(62) ; 
		}
		if (s[i] == '_'){
			v.pb(63) ; 
		}
	}
	ll ans = 1 ; 
	forn(i,v.size()){
		ans *= m[v[i]] ; 
		ans %= MOD ; 
	}
	cout << ans << el ; 
	return 0 ; 
	
	
}
