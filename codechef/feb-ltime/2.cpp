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
 #define ull unsigned ll
 #define abs(x) ((x<=0)?(-x):(x))
 #define CASET  ll t;cin>>t;while(t--)
 #define FORN(i,x,y) for(ll i=x;i<y;i++)
 #define MAXN 100005
 #define INF 10000000010
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<ll,ll> PII ; typedef vector<ll> VI ; typedef vector<vector<ll> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<ll,ll> MII ; typedef map<ll,VI > MIV ; typedef set<ll> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 const ll N = 100050  ;
 const ll K = 100050 ;
 ll A[N] , D[N] ;
 ll pre[N] ;
 ll B[K] ;


 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    CASET {
        ll n , k ; cin >> n >> k ;
        ll l = 1 ;
        ll r = 0 ;
        memset(A,0,sizeof A) ;
        memset(D,0,sizeof D) ;
        memset(pre,0,sizeof pre) ;
        memset(B, 0,sizeof B) ;

        FORN(i,1,n+1){
            cin >> A[i] ;
        }
        pre[0] = 0 ;
        FORN(i,1,n+1){
            cin >> D[i] ;
            r += D[i] ;
            pre[i] = pre[i-1] + D[i] ;
        }
        FORN(i,1,k+1){
            cin >> B[i] ;
            if (i%2 == 1){
                l = r-B[i]+ 1 ;
            }
            else{
                r = l+B[i]-1 ;
            }
        }
        // cout << l << sp << r << el ;
        ll sum = 0 ;
        int lidx = 0  ; int ridx = 0 ;
        for(int i = 1; i <= n ;i++){
            if (pre[i]>=l && pre[i]-D[i]<l){
                lidx = i ;
                break ;
            }
        }
        for(int i = 1; i <= n ;i++){
            if (pre[i]>=r && pre[i]-D[i]<r){
                ridx = i ;
                break ;
            }
        }
        for(int i = lidx + 1 ; i < ridx ; i++){
            sum += A[i]*D[i] ;
        }
        if (ridx == lidx){
            sum += A[lidx]*(r-l+1);
        }
        else{
            sum += A[lidx]*(pre[lidx]-l+1) ;
            sum += A[ridx]*(r-pre[ridx-1]) ;
        }
        cout << sum << el ;
    }
}
