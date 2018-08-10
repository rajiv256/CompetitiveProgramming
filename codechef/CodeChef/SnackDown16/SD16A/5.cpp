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
//#define sci(x) scanf("%d",&x)
#define MXN 1000003
#define gc getchar_unlocked	

vp v ; 
stree[2*MXN] ; 



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

int a[MXN] ; 
int L{MXN] ; 





int main(){
	
	vp v ; int n ; int q ; sci(n) ; sci(q) ; 
	int x , y  ; 
	forn(i,n){
		sci(x) ;sci(y) ; 
		v.pb(mp(y,x)) ; 
	}
	sort(all(v)) ; 
	vp v1 ; 
	forn(i,v.size()){
		v1.pb(mp(v[i].yy,v[i].xx)) ; 
	}
	for(int i = 0 ; i < v1[i].size() ; i++){
		L[v[i].yy] = 1 ;  
	}
	
	for(int i = 1 ; i < n ; i++){
		for(int j = i+1 ; j < n ; j++){
			if (v[j].xx > v[i].yy){
				if (L[j] < 1+L[i]){
					L[j] = 1+L[i] ; 
				}
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

























