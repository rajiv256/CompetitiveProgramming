/*
 Resilience is the greatest of all virtues
 Code by rajiv

 Tags : Matrix exponentiation, Recurrence Relation
 Link : https://www.codechef.com/problems/CROWD
 Recurrence : dp[N] = 2**N - (dp[N-1]+dp[N-2]+dp[N-3])

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
 #define ull unsigned ll  #define abs(x) ((x<=0)?(-x):(x))
 #define MAXN 100005
 #define INF 10000000010
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793
 #define Mod(x) ((x)%MOD)

 typedef pair<ll,ll> PII ; typedef vector<ll> VI ; typedef vector<vector<ll> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<ll,ll> MII ; typedef map<ll,VI > MIV ; typedef set<ll> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 ll power2(ll n)
{
    if (n == 0) return 1LL ;
    ll res = power2(n/2) ;
    res = (res*res)%MOD ;
    if (n&1){
        res = (res*2)%MOD ;
    }
    return res ;
}

 void multiply(ll F[3][3], ll M[3][3]){
    ll P[3][3] = {{0,0,0},{0,0,0},{0,0,0}} ;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            for(int k = 0 ; k < 3 ; k++){
                P[i][j] = (P[i][j]+(F[i][k]*M[k][j])%MOD)%MOD ;
            }
        }
    }
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            F[i][j] = P[i][j] ;
        }
    }
 }
 void power(ll F[3][3], ll n){
      if( n == 0 || n == 1){
          return;
      }

      ll M[3][3] = {{1,1,1},{1,0,0},{0,1,0}};
      power(F, n/2);
      multiply(F, F);
      if( n%2 != 0 ){
         multiply(F, M);
     }
}
 int main(){
     int t ; cin >> t ;
     while (t--){
         long long n ; cin >> n ;
         ll a ,  b  ;
         ll c ;
         ll F[3][3]={{1,1,1},{1,0,0},{0,1,0}};
         power(F,n);
         a=4*F[2][0]+2*F[2][1]+F[2][2];
         b=power2(n);
         c=b-a;
         while(c<0)
         c+=1000000007;
         printf("%lld\n",c);
     }
 }
