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


vector<string> s ; 
map<pair<int,int> , int> m ; 


int mult = 7 ; 

int main(){
	ios::sync_with_stdio(0) ; 
	cin.tie(0) ; 
	cout.tie(0) ; 

	int n ; cin >> n ; 
	string x = "" ; 
	forn(i,0,n){
		cin >> x ; s.pb(x); 
	}

	for(int i = 0 ; i < n ; i++){
		set<pair<int,int> > g ; 
		for(int l = 0 ; l < 9 ; l++){
			int hsh = 0 ; 
			for(int r = l ; r < 9 ; r++){
				hsh = hsh*10 + s[i][r]-48  ; 
				pair<int,int> p = make_pair(r-l+1,hsh) ; 
				if (g.find(p)==g.end()){
					g.insert(p) ; m[p]++ ; 
				}

			}
		}
	}


	for(int i = 0 ; i < n ; i++){
		int ans = 10 ; int st = 0  ; int en = 9 ; 
		for(int l = 0 ; l < 9 ; l++){
			int hsh = 0 ; 
			for(int r = l ; r < 9 && r-l+1 < ans ; r++){
				hsh = hsh*10 + s[i][r]-48 ; 
				pair<int,int>p = make_pair(r-l+1,hsh) ; 
				if (m[p]==1){
					//if (ans > r-l+1){
						ans = r-l + 1 ; st = l ; en = r ; 
					//}
				}
			}
		}
		string fin = "" ; 
		for(int p = st ; p <= en ; p++){
			fin += s[i][p] ; 
		}
		cout << fin << el ;
	}



















}