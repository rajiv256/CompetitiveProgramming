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
 #define MAXN 1000005
 #define INF 10000000010
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 ll diff(ll n){
     ll ret = 0 ;
     while (n!=0){
         ll k = n%10 ;
         ret += (k&1)?-k:k ;
         n /= 10 ;
     }
     return abs(ret) ;
 }


 ll a[2*MAXN] ;
 ll dp[2*MAXN] ;
 ll pre[2*MAXN] ;

 int main(){
    a[0] = 0 ;
    memset(a,0,sizeof a) ;
    memset(dp,0,sizeof dp) ;
    memset(pre,0,sizeof pre) ;
    pre[0] = 0 ;
    for(int i = 1 ; i < 2*MAXN ; i++){
        a[i] = diff(i) ;
        pre[i] = pre[i-1]+a[i] ;
    }
    dp[0] = 0 ;
    dp[1] = 2 ;
    dp[2] = 12 ;
    dp[3] =  36 ;
    for(int i = 4 ; i < MAXN ; i++){
        dp[i] = dp[i-1] + 2*(pre[2*i-1]-pre[i]) + a[2*i] ;
    }
    CASET {
        ll N ; cin  >> N ;
        cout << dp[N] << el ;
    }

 }
