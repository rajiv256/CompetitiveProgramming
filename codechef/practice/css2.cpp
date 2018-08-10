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

map<pair<int,int>,int> ids ;  // id,attr --> val 


int main(){
	int n , m ; sci(n) ; sci(m) ; 
	int id, val, attr, pr ; 
	vector<pair<int,pair<int,pair<int,pair<int,int> > > > > v ; 
	forn(i,0,n){
		sci(id) ; sci(attr) ; sci(val) ; sci(pr) ; 
		v.pb(mp(pr,mp(i,mp(id,mp(attr,val))))) ; 
	}
	sort(all(v)) ; 
	for(int i = 0 ; i < v.size() ; i++){
		int idx = v[i].yy.xx ; 
		int idi = v[i].yy.yy.xx ; 
		int attri = v[i].yy.yy.yy.xx ; 
		int vali = v[i].yy.yy.yy.yy ; 

		ids[mp(idi,attri)] = vali ; 
	}
	for(int i = 0 ; i < m ; i++){
		sci(id) ; sci(attr) ;
		printf("%d\n", ids[mp(id,attr)]); 
	}
	return 0 ; 
}