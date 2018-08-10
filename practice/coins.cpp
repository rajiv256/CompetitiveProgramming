// http://wcipeg.com/problem/dp1p2
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


int rsum(int x , int y , int pre[]){
	return pre[y]-pre[x-1] ; 
}


int main(){
	int n ; sci(n) ; 
	int a[n+2] ; a[n+1] = 0 ;  
	for(int i = 1 ; i <= n ; i++) sci(a[i]) ; 

	int L[n+2][n+2][2] ; 
	
	memset(L,0,sizeof(L)) ; 
	for(int i = 1 ; i <= n ; i++){
		L[i][i][0] = a[i] ; 
		L[i][i][1] = a[i] ; 
	}
	int pre[n+1] ; pre[1] = a[1] ; pre[0] = 0 ; 
	forn(i,2,n+1) pre[i] = pre[i-1]+a[i] ; 

	for(int i = n ; i >= 0 ; i--){
		for(int j = 1 ; j <= n ; j++){

			if (i+1 <= j){
				L[i][j][0] = max(L[i][j][0],a[i]+rsum(i+1,j,pre)-L[i+1][j][1]) ; 
				L[i][j][1] = max(L[i][j][1],a[i]+rsum(i+1,j,pre)-L[i+1][j][0]) ; 
			}
			if (i <= j-1){
				L[i][j][0] = max(L[i][j][0],a[j]+rsum(i,j-1,pre)-L[i][j-1][1]) ; 
				L[i][j][1] = max(L[i][j][1],a[j]+rsum(i,j-1,pre)-L[i][j-1][0]) ; 
			}
		}
	}
	printf("%d\n", L[1][n][1]);
	return 0 ; 

}