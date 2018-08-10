/* Resilience is the greatest of all virtues
 Code by rajiv
 */
 /*
  Tags  : Matrix exponentiation , Recurrence relations
  Link  : https://www.codechef.com/problems/CSUMD
  Recurrence relation : dp[N] = 2*dp[N-1] + 2*dp[N-2]
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

 ll p2(ll x){
     if (x == 0) return 1LL ;
     ll ret = p2(x/2) ;
     ret = (ret*ret)%MOD ;
     return (x&1)?(2*ret)%MOD : ret ;
 }

 void multiply(ll A[2][2], ll B[2][2]){

     const int ROWS= 2 ;
     const int COLS = 2 ;
     const int COLS2 = 2 ;
     ll P[ROWS][COLS] ;
     FORN(i,0,ROWS){
         FORN(j,0,COLS2){
             P[i][j] = 0 ;
             FORN(k,0,COLS){
                P[i][j] = (P[i][j]+A[i][k]*B[k][j])%MOD ;
             }
         }
     }
     FORN(i,0,ROWS){
         FORN(j,0,COLS2){
             A[i][j] = P[i][j] ;
         }
     }
 }

 void power(ll A[2][2], ll x){
     if (x <= 1) return ;
     ll M[2][2] = {{2,2},{1,0}} ;
     power(A,x/2) ;
     multiply(A,A) ;
     if (x&1){
         multiply(A,M) ;
     }
     return ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    CASET{
        ll n ; cin >> n ;

        ll A[2][2] = {{2,2},{1,0}} ;
        if (n == 1){
            A[0][0] = 1; A[0][1] = 0 ;
            A[1][0] = 0 ; A[1][1] = 1 ;
        }
        power(A,n-1) ;
        ll ans = (3*A[1][0]+A[1][1])%MOD ;
        cout << ans << el ;
    }
 }
