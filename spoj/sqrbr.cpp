#include<bits/stdc++.h>

using namespace std ;

#define sci(x) scanf("%d",&x)
#define ll long long

ll dp[50][100] ;

int main(){

	int T ; sci(T) ;
	while (T--){
		memset(dp,0,sizeof dp) ;

		int n , k ; sci(n) ; sci(k) ;
		string s = "" ;
		for(int i = 0 ; i <= 2*n ; i++){
			s += '0' ;
		}
		int x ;
		for(int i = 0 ; i < k ; i++){
			sci(x) ; s[x] = '1' ;
		}
		dp[0][0] = 1 ;
		for(int i = 1 ; i <= 2*n ; i++){
			for(int lev = 0 ; lev <= 2*n ; lev++){
				if(lev>=1){
					dp[i][lev] += dp[i-1][lev-1] ;
				}
				if (s[i] != '1')
					dp[i][lev] += dp[i-1][lev+1] ;
			}
		}
		printf("%lld\n",dp[2*n][0]) ;
	}
	return 0 ;
}
