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


 vector<ll> dp(1<<20,0) ;
 vector<ll> tdp(1<<20,0) ;
 bool prime[100] ;
 int p[20] ;

 void sieve(){

     for(int i = 0 ; i < 100 ; i++){
         prime[i] = true ;
     }
     for(int i = 2 ; i < 100 ; i++){
         if (prime[i]){
             for(int j = 2 ; i*j<100 ; j++){
                 prime[i*j] = false ;
             }
         }
     }
 }


 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    sieve();
    int cnt = 0 ;
    for(int i = 2 ; i < 70 ; i++){
        if (prime[i]){
            p[cnt++] = i ;
        }
    }
    dp[0] = 1 ;
    int n ; cin >> n ;
    int co[72] ;
    clr(co) ;
    for(int i = 0 ; i < n ; i++){
        int x ; cin >> x ;
        for(int j = 0 ; j < cnt ; j++){
            while (x %(p[j]*p[j]) == 0) x /= (p[j]*p[j]) ;
        }
        co[x]++ ;
    }
    for(int i = 1 ; i <= 70 ; i++){

        if (co[i]!=0){
            ll mo = 1 ;
            for(int j = 0 ; j < co[i]-1 ; j++){
                mo = (mo*2)%MOD ;
            }
            for(int j =0 ; j < 1<<20 ; j++){
                tdp[j] = 0 ;
            }

            int tmp = 0 ;
            for(int j = 0; j < cnt ; j++){
                int i1 = i ;
                while (i1%p[j]==0) {
                    i1 /= p[j] ;
                    tmp ^= 1<<j ;
                }
            }
            for(int j = 0 ; j < 1<<20 ; j++){
                tdp[j^tmp] += mo*dp[j] ;
                tdp[j^tmp] %= MOD ;
                tdp[j] += mo*dp[j] ;
                tdp[j] %= MOD ;
            }
            swap(dp,tdp) ;
        }
    }
    ll ans = dp[0] ;
    ans -= 1 ;
    ans += MOD ;
    ans %= MOD ;
    cout << ans << el  ;

 }
