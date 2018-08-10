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
		int n ; cin >> n ; 
		vector<string> v ; 
		string s ; 
		
		forn(i,0,n){
			cin >> s ; 
			v.pb(s) ; 
		}
		int begin[26] ; 
		int end[26] ; 
		clr(begin) ; 
		clr(end) ; 
		forn(i,0,n){
			begin[v[i][0]-'a']++ ; 
			end[v[i][v[i].size()-1]-'a']++ ;  
		}
		int par = 0 ; 
		int fl = 0 ; 
		int ans = 0 ; 
		forn(i,0,26){
			par = abs(begin[i]-end[i]) ; 
			if (par == 1){
				ans++ ;  
			}
			if (par > 1){
				fl = 1 ; 
				break ; 
			}
		}
		if (ans > 2){
			fl = 1 ; 
		}
		if (fl == 1){
			cout << "The door cannot be opened." << el ; 
		}
		else{
			cout << "Ordering is possible." << el ; 
		}
	}
}



















