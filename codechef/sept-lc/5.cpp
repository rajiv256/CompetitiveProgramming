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
typedef vector<vector<int> > vvi ;
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
#define YES "YES\n"
#define NO "NO\n"


ll qa[100005] ; 
ll aa[100005] ; 

typedef struct query{
	int fl ; 
	int l ; 
	int r ; 
}query ; 

void qupdateBIT(int idx, ll val){
	idx += 1 ; 
	while (idx < MXN){
		qa[idx] += val ; 
		qa[idx] %= MOD ; 
		idx += (idx&(-idx)) ; 
	}
}

void aupdateBIT(int i, ll val){
	i += 1 ; 
	while (i < MXN){
		aa[i] = (aa[i]+val+MOD)%MOD ; 
		i += (i&(-i)) ; 
	}
}


void qupdate(int l , int r , ll val){
	
	qupdateBIT(l,val) ; 
	qupdateBIT(r+1,-val) ; 
}
ll qquery(int idx){
	ll sum = 0 ; 
	idx += 1 ; 
	while (idx > 0){
		sum += qa[idx] ; 
		sum %= MOD ; 
		idx -= (idx&(-idx)) ; 
	}
	return sum ; 
}

void aupdate(int l , int r, ll val){
	aupdateBIT(l,val) ; 
	aupdateBIT(r+1,-val) ; 
}


ll aaquery(int idx){
	ll sum = 0 ; 
	idx += 1 ; 
	while (idx > 0){
		sum += (aa[idx]) ;
		sum %= MOD ;  
		idx -= (idx&(-idx)) ; 
	}
	return sum ; 
}


int main(){

	int t ; sci(t) ; 
	while (t--){
		int n , m ; sci(n) ; sci(m) ; 
		vector<query> queries ; int fl , l , r ; 
		for(int i = 0 ; i < MXN ; i++){
			qa[i] = 0 ;
			aa[i] = 0 ;  
		}
		for(int i = 0 ; i < m ; i++){
			sci(fl) ; sci(l) ; sci(r) ; l-- ; r-- ; 
			query q ; q.fl = fl ; q.l = l ; q.r = r ; 
			queries.pb(q) ; 
		}

		for(int i = m-1 ; i >= 0 ; i--){
			query q = queries[i] ; 
			if (q.fl == 1){
				qupdate(i,i,1) ; 
			}
			if (q.fl == 2){
				ll nbefore =  qquery(i) ; 
				qupdate(q.l, q.r, nbefore+1) ; 
			}
		}

		for(int i = 0 ; i < m ; i++){
			query q = queries[i] ; 
			if (q.fl == 1){
				aupdate(q.l,q.r,qquery(i)) ; 
			}
		}
		

		for(int i = 0 ; i < n ; i++){
			printf("%lld ", aaquery(i));
		}
		printf("\n");

	}


}




