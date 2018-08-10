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


typedef struct node {
	int num ; 
	bool fresh ; 
	set<int> pnums ; 
}node ; 

set<int> ss ; 
set<int> getposs(int src, int dest , int w, vector<node>& nodes){
	ss.clear() ;  
	if (w == 0){
		ss = nodes[src].pnums ; 
	}
	else{
		for(set<int> :: iterator it = nodes[src].pnums.begin(); it != nodes[src].pnums.end() ; it++){
			ss.insert((*it) - 1); 
			ss.insert((*it) + 1) ; 
		}
	}
	return ss ; 
}
set<int> intersection(set<int>& s1, set<int>& s2){
	vector<int> v(max(s1.size(),s2.size())) ; 
	vi :: iterator it = set_intersection(all(s1),all(s2),v.begin()) ; 
	v.resize(it-v.begin()) ; 
	ss.clear() ; 
	ss = set<int>(all(v)) ; 
	return ss ;
}	
void printset(set<int> s){
	for(set<int> :: iterator it = s.begin(); it != s.end(); it++){
		printf("%d ",*it);
	}
	printf("\n");
}

int main(){
	int t; sci(t) ; 

	while (t--){
		int n , m ; sci(n) ; sci(m) ; 
		
		vector<node> nodes ; 

		for(int i = 0 ; i < n ; i++){
			node v ; v.num = i ; 
			v.fresh = true ;
			nodes.pb(v) ; 
		}
		int x, y , w ; 
		int fl = 1 ; 

		vector<pair<pair<int,int>,int> > edges ; 
		for(int i = 0; i < m ; i++){
			sci(x) ; sci(y) ; sci(w) ; x-- ; y-- ; 
			edges.pb(mp(mp(min(x,y),max(x,y)),w)) ; 
			if (x==y && w==1){
				fl = 0 ; 
			}
		}
		if (fl == 0){
			printf("no\n");
			continue ; 
		}
		sort(all(edges)) ; 
		for(int i = 0 ; i < m ; i++){
			x = edges[i].xx.xx ; y = edges[i].xx.yy ; w = edges[i].yy ;

			bool f1 = nodes[x].fresh ; 
			bool f2 = nodes[y].fresh ; 
			//printf("%d\n",i );
			if (f1 && f2){
				nodes[x].fresh = false ; 
				nodes[y].fresh = false ; 
				nodes[x].pnums.insert(1) ; 
				nodes[y].pnums = getposs(x,y,w,nodes) ;
			
			}
			if (!f1 && f2){
				nodes[y].fresh = false ; 
				nodes[y].pnums = getposs(x,y,w,nodes) ;
			}
			if (f1 && !f2){
				nodes[x].fresh = false ; 
				nodes[x].pnums = getposs(y,x,w,nodes)  ; 
			}
			if (!f1 && !f2){
				set<int> fir = getposs(x,100001,w,nodes) ; 
				set<int> s = intersection(fir,nodes[y].pnums) ; 

				// printf("sets\n");
				// printset(fir) ; 
				// printset(nodes[y].pnums) ; 
				// printf("intersection\n");
				// printset(s) ; 
				// printf("oblig line\n");

				if (s.size() == 0) fl = 0 ; 

			}
			// for(int i = 0 ; i < n ; i++){
			// 	printset(nodes[i].pnums) ; 
			// }
		}
		// for(int i = 0 ; i < n ; i++){
		// 	if (!nodes[i].fresh && nodes[i].pnums.size() == 0){
		// 		fl = 0 ; 
		// 		break ; 
		// 	}
		// }
		
		if (fl) printf("yes\n");
		else printf("no\n");

		
	}
}