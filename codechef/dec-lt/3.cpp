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
 int p  , q , N;
 ll S[2] , B[2] ;
 ll dp1[120][220] ;
 ll dp2[120][220] ;


 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    CASET {
        cin >> p >> q >> N ;
        cin >> B[0] >> B[1] ;
        cin >> S[0] >> S[1] ;
        memset(dp1,0,sizeof dp1) ;
        memset(dp2,0,sizeof dp2) ;
        dp1[0][0] = 1 ;
        // for(int i = 1 ; i <= B[0] ; i++){
        //     dp1[0][i] = 1 ;
        // }
        for(int fill = 1 ; fill <= p ; fill++){
            for(int bused = 1 ; bused <= B[0] ; bused++){
                dp1[fill][bused] = 0 ;
                for(int nco = 1 ; nco<=fill && nco <=p && nco <= S[0] ; nco++){
                    dp1[fill][bused] += dp1[fill-nco][bused-1] ;
                    dp1[fill][bused] %= MOD ;
                }
            }
        }
        // for(int i = 1 ; i  <= B[0] ; i++){
        //     cout << dp1[p][i] << sp ;
        // }
        // cout << el ;
        dp2[0][0] = 1 ;
        // for(int i = 1; i <= B[1] ; i++){
        //     dp2[0][i] = 1 ;
        // }
        for(int fill = 1 ; fill <= q ; fill++){
            for(int bused = 1 ; bused <= B[1] ; bused++){
                dp2[fill][bused] = 0 ;
                for(int nco = 1 ; nco <= fill && nco <=q && nco<=S[1] ; nco++){
                    dp2[fill][bused] += dp2[fill-nco][bused-1] ;
                    dp2[fill][bused] %= MOD ;
                }
            }
        }
        ll ans = 0  ;
        for(int ate = 0 ; ate <= p && ate <= N; ate++){
            for(int used = 0 ; used <= B[0] ; used++){
                if (used > 0){
                    ans +=  (dp1[ate][used]*dp2[N-ate][used-1] % MOD) ;
                    ans %= MOD ;
                }
                ans += ((dp1[ate][used]*dp2[N-ate][used]*2 % MOD) + (dp1[ate][used]*dp2[N-ate][used+1]%MOD)) % MOD ;
                ans %= MOD ;
            }
        }
        cout << ans << el ;


    }
    return 0 ;
 }
