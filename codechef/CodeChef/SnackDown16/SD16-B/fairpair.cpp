#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;

#define forn(i,n) for(int i = 0; i < n ; i++)
#define INF 1000000
#define LIM 1000000000
#define sp " "
#define el endl
#define ll long long
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define MXN 100003
#define MOD 1000000007
#define gc getchar_unlocked	

void sci(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

bool bpGraph[1003][1003] ; 
int parent[1003] ; 
int n ; 

bool bpm(int u , bool seen[]){
	
	for(int v = n-1 ; v >= 0 ; v--){
		//cout << v << el ; 
		if ((bpGraph[u][v] ==1) && !seen[v]){
			seen[v] = true ; 
			//cout << "Valid vertex" << el ; 
			if (parent[v]==-1 || bpm(parent[v],seen)){ 
				parent[v] = u ;
				return true ; 
			}
			
		}
		
	}
	return false  ; 
}

int maxBPM(){
	
	int result = 0 ; 
	for(int u = 0 ; u < n ;u++){
		bool seen[n] ; 
		memset(seen,false,sizeof(seen)) ; 
		//cout <<"src : " << u<< el ; 
		if (bpm(u,seen)){
			result++ ; 
		}
		
	}
	return result ; 
	
}


bool bfs(vvi& adj , int src , int sink){
	
}







int fordFulkerson(vvi& adj, int src , int sink){
	
	int rG[n+1][n+1] ; 
	forn(i,n){
		forn(j,n){
			rG[i+1][j+1] = bpGraph[i+1][j+1] ; 
		}
	}
	
	int max_flow = 0 ; 
	
	while (bfs(adj,src,sink,rG)){
		
		int path_flow= INT_MAX ; 
	   for(int v = sink ; v != src ; v= parent[u]){
		   u = parent[v] ; 
		   path_flow = min(path_flow,rG[u][v]);  
	   }
	   for(int v= sink;v!=src ; v= parent[v]){
		   rG[u][v] -= path_flow ;
		   rG[v][u] += path_flow ; 
	   }
	   max_flow += path_flow ; 
		
	}
	return max_flow ; 
	
	
	
}












int main(){
	
	int t; sci(t) ;
	while (t--){
		
		memset(bpGraph,0,sizeof(bpGraph)) ; 
		memset(parent,-1,sizeof(parent)) ; 
		sci(n) ; 
		int a[n] ; int b[n] ; 
		pair<int,int> aAug[n] ; pair<int,int> bAug[n]; 
		int aCom[n] ; int bCom[n] ; 
		forn(i,n){
			sci(a[i]) ; 
			aAug[i] = mp(a[i],i) ; 
		}
		forn(i,n){
			sci(b[i]) ; 
			bAug[i] = mp(b[i],i) ; 
		}
		sort(aAug,aAug+n) ; 
		sort(bAug,bAug+n) ; 
		int st = 1 ; 
		forn(i,n){
			aCom[aAug[i].yy] = st ; st++ ; 
		}
		st = 1 ; 
		forn(i,n){
			bCom[bAug[i].yy] = st ; st++ ; 
		}
		vi v ; 
		vvi adj(2*n+2,v)   ; 
		
		forn(i,n){
			forn(j,n){
				if (a[i] == b[j]){
					continue ; 
				}
				adj[aCom[i]].pb(bCom[i]) ;  
			}
		}
		for(int i = 1 ; i <= n ; i++){
			adj[0].pb(i) ;
			adj[n+i].pb(2*n+1); 
		}
		
		
		int ans = fordFulkerson(adj,0,2*n+1) ; 
		
		cout << n-ans << el ;
		
		forn(i,n){
			if (parent[i]==-1){
				cout << i+1 << sp ; 
				continue  ; 
			}
			cout << parent[i]+1 << sp  ; 
		}
		cout << el ; 
		
		
	}	
}
