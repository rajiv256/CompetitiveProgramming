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
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 

	int n ,x; cin >> n >> x ;
	
	if (n==1){
		cout << "YES" << el ; 
		cout << x << el  ; 
		return 0 ; 
	}
	if (n==2){
		if (x==0){
			cout << "NO" << el; 
		}
		else{
			cout << "YES" << el ; 
			cout << "0 " << x << el ; 
		}
		return 0 ; 
	}
	vi v ; int xo = 0 ; 
	v.pb(1<<18) ; 
	v.pb(1<<17) ; 
	xo = (1<<18) ;
	xo^= (1<<17);  
	for(int i = 0 ; i < n-3 ; i++){
		v.pb(i) ; 
		xo^=i ; 
	}
	v.pb(x^xo) ; 
	cout << "YES" << el ; 
	forn(i,0,v.size()){
		cout << v[i] << sp ;  
	}

}