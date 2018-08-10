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



int L[1003][1025] ; 
int a[1003] ; 

int dp(int idx , int val){
	if (idx == 0){
		if (val == 0)
			return 1 ; 
		else{
			return 0 ; 
		}
	}
	
	if (L[idx][val]!=-1){
		return L[idx][val] ; 
	}
	//for(int j = 0 ; j <= 1024 ; j++){
		L[idx-1][val] = dp(idx-1,val) ; 
		L[idx-1][val^a[idx]] = dp(idx-1,val^a[idx]) ; 
		return (L[idx-1][val] ||L[idx-1][val^a[idx]] ) ; 		
	//}
}



int main(){
	int T ; cin >> T ;
	while (T--){
		int N , K; cin >> N >> K ; 
		clr(a) ; 
		forn(i,1,N+1){
			cin >> a[i] ; 
		}
		forn(i,0,1003){
			forn(j,0,1025){
				L[i][j] = -1 ; 
			}
		}
		forn(i,0,1003){
			L[i][0] = 1 ; 
		}

		forn(j,0,1024){
			L[N][j] = dp(N,j); 		
		}
		int ans = 0 ; 
		forn(i,0,1025){
			if (L[N][i] == 1)
				ans = max(ans,K^i) ; 
		}
		cout << ans << el ; 

	}
}