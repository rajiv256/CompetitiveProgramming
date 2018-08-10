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
#define xx first 
#define yy second 
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

int L[MXN][2] ; 
int N,x , y ; 

int dp(int a[],int b[],int nt,int na,int nb, int idx, int fl){
	//cout << nt << sp << na << sp << nb << sp << idx <<sp<< fl << el ; 
	if (idx == 0){
		if (fl == 0){
			if (na > 0){
				return a[0] ; 
			}
			else 
				return INT_MIN ; 
		}
		if (fl == 1){
			if (nb >0) 
				return b[0] ; 
			else 
				return INT_MIN ; 
		}
	}
	if (L[idx][fl] != -1){
		return L[idx][fl] ; 
	}
	int ff = INT_MIN ; int ss = INT_MIN ; 
	if (na > 0)
		ff= L[idx-1][0] = dp(a,b,nt-1,na-1,nb,idx-1,0) ; 
	if (nb > 0)
		ss = L[idx-1][1] = dp(a,b,nt-1,na,nb-1,idx-1,1) ;

	if (na > 0 && fl == 0){
		return a[idx]+max(ff,ss) ; 	
	}
	if (nb>0 && fl==1){
		return b[idx]+max(ff,ss) ; 	
	}

	return 0 ; 
}


int main(){
	cin >> N >> x >> y ; 
	int a[N] ; int b[N] ; 
	forn(i,0,N){
		cin >> a[i] ; 
	}
	forn(i,0,N){
		cin >> b[i] ;
	}
	forn(i,0,MXN){
		forn(j,0,2){
			L[i][j] = -1 ; 
		}
	}
	int xx = L[N-1][0] = dp(a,b,N,x,y,N-1,0) ; 


	
	int yy = L[N-1][1] = dp(a,b,N,x,y,N-1,1) ; 
	
	cout << max(xx,yy) ; 



}