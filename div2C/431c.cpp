/*
 		Resilience is the greatest of all virtues.
 		Code by rajiv
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
 #define INF 10000000010
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 const int N = 120 ;
 ll dp[10*N][10*N][2] ;
 ll n , k , d ;



 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> n >> k >> d ;
    memset(dp,0,sizeof dp) ;
    dp[0][0][0] = 1 ;
    for(int depth = 0 ; depth <= N ; depth++){
        for(int pathlen = 0 ; pathlen <= N ; pathlen++){
            for(int elen = 1 ; elen <= k ; elen++){
                dp[depth+1][pathlen+elen][1] += (dp[depth][pathlen][1] + ((elen>=d)?1:0)*dp[depth][pathlen][0]) % MOD ;
                dp[depth+1][pathlen+elen][1] %= MOD ;
                dp[depth+1][pathlen+elen][0] += ((elen>=d)?0:1)*dp[depth][pathlen][0] ;
                dp[depth+1][pathlen+elen][0] %= MOD ;

            }
        }
    }
    ll ans = 0 ;
    for(int dep = 0 ; dep < N ; dep++){
        ans += dp[dep][n][1] ;
        ans %= MOD ; 
    }
    cout << ans << el ;





















 }
