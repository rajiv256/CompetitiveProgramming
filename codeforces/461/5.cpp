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
 const int N = 1050 ;
 const int C = 10050 ;
 ll n , W, B , X ;
 ll cost[N] ;
 ll birds[N] ;
 ll dp[N][C] ;
 ll curr = W ;
 ll cap = W ;


 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> n >> W >> B >> X  ;
    for(int i = 1 ; i <= n ; i++){
        cin >> birds[i] ;
    }
    for(int i = 1 ; i <= n ; i++){
        cin >> cost[i] ;
    }
    memset(dp,-1,sizeof dp) ;
    dp[0][0] = W ;
    for(int i = 1 ; i <= n ; i++){
        for(int tb = 0 ; tb <= 10000 ; tb++){
            for(int j = 0 ; j <= min((ll)tb,birds[i]) ; j++){
                if (dp[i-1][tb-j] == -1) continue ;
                dp[i][tb] = max(dp[i][tb],min(dp[i-1][tb-j]+X,W+(tb-j)*B)-cost[i]*j) ;
            }
        }
    }
    ll tb = 10000 ;
    for( ; tb >= 0 ; tb--){
        if (dp[n][tb] >= 0){
            cout << tb << el ;
            return 0 ;
        }
    }
    cout << tb << el ;
    return 0 ;


 }
