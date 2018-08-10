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
	int n, k ; sci(n) ; sci(k) ; 
	int a[k] ; forn(i,0,k) sci(a[i]) ; 


	int fs = n ; 
	int ss = 2*n ; 
	int i = 0 ; 

	int full = 0 ; 
	int thr = 0 ; 

	while (i < k){
		fs -= a[i]/4 ; 
		
		if (a[i]%4 == 3){
			fs-- ; 
		}
		else if (a[i]%4 > 0){
			ss -= 1 ; 
		}
		i++ ; 
	}
	if ((fs < 0) && (ss<0)) cout << NO ; 
	else if (fs < 0){
		ss -= 2*abs(fs) ; 
		if (ss < 0){
			cout << NO ; 
		}
		else cout << YES ; 
	}
	else if (ss < 0){
		fs -= abs(ss) ; 
		if (fs < 0) cout << NO ; 
		else cout << YES ; 
	}
	else {
		cout << YES ;
	}
 
}