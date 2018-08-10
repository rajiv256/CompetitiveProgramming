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
	int a, b, f , k ; cin >> a >> b >> f >> k ; 

	if (f > b || a-f>b){
		cout << "-1\n" ; 
		return 0 ; 
	}
	if (k>1 && (2*a-2*f) > b){
		cout << "-1\n" ; 
		return 0 ; 
	}
	if (k > 2){
		if (2*f > b){
			cout << "-1\n" ; 
			return 0 ; 
		}
	}

	int st = b ; 
	vi v ; v.pb(0) ; v.pb(f) ; 
	vi add ; add.pb(2*a-2*f) ; add.pb(2*f) ; 
	int rem = k-1 ; int i = 0 ; 
	while (rem--){
		v.pb(add[i]) ; 
		i += 1 ; i%= 2 ; 
	}

	if (k&1){
		v.pb(a-f) ; 
	}
	else{
		v.pb(f) ; 
	}

	int idx = 0 ; int nf = 0 ; int pa = b ; 	
	while (idx < v.size()){
		while (pa >= v[idx] && idx < v.size()){
			pa -= v[idx] ; 
			idx++ ;
		}
		if (idx >= v.size()){
			break ; 
		}
		nf++ ; 
		pa = b ; 
	}
	cout << nf << el ; 

}