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

typedef struct query {
	char c ;
	int fst ;
	ll snd ;

}query ;

set<pair<ll,int> > ans ;

ll dfs(int src, vvi& adj, vb& vis, ll a[], int comp[], int n, int cnum){

	vis[src] = true ;
	ll ret = a[src] ;
	comp[src] = cnum ;

	forn(i,0,adj[src].size()){
		int child = adj[src][i] ;
		if (!vis[child]){
			ret += dfs(child,adj,vis,a,comp,n,cnum) ;
		}
	}
	return ret ;

}

ll compSum[5*MXN] ;
int compMap[5*MXN] ;

int find(int x){
	if (compMap[x] == -1){
		return x ;
	}
	return find(compMap[x]);
}

pair<ll,int> Union(int x , int y){

	int xx = find(x) ;
	int yy = find(y) ;
	//cout << xx << "  " << yy << el ;
	if (xx != yy){
		ans.erase(mp(compSum[yy],yy)) ;
		ans.erase(mp(compSum[xx],xx)) ;

		compMap[yy] = xx ;
		compSum[xx] += compSum[yy] ;


	}
	return mp(compSum[xx],xx);
}

int main(){

	int n , m , qq ; sci(n) ; sci(m) ; sci(qq) ;

	ll a[n] ; forn(i,0,n) cin >> a[i] ;

	vi v ; vvi adj(n,v) ;


	vector<pair<int,int> > edges ;

	int x , y ;

	forn(i,0,m){
		sci(x) ; sci(y) ;   x-- ; y-- ;
		edges.pb(mp(x,y)) ;
	}

	vector<int> eq ;


	char c ; int f ; ll s;



	std::vector<query> Q;

	ll actual_val[qq] ;



	forn(i,0,qq){
		query q ;
		cin >> c ;
		q.c = c ;
		if (c == 'P'){
			sci(f) ;

			f-- ;

			q.fst = f ;

			scll(s) ;  q.snd = s ;

			actual_val[i] = a[f] ;

			a[f] = s ;

		}
		if (c == 'D'){
			sci(f) ;

			f-- ;

			q.fst = f ;

			eq.pb(f) ;

		}
		Q.pb(q) ;

	}

	sort(all(eq)) ;


	forn(i,0,edges.size()){
		if (!binary_search(all(eq),i)){
			x = edges[i].xx ;
			y = edges[i].yy ;
			adj[x].pb(y) ;
			adj[y].pb(x) ;
		}
	}

	// cout << "came here!" << el ;
	int comp[n] ; vb vis(n,false) ; int cnum = 0 ;

	forn(i,0,n) compSum[i] = 0 ;



	for(int i = 0 ; i < n ; i++){
		if (!vis[i]){

			compSum[cnum] = dfs(i,adj,vis,a,comp,n,cnum) ;
			ans.insert(mp(compSum[cnum],cnum)) ;
			cnum++ ;
		}
	}
	for(int i = 0 ; i < n ; i++){
		compMap[i] = -1 ;
	}

	vector<ll> fin ;

	// forn(j,0,qq){
	// 	cout << Q[j].c << "  " << Q[j].fst << el ;
	// }

	for(int i = qq-1 ; i >=0  ; i--){


		query q = Q[i] ;
		//cout << q.c << el ;
		if (q.c == 'P'){

			set<pair<ll,int> >::iterator it = ans.end() ; it-- ;

			fin.pb((*it).xx) ;

			int xx = find(comp[q.fst]) ;

			ll diff = actual_val[i] - q.snd ;



			ans.erase(mp(compSum[xx],xx)) ;

			compSum[xx] += diff ;

			ans.insert(mp(compSum[xx],xx)) ;


		}

		if (q.c == 'D'){

			set<pair<ll,int> >::iterator it = ans.end() ; it-- ;
			fin.pb((*it).xx) ;

			int compX = comp[edges[q.fst].xx] ;
			int compY = comp[edges[q.fst].yy] ;

			ans.insert(Union(compX,compY)) ;

		}
	}



	reverse(all(fin)) ;
	forn(i,0,fin.size()){
		printf("%lld\n",fin[i]);
	}


}
