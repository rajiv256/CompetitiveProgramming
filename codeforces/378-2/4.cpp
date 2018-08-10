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
	map<pair<int,int>,set<pair<int,int> > > m ; 
	int n  ; cin >> n ; 
	vi v  ; 
	int ans = INT_MIN ;
	int k = 1 ; vi ans1(1,-1) ; 
	forn(i,0,n){
		v.clear() ; 
		v.pb(0) ; v.pb(0) ; v.pb(0) ; 
		cin >> v[0] >> v[1] >> v[2] ; 
		sort(all(v)) ; 
		
		if (ans < v[0]){
			ans = v[0] ; 
			ans1[0] = i+1 ; 
		}
		m[mp(v[0],v[1])].insert(mp(v[2],i)) ;
		while (next_permutation(all(v))){
			vi v1 ; v1.pb(v[0]) ; v1.pb(v[1]) ; 
			sort(all(v1));
			m[mp(v1[0],v1[1])].insert(mp(v[2],i)) ;
		}

	}
	map<pair<int,int>,vector<pair<int,int> > > mnew ;
	vi ans2(2,-1) ; 
	for(map<pair<int,int>,set<pair<int,int> > >:: iterator it = m.begin() ; it != m.end() ; it++){
		std::vector<pair<int,int> > v((it->second).begin(),it->second.end()) ; 
		mnew[it->first] = v ; 
		if (v.size() > 1){
			sort(all(v)) ; 
			int xyz = min(it->first.xx,min(it->first.yy,v[v.size()-1].xx+v[v.size()-2].xx)) ; 
			if (ans < xyz){
				ans = xyz ; 
				k = 2 ; 
				ans2[0] = v[v.size()-1].yy ; 
				ans2[1] = v[v.size()-2].yy ; 
				//cout << ans2[0] << sp << ans2[1] << el;
			} 
		} 
	}
	if (k == 1){
		cout << k << el ; 
		cout << ans1[0] << el ; 
	}
	if (k == 2){
		cout << k << el  ;
		cout << ans2[0]+1 << sp << ans2[1]+1 << el ; 
	}

}

