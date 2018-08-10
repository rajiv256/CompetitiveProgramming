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

bool adj[6][6] ; 
int parent[6] ; 

bool solve(int face){
	if (face == 6){
		return true ; 
	}
	for(int i = 0 ; i < 6 ; i++){
		if (parent[face] != -1){
			return solve(face+1) ; 
		}
		if (adj[face][i] && parent[i]==-1){
			parent[face] = i ; 
			parent[i] = face ; 
			if (solve(face+1)){
				return true ;
			} 
			else{
				parent[face] = parent[i] = -1 ; 
			}
		}
	}
	return false ; 

}





int main(){
	int t ; sci(t) ; 
	while (t--){
		int n ; sci(n) ; 
		int a[n] ; 
		forn(i,0,n){
			sci(a[i]) ;
			a[i]-- ; 
		}
		bool b = true ; 
		for(int i = 0 ; i < n-1 ; i++){
			if (a[i]==a[i+1]){
				b = false ; 
				break ; 
			}
		}
		if (!b){
			printf("-1\n");
			continue ; 
		}
		
		memset(adj,true,sizeof(adj)) ; 
		forn(i,0,6){
			adj[i][i] = false ; 
		}
		for(int i = 0 ; i < n ; i++){
			if (i-1 >= 0){
				adj[a[i]][a[i-1]] = false ; 
			}
			if (i+1<n){
				adj[a[i]][a[i+1]] = false ; 
			}
		} 
		
		memset(parent,-1,sizeof(parent)) ; 
		bool poss = true ;  
	 	poss = solve(0) ; 

		if (poss){
			for(int i = 0 ; i < 6 ; i++){
				printf("%d ", parent[i]+1);
			}
			printf("\n");
		}
		else{
			printf("-1\n");
		}

	}
}