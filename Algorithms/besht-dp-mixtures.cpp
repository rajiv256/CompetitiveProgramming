/*
 		Resilience is the greatest of all virtues.
 		Code by rajiv

        Problem : MIXTURES in SPOJ
        Tags : dp , Matrix Exponentiation (How?)
 */

 #include <iostream>
 #include <cstring>
 #include <vector>
 #include <map>
 #include <set>
 #include <stack>
 #include <queue>
 #include <deque>
 #include <sstream>
 #include <iomanip>
 #include <cassert>
 #include <sys/time.h>
 #include <algorithm>
 #include <bitset>
 #include <cmath>
 #include <functional>
 #include <cmath>

 using namespace std ;

 #define xx first
 #define yy second
 #define ll long long
 #define ld long double
 #define el (char)0x0A
 #define sp " "
 #define pb push_back
 #define mp make_pair
 #define all(x) (x).begin(),(x).end()
 #define clr(x) memset((x),0,sizeof(x))
 #define uint unsigned int
 #define abs(x) ((x<=0)?(-x):(x))
 #define CASET  int t;cin>>t;while(t--)
 #define FORN(i,x,y) for(int i=x;i<y;i++)
 #define MAXN 100005

 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

ll dp[120][120] ;
int n ;
#define INF 1LL<<40
int main(){
	while (scanf("%d",&n)!=EOF){
		int a[n+5] ;
		for(int i = 1 ; i <= n ; i++){
			scanf("%d",a+i) ;
		}
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ;j <= n ; j++){
                dp[i][j] = INF ;
                if (i == j) dp[i][j] = 0 ;
            }
        }
        int c[n+5] ;
        c[0] =0 ;
        c[1] = a[1] ;
        for(int i = 2 ; i <= n ; i++){
            c[i] = (c[i-1]+a[i])%100 ;
        }
        dp[0][0] = 0 ;
        for(int i = n ; i >= 1 ; i--){
            for(int j = i+1 ; j <= n ; j++){
                for(int k = i ; k <= j ; k++){ // Limits of k questionable.
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+((c[k]-c[i-1]+100)%100)*((c[j]-c[k]+100)%100)) ;
                }
            }
        }
        cout << dp[1][n] << el ;
    }
    return 0 ;
}
