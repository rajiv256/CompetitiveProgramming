#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,char> > vp ;
typedef vector<vector<pair<int,char> > > vvp  ;

typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> >
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >
#define pii pair<int,int>
#define INF 1000000000
#define sp " "
#define el "\n"
#define lld long long int
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define sci(x) scanf("%d",&x)
#define mp make_pair
#define ll long long


void merge(int x , int y, vvp& dummy){

	vp v1 = dummy[x] ; 
	vp v2 = dummy[y] ; 
	forn(i,v1.size()){
		dummy[y].pb(v1[i]) ; 
	}
	forn(i,v2.size()){
		dummy[x].pb(v2[i]) ; 
	}
	return ; 

}
bool valid(int x , int n){
	if (x < 0 || x >=2*n){
		return false ; 
	}
	return true ; 
}
void fill(vvp& adj, int n , char a[] ){
	
	if (n==1){
		adj[0].pb(mp(1,a[1])) ; 
		adj[1].pb(mp(0,a[0])) ; 
		return ; 
	}
	forn(i,n){
		if (i==n-1){
			if (valid(i+n,n))
				adj[i].pb(mp(i+n,a[i+n])) ; 
			if (valid(i-1,n))
				adj[i].pb(mp(i-1,a[i-1])) ; 
			continue ; 
		}
		if (i == 0){
			if (valid(i+1,n))
			adj[i].pb(mp(i+1,a[i+1])) ;
			if (valid(i+n,n)) 
			adj[i].pb(mp(i+n,a[i+n])) ;  
			continue ; 
		}

		adj[i].pb(mp(i+1,a[i+1])) ; 
		adj[i].pb(mp(i-1,a[i-1])) ; 
		adj[i].pb(mp(i+n,a[i+n])) ; 
	}	
	for(int i = n ; i < 2*n ; i++){
		if (i == n){
			adj[i].pb(mp(i+1,a[i+1])) ;
			adj[i].pb(mp(i-n,a[i-n])) ;  
			continue ; 
		}
		if (i==2*n-1){
			adj[i].pb(mp(i-n,a[i-n])) ; 
			adj[i].pb(mp(i-1,a[i-1])) ; 
			continue ; 
		}
		adj[i].pb(mp(i+1,a[i+1])) ; 
		adj[i].pb(mp(i-1,a[i-1])) ; 
		adj[i].pb(mp(i-n,a[i-n])) ; 
	}

}

void fillLevels(int src , vvp& adj , vvi& levels, vb& vis){

	queue<pair<int,int> > q ; 
	q.push(mp(src,0)) ; 
	while (!q.empty()){
		pair<int,int> p = q.front() ; 
		q.pop() ; 
		src = p.xx  ; 
		if (vis[src]){
			continue ; 
		}
		int lev = p.yy ; 
		vis[src] = true ; 
		levels[lev].pb(src) ; 

		forn(i,adj[src].size()){
			int child = adj[src][i].xx ; 
			if (!vis[child]){
				q.push(mp(child,lev+1)) ; 
			}
		}

	}






}

bool comp(pair<int,int> p1 , pair<int,char> p2){
	if (p1.yy != p2.yy){
		return (p1.yy < p2.yy) ; 
	}
	return (p1.xx <= p2.xx) ; 
}

void reset(vvp& adj2 , vvp& adj, int n){
	forn(i,2*n){
		adj2[i].clear() ; 
	}
	forn(i,2*n){
		forn(j,adj[i].size()){
			adj2[i].pb(adj[i][j]) ; 
		}
	}
	return ; 
}
int find(int x , int parent[]){
	if (parent[x] == -1){
		return x ; 
	}
	return find(parent[x], parent) ; 
}

void Union(int x , int y , int parent[]){
	int xx = find(x,parent) ;
	int yy = find(y,parent) ; 
	parent[yy] = xx ; 
}



void dfs(int src , int seen  , int n ,int *pointer , vvp& adj, vb& vis){
	vis[src] = true ; 
	seen += 1 ; 
	if (seen==2*n){
		*pointer = *pointer+1 ; 
		cout << *pointer << el ; 
		return ; 
	}

	forn(i,adj[src].size()){

		int child = adj[src][i].xx ; 
		
		if (!vis[child]){
			//cout << src << sp << child << el ; 
			dfs(child,seen,n,pointer,adj,vis) ; 
		}
	}
}






int main(){


	
	vvp adj ; vvp adj2 ; 	
	int p ; cin >> p  ; 

	while (p--){
		int n ; cin >> n ; int sz = 2*n ; 
		
		char a[sz] ;
		string s1 ; cin >> s1 ; 
		string s2 ; cin >> s2 ;

		forn(i,s1.size()){
			a[i] = s1[i] ; 
		} 

		forn(i,s2.size()){
			a[n+i] = s2[i] ; 
		}

		vp v ; 
		forn(i,2*n){
			adj.pb(v) ; 
			adj2.pb(v) ; 
		}

		
		fill(adj,n,a) ; 
		
		
		for(int i = 0 ; i < 2*n ; i++){
			sort(all(adj[i]), comp) ; 
		}

		int ans = 0 ; 
		int parent[2*n] ; 
		forn(j,2*n){
			parent[j] = -1 ; 
		}
		bool mark[2*n] ; 
		memset(mark,false,sizeof(mark)) ; 
		for(int i = 0 ; i < 2*n ; i++){
			//reset(adj2,adj,n) ; 

			forn(j,adj[i].size()-1){
				
				if (adj[i][j].yy == adj[i][j+1].yy){
					Union(adj[i][j].xx , adj[i][j+1].xx,parent) ;  
				}
			}
			forn(j,2*n){
				cout << parent[i] << sp ; 
			}
			cout << el ; 
			int loc = 0 ; 
			vb vis(2*n,false) ; 
			if (!mark[find(i,parent)]){
				 
				dfs(find(i,parent),0,n,&loc,adj,vis) ; 
				mark[find(i,parent)] = true ; 
			}
			ans += loc ; 

		}
		cout << ans << el  ;


	}
	return 0 ; 


}