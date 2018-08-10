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

int parent[MXN] ; 


bool anccheck(int a , int b){
	while (b != -1){
		if (b ==a){
			return true ; 
		}
		b = parent[b] ; 
	}
	return false  ; 
	
}

int main(){
	int n , m ; sci(n) ; sci(m) ; 
	memset(parent,-1,sizeof(parent)) ; 
	int p , q ; 
	forn(i,n){
		sci(p) ; sci(q) ; 
		parent[q] = p  ;
		vp v ; int x ; 
		forn(i,n){
			sci(x); 
			v.pb(mp(x,i+1)) ; 
		}
		
		
		
		
	}
	
	
	
	
	
}

