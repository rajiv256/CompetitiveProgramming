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
#define mod 998244353

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 

ll ncr[5002][5002] ; 
ll fact[5002] ; 
#define MAX 5002 

void init(){
	memset(ncr,0,sizeof(ncr)) ;
	memset(fact,0,sizeof(fact)) ;
	ncr[0][0] = 1 ; 
	for(int i = 1 ; i < MAX ; i++){
		ncr[0][i] = 0 ; 
		ncr[i][0] = 1 ; 
	}
	for(int i = 1  ; i < MAX ; i++){
		for(int j = 1 ; j <=i  ; j++){
			ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%mod ; 
		}
	}

	fact[0] = 1 ; 
	for(int i = 1 ; i < MAX ; i++){
		fact[i] = (fact[i-1]*i)%mod ; 
	}
}

ll each(int M , int m){
	ll sum = 0 ; 
	for(int i = 0 ; i <= m ; i++){
		sum += (((ncr[M][i]*ncr[m][i])%mod)*fact[i])%mod ;
		sum %= mod ;  
	}
	return sum ; 
}

int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 
	int a , b , c ; 
	cin >> a >> b >> c ; 
	init() ; 
	ll ans = 1 ; 
	ans *= each(max(a,b),min(a,b)) ; 
	ans %= mod ; 
	ans *= each(max(b,c),min(b,c)) ; 
	ans %= mod ; 
	ans *= each(max(c,a),min(c,a)) ; 
	ans %= mod ; 

	cout << ans << el ; 
}