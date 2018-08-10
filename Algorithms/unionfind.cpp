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
#define INF 10000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()

int parent[MXN] ; 

int find(int x){
	if (parent[x] == -1){
		return x ; 
	}
	return find(parent[x]) ; 
}
void Union(int x , int y){
	int xx = find(x) ; 
	int yy = find(y) ; 
	parent[yy] = xx ; 
}

int main(){
	int n , m ; sci(n) ; sci(m) ;
	int u , v ;  
	for(int i = 0 ; i < MXN ; i++){
		parent[i] = -1 ; 
	}
	for(int i = 0 ; i < m ; i++){
		sci(u) ; sci(v) ; 
		int uu = find(u) ; 
		int vv = find(v) ; 
		if (uu == vv){
			printf("NO\n") ; 
			return 0; 
		}
		Union(u,v) ; 
	}
	printf("YES\n") ; 
	return 0 ; 

}