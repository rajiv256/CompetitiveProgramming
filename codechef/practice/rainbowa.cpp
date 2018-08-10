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

bool isasc(vi& v){
	bool b = false ; 
	forn(i,0,v.size()-1){
		if (v[i] > v[i+1]){
			return false ; 
		}
	}
	return true ; 
}

int main(){
	int t ; cin >> t ; 
	while(t--){
		int n ; cin >> n ; 
		int a[n] ; int fl = 0 ; 
		forn(i,0,n){
			cin >> a[i] ; 
		}

		forn(i,0,n){
			if (a[i] > 7){
				fl = 1 ; 
				break ; 
			}
		}
		vi v1 ; vi v2 ; 
		forn(i,0,n/2+n%2){
			v1.pb(a[i]) ; 
			v2.pb(a[n-i-1]) ; 
		}

		vi v3 = v1 ; 
		sort(all(v3)) ; 
		for(int i = 1 ; i <= 7 ; i++){
			if (!binary_search(all(v3),i)){
				fl = 1 ; 
				break ; 
			}
		}

		if (!isasc(v1)){
			fl = 1 ; 
		}

		for(int i = 0 ; i < v1.size() ; i++){
			if (v1[i] != v2[i]) {
				fl = 1 ; 
				break; 
			}
		}


		if (fl) cout << "no\n" ; 
		else cout << "yes\n" ; 

	}
}