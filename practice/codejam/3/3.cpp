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


int adj[102][102] ; 

int dist[102][102] ; 


int main(){
	int t ; sci(t) ; int kase = 1 ; 


	while (t--){
		int n , m , P ; sci(n) ; sci(m) ; sci(P) ; 

		memset(adj,0,sizeof(adj)) ; 
		forn(i,0,m){
			int u , v , d ; sci(u) ; sci(v) ; sci(d) ; u-- ; v-- ; 
			adj[u][v] = d ; 
			adj[v][u] = d ; 
		}

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if (adj[i][j] != 0){
					dist[i][j] = adj[i][j] ; 
				}
				else 
					dist[i][j] = INF ; 
			}
		}

		for(int i = 0 ; i < n ; i++){
			dist[i][i] = 0 ; 
		}
		
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				if (i == k || dist[i][k] == INF) continue;
				for (int j = 0; j < n; j++) {
					if (j == k || j == i || dist[k][j] == INF) continue;
					if (dist[i][j] == INF || dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}

		
		
		double total  = 0.0 ; 
		double first  = 0.0 ; 
		double second = 0.0 ;
		double rem    = 0.0 ;  
			
		for(int i= 1 ; i < n ; i++){
			first += dist[0][i] ; 	
		}


		double avg[n] ; 
		memset(avg,0,sizeof(avg)) ; 

		for(int i = 1 ; i < n ; i++){
			for(int j = 0 ; (j < n)  ; j++){
				if (j == i) continue ; 
				avg[i] += dist[i][j] ; 
			}
			avg[i]/= (n-1) ; 

		}
		double f2 = 0.0 ; 
		for(int i = 1 ; i < n ; i++){
			f2 += dist[0][i]+avg[i] ; 
		}
		f2 /= (n-1) ; 



		for(int i = 0 ; i < n; i++){
			for(int j = 0 ; j < n ; j++){	
				if (j == i) continue ;
				rem += dist[i][j] ; 
			}
		}
		double avgfirst = first/(n-1) ; 
		double avgrem = rem/(n*(n-1)) ; 

		
		 
		if (P == 1){
			printf("Case #%d: %.10f\n",kase, avgfirst) ;
			kase++ ; 
			continue ; 
		}

		

		double tot = f2 + avgrem*(max(0,P-2)) ; 

		printf("Case #%d: %.9f\n",kase, tot);

		kase++ ; 




	}














}