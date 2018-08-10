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
#define hashp 999983 

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 

int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 
	int t ; cin >> t ; 
	while (t--){


	string s ; cin >> s ; 
	s = '@'+s ; 
	s += '$' ; 
	vector<pair<char,int> > v ; 
	char ch = s[0] ; int cnt = 1 ; 
	for(int i = 1 ; i < s.size() ; i++){
		if (ch == s[i]){
			cnt++ ; 
		}
		else{
			v.pb(mp(ch,cnt)) ; 
			ch = s[i] ; 
			cnt = 1; 
		}
	}
	if (cnt != 0){
		v.pb(mp(ch,cnt)) ; 
	}

	int ans = 0 ; 
	for(int i = 1 ; i < v.size()-1 ; i++){
		int n = v[i].yy ; 
		if (n == 1){ 
			continue ;
		}
		if (n == 2){
			ans += 1+(int)(v[i-1].xx==v[i+1].xx) ; 
			continue ;
		}
		
		ans += ((n-1)*(n))/2  ;
		if (v[i-1].xx == v[i+1].xx){
			ans++ ; 
		}
	}
	cout << ans << el ; 


}
	return 0 ; 










}