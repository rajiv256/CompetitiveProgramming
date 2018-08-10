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
#define bs binary_search

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 

int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 
	int n , m ; 
	cin >> n >> m ; 
	vi v1 , v2 ; 
	int x ; 
	forn(i,0,n){
		cin >> x ; v1.pb(x) ; 
	}
	forn(i,0,m){
		cin >> x ; v2.pb(x) ; 
	}
	sort(all(v1)) ; 
	sort(all(v2)) ; 

	vi ans ; 
	
	forn(i,0,v1.size()){
		if (bs(all(v2),v1[i])){
			ans.pb(v1[i]) ; 
		}
	}
	forn(i,0,v2.size()){
		if (bs(all(v1),v2[i])){
			ans.pb(v2[i]) ; 
		}
	}
	
	
	ans.pb(v1[0]*10+v2[0]) ; 
	ans.pb(v2[0]*10+v1[0]) ; 
	sort(all(ans)) ; 
	cout << ans[0] << el ; 

}