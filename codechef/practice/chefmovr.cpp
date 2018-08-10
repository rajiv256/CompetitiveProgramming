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

ll abs(ll a){
	return (a>0)?a:-a ; 
}
bool valid(int i, int n){
	return ((i>=0 && i < n))?true : false ; 
}
int main(){
	int t ; cin >> t ; 
	while (t--){
		ll n , d ; cin >> n >> d ; int fl = 0 ; 

		ll a[n] ; 
		ll sum = 0 ; ll res = 0 ; 
		forn(i,0,n){
			cin >> a[i] ; 
			sum += a[i] ; 
		}
		if (sum%n!=0){
			cout << "-1\n" ; 
			continue ; 
		} 
		ll v = sum/n ; 

		int i = 0 ; 
		while ((i+d < n)){
			if (a[i]>v){
				ll s = a[i]-v ; 
				res += s ; 
				a[i+d]-= s ; 
				a[i] = v ; 
			}
			if (a[i] < v){
				ll s= v-a[i] ; 
				res += s;
				a[i+d] += s ; 
				a[i] += s ; 
			}
			++i ; 
		}
		for( i = 0 ; i < n ; i++){
			if (a[i]!=v){
				fl = 1; 
				break ; 
			}
		}
		if (fl){
			cout << "-1\n" ; 
		}
		else cout << res << el ; 
		

	}
	return 0 ; 
}
