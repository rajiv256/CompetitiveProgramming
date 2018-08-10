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


ll ncr(ll n , ll r){
	
	if (n < r) return 0 ; 
	if (r == 0) return 1 ; 
	if (n == 0) return 1 ; 
	if (n == 1) return 1 ; 


	ll num = 1 ; ll den = r ; 
	for(int i = n ; i >= n-r+1 ; i--){
		num *= i ; 
		den = max((ll)1,den) ; 
		if (den == 1){
			continue ; 
		}
		while (num%den == 0){
			num /= den ; 
			den-- ; 
			if (den == 0){
				break ; 
			}
		}
	}
	return num ; 


}



int main(){
	int t ; cin >> t ; 
	while (t--){
		ll n , k ; cin >> n >> k ; 
		cout << ncr(9,3-1) << endl ; 
	}
	 
}