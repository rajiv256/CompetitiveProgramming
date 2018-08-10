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


int rem(int x, int n){
	return (x%n==0)?0:1 ; 
}

int getfloor(int x, int nf){
	return (x/nf) + rem(x,nf) ; 
}


int main(){

	int n , m ; cin >> n >> m ; 
	map<int,int> ma ; int x , y ; 
	vector<int> v ; 
	forn(i,0,m){
		cin >> x >> y ; ma[x] = y ; 
		v.pb(x) ; 
	}
	if (n == 1){
		cout << "1" << el ; 
		return 0 ; 
	}
	int cnt = 0 ; 
	int anf = -1 ; vector<int> nfs ; 
	for(int nf = 1 ; nf <= 100 ; nf++){
		bool efine = true ; 
		for(int j = 0 ; j < v.size() ; j++){
			int fl = getfloor(v[j],nf) ; 
			//cout << "nf : " << nf << sp << "fl: " << fl << sp << "act: " << v[j] << sp << ma[v[j]] << el ; 
			if (fl != ma[v[j]]){
				efine = false ; 
				break ; 
			}
		}
		if (efine){
			nfs.pb(nf) ; 
		}  		
	}
	set<int> s ; 
	forn(i,0,nfs.size()){
		s.insert(getfloor(n,nfs[i])) ; 
	}
	if (s.size()!=1){
		cout << "-1\n" ; 
	}
	else {
		cout << *s.begin() << el ; 
	}

	return 0 ; 





}