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

int main(){
	int k ; cin >> k ; 
	vi v ; map<int,int> m ; 
	forn(i,0,k){
		int x ; cin >> x ; v.pb(x) ; 
		m[x] = 1 ; 
	}
	int y = 1 ; 
	for(int i = k ; i < 25 ;){
		if (m[y]!=1){
			m[y] = 1 ; 	
			i++ ; 
		}
		y++ ;
		
	}
	vi fin ; fin.pb(0) ; 
	for(map<int,int> :: iterator it = m.begin() ; it != m.end() ; it++){
		fin.pb(it->first) ; 
	}
	sort(all(fin)) ; 
	int ans = 0 ; 
	for(int i = 1 ; i < fin.size() ; i++){
		ans += fin[i]-fin[i-1]-1 ; 
	}
	cout << ans << el ; 

}