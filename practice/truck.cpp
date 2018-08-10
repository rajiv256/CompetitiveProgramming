	// http://wcipeg.com/problem/ccc07j5
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
		int a , b ; sci(a) ;sci(b) ; 
		

		vi v ;
		v.pb(0) ; 
		v.pb(990) ; 
		v.pb(1010) ; 
		v.pb(1970) ; 
		v.pb(2030) ; 
		v.pb(2940) ; 	
		v.pb(3060) ; 
		v.pb(3930) ; 
		v.pb(4060) ; 
	    v.pb(4970) ; 
	    v.pb(5030) ; 
	    v.pb(5990) ; 
	    v.pb(6010) ; 
	    v.pb(7000) ; 
	    int x ; sci(x) ; 
	    while (x--){
	    	int y ; 
	    	cin >> y ; v.pb(y) ; 
	    }
	    sort(all(v)) ; 

	    int L[v.size()+2] ; memset(L,0,sizeof(L)) ; 

	    L[0] = 1 ; 
	    for(int i = 0 ; i <= v.size() ; i++){
	    	vi :: iterator st, en ; 
	    	st = lower_bound(all(v),v[i]+a) ; 
	    	en = upper_bound(all(v),v[i]+b) ; 

	    	for(int j = st-v.begin() ; j < en-v.begin() ; j++){
	    		L[j] += L[i] ; 
	    	}
	    }
	    printf("%d\n",L[v.size()-1]);

	    return 0 ;


	}