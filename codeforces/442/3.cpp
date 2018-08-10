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
vi v ; 
int solve(int l , int h){
	if (l > h){
		return 0 ; 
	}
	int mid = (l+h)/2 ; 
	if (h-l+1 ==2){
		v.pb(l+1) ; v.pb(l) ; v.pb(l+1) ; 
		return 3 ; 
	} 
	if (h-l+1 == 3){
		v.pb(l+1) ; v.pb(l) ; v.pb(l+2) ; v.pb(l+1) ;
		return 4 ; 
	}
	int ans = 0 ; 
	v.pb(mid) ; 
	ans += 1 ;
	ans += solve(l,mid-1) ; 
	ans += solve(mid+1,h) ; 
	if (mid != l){
		v.pb(mid) ; 
		ans += 1 ; 
	}
	return ans ; 
}




int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false)  ; 
	int n ; cin >> n ; 
	//int ans = solve(1,n) ; 
	// cout << ans << el ;
	// for(int i = 0 ; i < v.size() ; i++){
	// 	cout << v[i] << sp ; 
	// }
	// return  0; 
	int ans = 2*(n/2) + ((n/2)+(n%2)) ; 
	cout << ans << el ;
	for(int i = 0 ; i < n ; i++){
		if (i&1){
			cout << i+1 << sp ; 
		}
	}
	forn(i,0,n){
		if (i%2==0){
			cout << i+1 << sp ; 
		}
	}
	forn(i,0,n){
		if (i&1){
			cout << i+1 << sp ; 
		}
	}
	return 0 ; 
}
