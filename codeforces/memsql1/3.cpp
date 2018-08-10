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

int main(){
	int n ; cin >> n ; 
	int a[n+1] ; 
	int sum = 0 ; int pre[n+1] ; 
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
		sum += a[i] ; 
	}
	pre[1] = a[1] ; 
	for(int i = 2 ; i <= n ; i++){
		pre[i] = a[i]+pre[i-1] ; 
	}
	int L[n+2][2] ; memset(L,0,sizeof(L)) ; 
	L[n][1] = a[n] ; 
	L[n][0] = a[n] ; 

	for(int i = n ; i >= 2 ; i--){
		L[i-1][0] = max(a[i-1]+pre[n]-pre[i-1]-L[i][1],L[i][0]) ; 
		L[i-1][1] = max(a[i-1]+pre[n]-pre[i-1]-L[i][0],L[i][1]) ; 
	}
	
	cout << sum-L[1][1] << " " << L[1][1] << el ; 
	return 0 ; 
}