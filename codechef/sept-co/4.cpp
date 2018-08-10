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


int gcd(int a, int b){
	if (b > a) return gcd(b,a) ; 
	return (b>0)?gcd(b,a%b):a ; 
}
bool po2(int num){
	if (num == 0){
		return 0 ; 
	}
	while (num != 1){
		if (num %2 !=0) return false ; 
		num /= 2 ; 
	}
	return true ; 
}


int main(){

	int n ; sci(n) ; 
	int b[n] ; 
	forn(i,0,n) sci(b[i]) ; 

	ll L[n+2][52][2502] ; clr(L) ; 
	for(int i = 0 ; i <= b[0] ; i++){
		L[0][i][i] = 1 ; 
	}
	//L[0][0][0] = 0 ; 

	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < 52 ; j++){
			for(int k = 0 ; k < 2502 ; k++){
	 			if (L[i-1][j][k] != 0){
					for(int p = 0 ; p <= b[i] ; p++){
						if ((p+k >= 2502)) continue ; 
	 						int g = gcd(p,j) ; 
							L[i][g][k+p] += L[i-1][j][k] ;
							L[i][g][k+p] %= MOD ;  
					}
	 			}
			}
		}
	}
	ll ans = 0 ; 
	for(int j = 1 ; j < 52 ; j++){
		for(int k = 0 ; k < 2502 ; k++){
			if (!L[n-1][j][k]) continue ; 
			if (!po2(k/j)) continue ; 

			ans += L[n-1][j][k] ; 
			ans %= MOD ; 
		}
	}


	printf("%lld\n", ans);

	return 0 ; 
}