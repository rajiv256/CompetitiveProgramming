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

 ll po(ll a,  ll x){
     if (x == 0) return 1 ;
     ll temp = po(a,x/2) ;
     temp = temp*temp % MOD ;
     if (x&1) return (a*temp)%MOD ;
     return temp ;
 }
 ll n , m ;
 ll P = 1 ; ll Q = 1 ;
 ll a[MAXN] ; ll b[MAXN] ;
 ll az[MAXN] ; ll bz[MAXN] ;
 ll L[MAXN] ;
 ll solve(int idx){
     if (idx == n) return 0 ;
     if (L[idx] != -1){
         return L[idx] ;
     }
     if (a[idx]== 0 && b[idx]!=0){
         L[idx+1] = solve(idx+1) ;
         ll whengreater = (m-b[idx])*po(m,az[idx+1]+bz[idx+1]) % MOD ;
         return (L[idx+1]+whengreater)%MOD ;
     }
     if (a[idx]!=0 && b[idx]==0){
         L[idx+1] = solve(idx+1) ;
         ll whenless = (a[idx]-1)*(po(m,az[idx+1]+bz[idx+1]))%MOD ;
         return (L[idx+1]+whenless)%MOD ;
     }
     if (a[idx]==0 && b[idx]==0){
         ll x = (m*(m-1))/2 ;
         ll greater = (x*(po(m,az[idx+1]+bz[idx+1])))%MOD  ;
         L[idx+1] = m*solve(idx+1) % MOD ;
         return (greater+L[idx+1])%MOD ;
     }
     if (a[idx]!=0 && b[idx]!=0){
         if (a[idx]==b[idx]){
             L[idx+1] = solve(idx+1) ;
             return L[idx+1] ;
         }
         else if (a[idx]>b[idx]){
             ll greater = po(m,az[idx+1]+bz[idx+1]) ;
             return greater ;
         }
         return 0 ;
     }
     return 0 ;
 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
     cin >> n >> m ;
     memset(az,0,sizeof az) ;
     memset(bz,0,sizeof bz) ;

    int nz = 0 ;
    FORN(i,0,n){
        cin >> a[i] ;
        if (a[i]==0) nz++ ;
    }
    FORN(i,0,n){
        cin >> b[i] ;
        if (b[i]==0) nz++ ;
    }
    for(int i = n-1 ; i>=0 ; i--){
        az[i] = az[i+1] ;
        if (a[i]==0){
            az[i] = az[i+1]+1 ;
        }
    }
    for(int i = n-1 ; i >= 0 ; i--){
        bz[i] = bz[i+1] ;
        if (b[i]==0){
            bz[i] = bz[i+1]+1 ;
        }
    }
    for(int i = 0 ; i < MAXN ; i++){
        L[i] = -1 ;
    }
    P = L[0] = solve(0) ;
    Q = po(m,az[0]+bz[0]) ;
    ll invQ = po(Q,MOD-2) ;
    ll ans = P*invQ % MOD ;
    cout << ans << el ;

 }
