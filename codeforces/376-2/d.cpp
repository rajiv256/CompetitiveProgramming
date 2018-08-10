#include <bits/stdc++.h> 
using namespace std ; 

#define ll long long 
#define el endl 
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100003 
#define INF 10000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<vector<int> > vvi ; 
typedef vector<pair<int,int> > vp ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define xx first 

#define yy second
int n , c ; 
pair<int,int> interval(int x, int y){
	pii p ; 
	if (x <= y){
		p.xx = 0 ; 
		p.yy = c-y ; 
	}
	return p ; 
}
pii isect(pii p1, pii p2){
	pii p ; 
	p.xx = max(p1.xx,p2.xx) ; 
	p.yy = min(p1.yy,p2.yy) ;  
	if (p.xx > p.yy){
		p.xx = -1 ; 
		p.yy = -1 ; 
	}
	return p ; 
}
pii cinterval(vi v1, vi v2){
	pii p ; p.xx = 0 ; p.yy = c-1 ; 
	forn(i,0,min(v1.size(), v2.size())){
		cout << p.xx << sp << p.yy << el; 
		p = isect(p,interval(v1[i],v2[i])) ; 
		if (p.xx == -1 && p.yy==-1){
			return p ; 
		}
	}
	return p ; 
}


int main(){
	cin >> n >> c ; 
	vi v ; 
	vvi w(n,v) ; int l ;  
	forn(i,0,n){
		cin >> l ; int x ; 
		forn(j,0,l){
			cin >> x ; 
			w[i].pb(x) ; 
		}
	}
	pii p ; p.xx=0 ; p.yy = c-1 ; 
	forn(i,0,n-1){
		p = cinterval(w[i],w[i+1]) ;
		if (p.xx == -1){
			cout << "-1" << el ; 
			return 0 ; 
		}
	}
	cout << p.xx << el ;
	return 0 ; 

}