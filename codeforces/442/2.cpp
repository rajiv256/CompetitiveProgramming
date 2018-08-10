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

int pa[5002] ; 
int pb[5002] ; 
vector<int> v ;

int qa(int l , int r){
	if (l < 0 || r < 0 || r < l){
		return 0 ; 
	}
	if (l == 0){
		return pa[r] ; 
	}
	return (pa[r]-pa[l-1]) ; 
}
int qb(int l , int r){
	if (l < 0 || r < 0 || r < l){
		return 0 ; 
	}
	if (l == 0){
		return pb[r] ; 
	}
	return (pb[r]-pb[l-1]) ; 
}


int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false)  ; 
	string s ; cin >> s ; 
	v.clear() ; 
	int n = s.size() ; 
	memset(pa,0,sizeof(pa)) ; 
	memset(pb,0,sizeof(pb)) ; 

	pa[0] = (s[0]=='a') ; 
	pb[0] = (s[0]=='b') ; 
	for(int i = 1 ; i < n ; i++){
		pa[i] = pa[i-1]+(s[i]=='a') ; 
		pb[i] = pb[i-1]+(s[i]=='b') ; 
	}
	for(int i = 0 ; i < n ;i++){
		if (s[i]=='b'){
			v.pb(i) ; 
		}
	}
	int ans = INT_MIN ; 
	for(int i = 0 ; i < v.size() ; i++){
		for(int j = i; j < v.size() ; j++){
			int l = v[i] ; 
			int r = v[j] ; 
			int x = 0 ; 
			x += qb(0,l-1); 
			x += qa(l,r); 
			x += qb(r+1,n-1);
			ans = max(ans,n-x) ;  

		}
	}
	if (ans == INT_MIN){
		ans = n ; 
	}
	cout  << ans << el ; 


	
}
