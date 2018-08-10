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
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()


typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<int,int> > vvi ; 
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

void printv(vi& v){
	forn(i,0,v.size()){
		cout << v[i] << " " ; 
	}
	cout << el ;
}
int sumv(vi& v){
	int sum = 0 ; 
	forn(i,0,v.size())
		sum += v[i] ; 
	return sum ; 
}

int main(){
	int n , m ; cin >> n >> m ; 
	int a[n] ; 
	int last[m] ; 
	memset(last,-1,sizeof(last)) ; 

	forn(i,0,n){
		cin >> a[i] ;
		if (a[i] !=0){
			last[a[i]] = i ; 
		} 
	}
	int nd[m] ; 
	forn(i,0,m){
		cin >> nd[i] ; 
	}
	vp v ; 
	forn(i,0,m){
		v.pb(mp(nd[i],i)) ; 
	}
	sort(all(v)) ; 
	forn(i,0,m){
		if (last[i] == -1) {
			cout << "-1\n" ; 
			return 0 ; 
		}
	}
	//assign everything to its last day. 




}