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
#define sci(x) scanf("%d",&x)
#define MXN 100003
#define gc getchar_unlocked	

int parent[2*MXN] ; 
int curr = 0 ; 
int sq = 1 ; 

typedef struct edge{
	int u , v ; 
}edge;

typedef struct query{
	int idx ; 
	int l , r ; 
}query;


void Union(int x , int y){
	int xx = find(x) ; 
	int yy = find(y) ; 
	parent[yy] = xx ; 
}

int find(int x){
	if (parent[x]==-1){
		return x ; 
	}
	return find(parent[x]) ; 
}

bool comp(query a , query b){
	if (a.l/sq != b.l/sq){
		return (a.l/sq < b.l/sq) ; 
	}
	return (a.r < b.r)
}
void add(int pos){
	int x = e[pos].u ;
	int y = e[pos].v ; 
	
}



int main(){
	
	int t ; sci(t) ; 
	while (t--){
		int n , m , d ; sci(n) ; sci(m) ; sci(q) ; 
		sq = sqrt(n) ; 
		edge e[m] ; 
		memset(edge,0,sizeof(edge)) ; 
		memset(parent,0,sizeof(parent)) ; 
		int a , b ;
		forn(i,m){
			 sci(a) ; sci(b) ; a-- ; b-- ; 
			 e[i].u = a ; e[i].v = b ; 
			  
		}
		query q[d] ;
		forn(i,d){
			sci(a) ; sci(b) ; a-- ; b--; 
			q[i].idx = i ; 
			q[i].l = a ; q[i].r = b ; 
		}
		sort(q,q+d,comp) ; 
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}






int main(){
	
}
