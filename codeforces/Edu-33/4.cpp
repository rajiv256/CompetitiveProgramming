/* Resilience is the greatest of all virtues
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
 const int N = 1000050 ;
 ll fact[N] ;
 ll invfact[N] ;
 int erat[N] ;

 ll pw(ll a , ll b){
     if (b == 0) return 1 ;
     ll res = pw(a,b/2) ;
     res = (res*res)%MOD ;
     if (b&1) return (res*a)%MOD ;
     return res ;
 }
 ll ncr(ll n, ll r){
     return (((fact[n]*invfact[n-r])%MOD)*invfact[r])%MOD ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    fact[0] = 1 ;
    for(int i = 1 ; i < N ; i++){
        fact[i]  = (fact[i-1]*i)%MOD ;
    }
    invfact[N-1] = pw(fact[N-1],MOD-2) ;
    for(int i = N-2 ; i >= 0 ; i--){
        invfact[i] = (invfact[i+1]*(i+1))%MOD ;
    }
    memset(erat,0,sizeof erat) ;
    for(int i = 2 ; i < N ; i++){
        if (erat[i]!=0){
            continue ;
        }
        erat[i] = i ;
        for(int j = 2  ; i*j < N ; j++){
            erat[i*j] = i ;
        }
    }

    int q ; cin >> q ;
    ll x , y ;

    while (q--){
        cin >> x >> y ;
        int cnt = 0 ; int last = 0 ; ll ans = 1 ;
        while (x > 1){
            int p = erat[x] ;
            if (erat[x]==last){
                ++cnt ;
            }
            else{
                ans = (ans*ncr(cnt+y-1,cnt))%MOD ;
                cnt = 1 ;
            }
            last = p ;
            x /= p ;
        }
        ans = (ans*ncr(cnt+y-1,cnt))%MOD ;
        ans = (ans*(pw(2,y-1)))%MOD ;
        cout << ans << el ;
    }











 }
