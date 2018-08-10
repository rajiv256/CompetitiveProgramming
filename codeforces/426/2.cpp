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

int open[26] ; 
int close[26] ; 

int main(){
	int n , k ; cin >> n >> k ; 
	string s ; cin >> s ; 

	for(int i = 0 ; i < 26 ; i++){
		open[i] = -1 ; 
		close[i] = -1 ; 
	}
	for(int i = 0 ; i < s.size() ; i++){
		if (open[s[i]-'A']==-1){
			open[s[i]-'A'] = i ; 
		}
	}
	for(int i = s.size()-1 ; i >= 0 ; i--){
		if (close[s[i]-'A']==-1){
			close[s[i]-'A'] = i ; 
		}
	}

	int nopen = 0 ; string ans = "NO" ; 
	for(int i = 0 ; i < s.size() ; i++){
		if (i == open[s[i]-'A']){
			nopen++ ; 
		}
		if (nopen > k){
			ans = "YES" ; 
			break ; 
		}
		if (i == close[s[i]-'A']){
			nopen-- ; 
		}
	}
	cout << ans << el ; 
	return 0 ; 


}