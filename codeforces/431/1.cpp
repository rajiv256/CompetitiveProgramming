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

bool ans = false ; 

bool L[103][2] ; 





int main (){
	int n ; cin >> n ; 
	int a[n+1] ; 
	forn(i,1,n+1){
		cin >> a[i] ; 

	}
	L[0][0] = true ; 
	for(int i = 1 ; i <= n ; i++){
		for(int j = i ; j <= n ; j++){
			int sz = j-i+1 ; 
			if ((a[i]&1) && (a[j]&1) &&(sz&1)){
				L[j][0] |= L[i-1][1] ; 
				L[j][1] |= L[i-1][0] ; 
			}
		}
	}
	puts((L[n][1])?"Yes":"No" ); 

	return 0 ; 















}