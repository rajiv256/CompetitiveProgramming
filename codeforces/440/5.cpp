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
//typedef vector<pair<pair<int,int> > > vpp ; 

map<int,int> mx , my ; 

int deg = 0 ; 
int compsize = 0 ; 
int parent[MXN] ; 
set<int> diff_x  ; 
set<int> diff_y  ; 

int find(int x ){
	if (parent[x] ==-1){
		return x ; 
	}
	return find(parent[x]) ; 
}

void Union(int x, int y){
	int xx = find(x) ; 
	int yy = find(y) ; 
	parent[xx] = yy ; 
}

ll pow(ll x, int y){
	if (y==0){
		return 1LL ; 
	}
	ll temp = pow(x,y/2) ; 
	temp = (temp*temp)%MOD ; 
	if (y&1){
		return (temp*x)%MOD ; 
	}
	return temp ; 
}
bool cmp(pair<pair<int,int>,int>& p1, pair<pair<int,int>,int>& p2){
	return (p1.xx.xx<p2.xx.xx)?true:(p1.xx.xx==p2.xx.xx)?(p1.xx.yy<=p2.xx.yy):false ; 
}

bool rcmp(pair<pair<int,int>,int>& p1, pair<pair<int,int>,int>& p2){
	return (p1.xx.yy<p2.xx.yy)?true:(p1.xx.yy==p2.xx.yy)?(p1.xx.xx<=p2.xx.xx):false ; 
}
void dfs(int src, vvi& adj, vb& vis,vp& pt){
	vis[src] = true ; 
	++compsize ; 
	deg += adj[src].size() ; 
	diff_x.insert(pt[src].xx); 
	diff_y.insert(pt[src].yy);

	forn(j,0,adj[src].size()){
		int ch = adj[src][j] ; 
		if (!vis[ch]){
			dfs(ch,adj,vis,pt) ; 
		}
		 
	}
}


int main(){
	cin.tie(0) ; 
	ios_base::sync_with_stdio(false) ; 

	int n ; cin >> n ; 
	vvi v ; vi vvv ;  v.pb(vvv) ;  
	int x , y ; 
	vp vertical[n], horiz[n] ; 
	vp pt ; 
	pt.resize(n) ;  
	vi vx , vy ; 
	forn(i,0,n){
		cin >> x >> y ; 
		pt.pb(mp(x,y)) ; 
		
	}
	forn(i,0,n){
		vx.pb(pt[i].xx) ; 
		vy.pb(pt[i].yy) ; 
	}
	sort(all(vx)) ; 
	sort(all(vy)) ; 
	
	forn(i,0,n){
		pt[i].xx = lower_bound(all(vx),pt[i].xx)-vx.begin() ; 
		pt[i].yy = lower_bound(all(vy),pt[i].yy)-vy.begin() ; 
	}

	forn(i,0,n){
		vertical[pt[i].xx].push_back(mp(pt[i].yy,i)) ; 
		horiz[pt[i].yy].push_back(mp(pt[i].xx,i))    ; 
	}
	

	vvi adj(n,vvv) ; 
	 
	for(int i = 0 ; i < n ; i++){
		sort(all(vertical[i])) ; 
		for(int j = 1 ; j < vertical[i].size() ; j++){
			int a = vertical[i][j].yy ; 
			int b = vertical[i][j-1].yy ; 
			//cout << a << b << el ; 
			adj[a].pb(b) ; 
			adj[b].pb(a) ; 
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		sort(all(horiz[i])) ; 
		for(int j = 1 ; j < horiz[i].size() ; j++){
			int a = horiz[i][j].yy ; 
			int b = horiz[i][j-1].yy ; 
			adj[a].pb(b) ; 
			adj[b].pb(a) ; 
		}
	}

	vb cycle ;
	cycle.pb(false) ; 
	vb vis(n,false) ; 
	ll ans = 1 ; 
	for(int i = 0 ; i < n ; i++){
		deg = 0 ; compsize = 0 ; diff_y.clear() ; diff_x.clear() ; 
		if (!vis[i]){
			dfs(i,adj,vis,pt) ;
			ll sub = pow(2,diff_x.size()+diff_y.size()) ; 
			if (deg/2 == compsize-1){
				sub-- ; 
			}
			ans = (ans*sub)%MOD ; 
		}
	}
	cout << ans << el ; 

	return 0 ; 

	


}




































