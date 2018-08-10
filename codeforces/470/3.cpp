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

 const int N = 100050 ;
 ll stree[4*N] ;
 bool lazy[4*N] ;

void update(ll s, ll lo , ll hi, ll left, ll right){
     if (lo > right || hi < left){
         return ;
     }
     if (lazy[s]){
         if (2*s+1 < 4*N)
            stree[2*s+1] += 1 ;
         if (2*s+2 < 4*N)
            stree[2*s+2] += 1 ;
         lazy[s] = false ;
     }
     if (lo >=left && hi<=right){
         lazy[s] = true ;
         stree[s] += 1;
         return ;
     }
     ll mid = (lo+hi)>>1 ;
     update(2*s+1,lo,mid,left,right) ;
     update(2*s+2,mid+1,hi,left,right) ;
     stree[s] = stree[2*s+1] + stree[2*s+2] ;
     return ;
 }

 ll query(ll s, ll lo, ll hi , ll idx){

     if (idx < lo || idx > hi){
         return 0 ;
     }
     if (lo == hi && lo == idx){
         return stree[s] ;
     }
     if (lazy[s]){
         if (2*s+1 < 4*N)
         stree[2*s+1] += 1 ;
         if (2*s+2 < 4*N)
         stree[2*s+2] += 1 ;
         lazy[s] = false ;
     }
     ll mid = (lo+hi)>>1 ;
     if (idx <= mid)
        return  query(2*s+1,lo,mid,idx) ;
     return query(2*s+2,mid+1,hi,idx) ;
 }


 ll V[N] ;
 ll T[N] ;
 ll extra[N] ;
 ll F[N] ;
 VI pre ;

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    ll n ; cin >> n ;
    FORN(i,0,n){
        cin >> V[i] ;
    }
    FORN(i,0,n){
        cin >> T[i] ;
    }
    pre.pb(0) ;
    for(ll i = 0 ; i < n ; i++){
        pre.pb(pre[i]+T[i]) ;
    }
    memset(stree,0,sizeof stree) ;
    memset(lazy,false,sizeof lazy) ;
    memset(extra,0,sizeof extra) ;
    memset(F,0,sizeof F) ;
    for(int i = 0 ; i < n ; i++){
        int idx = upper_bound(all(pre),pre[i]+V[i])-pre.begin() ;
        idx-- ;
        int preidx = idx ;
        int tidx = idx-1 ;
        F[i] += 1 ;
        F[tidx+1] -= 1 ;
        extra[tidx+1] += V[i]-(pre[preidx]-pre[i]) ;
    }
    for(int i = 1 ; i < N-1 ; i++){
        F[i] += F[i-1] ;
    }
    ll ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        cout <<  F[i]*T[i] + extra[i] << " " ;
    }
    return 0 ;
 }
