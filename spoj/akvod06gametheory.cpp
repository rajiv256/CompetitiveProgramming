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

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;
#define pb push_back
#define mp make_pair

int L[1003][1003] ; 
int v[1003] ; 
int mex(){
	int num = 0 ; 
	while (v[num]==true){
		num++ ; 
	} 
	return num ; 
}



int grundy(int A , int Z ){
	if (A <= 0){
		return 0 ; 
	}
	
	if (L[A][Z] != -1){
		return L[A][Z] ; 
	}
	else{

		memset(v,false,sizeof(v)) ; 
		forn(i,1,Z+1){
			if (A-i >= 0 && i<=A-i){
				L[A-i][i] = grundy(A-i,i) ; 
				v[L[A-i][i]] = true ;
			}	 
		}
		return mex() ;
	}
}



int main(){
	int t ; sci(t) ; 
	while (t--){
		int n , z ; sci(n) ; sci(z) ; 
		int a[n] ; 
		forn(i,0,n){
			sci(a[i]) ; 
		}
		int ans = 0 ;
		forn(p,0,1003){
			forn(q,0,1003){
				L[p][q] = -1 ; 
			}
		} 
		forn(i,0,n){
			ans ^= grundy(a[i],z) ; 
		}
		if (ans == 0){
			printf("Butters\n") ; 
		}
		else
			printf("Cartman\n") ; 

	}
	return 0 ; 
}