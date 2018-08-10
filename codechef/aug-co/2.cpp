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
	int t ; sci(t) ;
	while (t--){
		ll k , a , b ;

		scanf("%lld%lld%lld",&k,&a,&b) ;
		ll t1 = min(a,b) ;
		ll t2 = max(a,b) ;
		a = t1 ;
		b = t2 ;

		ll x1 = b-a-1 ;
		ll x2 = k-(b-a+1) ;

		if (x1 < x2){
			printf("%lld\n", x1);
		}
		else if (x2 < x1){
			printf("%lld\n", x2);
		}
		else{
			printf("0\n");
		}

	}
	return 0 ;
}
