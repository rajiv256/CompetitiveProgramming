/* 
        Code written by rajiv. 
        God speed!
*/
#include <bits/stdc++.h>
#include <sys/time.h> 

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
#define lb lower_bound
#define ub upper_bound
 
typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ; 
typedef vector<ll> vll ;
typedef vector<pair<int,pair<int,int> > > vppi ;  
 
unsigned long long s[2];
unsigned long long xorshift128plus() {
	unsigned long long x = s[0];
	const unsigned long long y = s[1];
	x ^= x << 23;
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
	return s[0] = y;
}

const int MX = 1000;

int C[MX][MX];
int H[MX][MX];

int parent[10000] ; 

int find(int x){
	if (parent[x] == -1){
		return x ; 
	}
	return parent[x] ; 
}

void Union(int x, int y){
	int xx = find(x) ; 
	int yy = find(y) ; 
	if (xx != yy){
		parent[xx] = yy ; 
	}
}

// bool cmp(const pair<int,int>& p1, const pair<int,int>& p2){
// 	return (C[p1.xx][p1.yy]*H[p1.xx][p1.yy] < C[p2.xx][p2.yy]*H[p2.xx][p2.yy]) ;
// }
bool notnull(vp& rem){
	forn(i,0,rem.size()){
		if (rem[i].xx!=0)
			return true ; 
	}
	return false ; 
}
int out[1002][1002] ; 
int outcp[1002][1002] ; 
int cons[1002] ; 
ll minval = 0 ; 
int n ; int ret =0 ; 
struct timeval starttime , currtime  ;
bool valid(){
	int timediff = (currtime.tv_sec-starttime.tv_sec)*1000000L + (currtime.tv_usec-starttime.tv_usec) ; 
	if (timediff <= 700000){
		return true ; 
	}
	return false ; 
}

ll score(){
	ll costs = 0 ; ll hubs = 0 ; 
	ll ret = 0 ; 
	forn(i,0,n){
		int ncons = 0 ; 
		forn(j,0,n){
			if (outcp[i][j]==1){
				ncons++ ; 
			}
			if (j>i && outcp[i][j]==1){
				costs += C[i][j] ; 
			}
		}
		hubs += H[i][ncons] ; 
	}
	ret = costs + hubs ; 
	return ret ; 
}
void changeout(){
	forn(i,0,n){
		forn(j,0,n){
			out[i][j] = outcp[i][j] ; 
		}
	}
	return ; 
}
int randgen(){
	int r = rand()%3 ;
	return r ; 
}
void dfs(int src, vb& vis){
	vis[src] = true ; 
	ret += 1 ; 
	for(int i = 0 ; i < n; i++){
		if (!vis[i] && out[src][i]==1){
			dfs(i,vis) ; 
		}
	}
	return ; 
}

bool cmp(pair<int,pair<int,int> > p1 ,pair<int,pair<int,int> > p2){
	int c1 = p1.xx , u1 = p1.yy.xx , v1 = p1.yy.yy ; 
	int c2 = p2.xx , u2 = p2.yy.xx , v2 = p2.yy.yy ; 
	int con11=0,con12=0 ; int con21 = 0 , con22 = 0 ; 
	con11 = cons[u1] ;  con21 = cons[u2] ; 
	con12 = cons[v1] ;  con22 = cons[v2] ; 
	return (c1+H[u1][con11+1]+H[v1][con12+1] < c2+H[u2][con21+1]+H[v2][con22+1]) ; 
}

bool fullyconnected(){
	int ret = 0 ; vb vis(n,false) ;  
	dfs(0,vis) ; 
	return (ret==n) ; 
}
void keepsolvinguntiltimeout(vppi& v , int idx){
	gettimeofday(&currtime,NULL) ; 

	
	if (!valid()){
		return ; 
	}
	if (v.size()==0){
		return ; 
	}
	sort(all(v),cmp) ; 
	pair<int,pair<int,int> > p = v[0] ; 
	outcp[p.yy.xx][p.yy.yy] = 1 ; 
	outcp[p.yy.yy][p.yy.xx] = 1 ; 
	cons[p.yy.xx] += 1 ; 
	cons[p.yy.yy] += 1 ; 
	v.erase(v.begin()) ; 
	if (fullyconnected()){
		ll val = score() ; 
		if (val < minval){
			changeout() ; 
			minval = val ; 
		}	
	}
	
	keepsolvinguntiltimeout(v,idx) ; 	
}



int main() {
	int T;
	srand(time(NULL)) ; 
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int Cmax, Hmax;
		scanf("%d %d %d", &n, &Cmax, &Hmax);
		for (int i = 0; i < n; i++) {
			C[i][i] = 0;
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = i + 1; j < n; j++) {
				C[i][j] = C[j][i] = xorshift128plus() % (Cmax + 1);
			}
		}
		
		for (int i = 0; i < n; i++) {
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = 0; j < n; j++) {
				H[i][j] = xorshift128plus() % (Hmax + 1);
			}
		}

		vector<pair<int,pair<int,int> > > v ; 
		for(int i = 0 ; i < n ; i++){
			for(int j = i+1 ; j < n ; j++){
				v.pb(mp(C[i][j],mp(i,j))) ; 
			}
		}
		sort(all(v)); 
		
		clr(out) ; 
		clr(outcp) ; 
		clr(cons) ; 
		vb over(n,false) ; 
		// for(int i = 0; i < n ; i++){
		// 	ll mini = (1LL)<< 60  ; int idx =0 ; 
		// 	if (over[i]) continue ; 
		// 	for(int j = 0 ; j<n ; j++){
		// 		if (j!=i && !over[j]){
		// 			if (mini > C[i][j]+H[j][2]){
		// 				mini = C[i][j] + H[j][2] ; 
		// 				idx = j; 
		// 			}
		// 		}
		// 	}
		// 	out[i][idx] = 1 ; 
		// 	out[idx][i] = 1 ; 
		// 	cons[i] += 1; 
		// 	cons[idx] += 1 ; 

		// }
		//minval = score() ; 

		
		minival = (1LL)<<60 ; 

		gettimeofday(&starttime,NULL) ; 
		keepsolvinguntiltimeout(v,0) ; 
		vb vis(n,false) ;  
		dfs(0,vis) ; int prev = 0 ; 
		for(int i = 1 ; i < n; i++){
			
			if (!vis[i]){
				out[i][prev] = 1 ; 
				out[prev][i] = 1 ; 
				prev = i ;
				dfs(i,vis) ;  
			}


		}
		forn(i,0,n){
			out[i][i] = 0 ; 
		}
		////////////// Output //////////////////////////
		forn(i,0,n){
			forn(j,0,n){
				cout << out[i][j] ; 
			}
			cout << el ; 
		}
	}
	
	return 0;
}
