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

int ndig(int n){
	int ret = 0 ; 
	while (n!=0){
		n /= 10 ; 
		ret++ ; 
	}
	return ret; 
}

int dsum(int n){
	int ret = 0 ; 
	while (n!=0){
		ret += n%10 ; 
		n /= 10 ; 
	}
	return ret ; 
}
int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 
	int n ; 
	cin >> n ; 

	int nd = ndig(n) ; 
	int mds = 9*nd ; 
	int ans = 0 ; 
	vi v ;
	for(int ds = 0 ; ds <= mds ; ds++){
		int num = n-ds ; 
		int numdsum = dsum(num) ; 
		if (numdsum == ds){
			ans++ ; 
			v.pb(num) ; 
		}

	}

	cout << ans << el ; 
	sort(all(v)) ; 
	forn(i,0,v.size()){
		cout << v[i] << sp ; 
	}
	


}





















