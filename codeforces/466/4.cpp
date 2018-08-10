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

 ll e9 = 1000000000 ;
 ll me9 = -1000000000 ;
 pair<ll,ll> rp ;
 pair<ll,ll> lp ;

 ll a[MAXN] ;
 ll b[MAXN] ;
 typedef struct node {
     ll m, M ;
 }node ;
 node stree[4*MAXN] ;
 void build(int s, int lo, int hi, int idx){
     if (idx < lo || idx >hi){
         return  ;
     }
     if (lo==hi && lo==idx){
         stree[s].m = a[idx] ;
         stree[s].M = a[idx] ;
         return ;
     }
     int mid = (lo+hi)>>1 ;
     build(2*s+1, lo, mid, idx) ;
     build(2*s+2, mid+1 , hi, idx) ;
     stree[s].m = min(stree[2*s+1].m, stree[2*s+2].m) ;
     stree[s].M = max(stree[2*s+1].M, stree[2*s+2].M) ;
 }
 pair<ll,ll> query(int s, int lo , int hi, int left, int right){
     if (lo > right || hi<left){
         return mp(INF,-INF) ;
     }
     if (lo>=left && hi<=right){
         return mp(stree[s].m, stree[s].M) ;
     }
     int mid = (lo+hi)>>1 ;
     pair<ll,ll> p1 = query(2*s+1,lo,mid,left,right) ;
     pair<ll,ll> p2 = query(2*s+2,mid+1,hi,left,right) ;
     return mp(min(p1.xx,p2.xx),max(p1.yy,p2.yy)) ;
 }
 pair<ll,ll> intersect(pair<ll,ll> p1, pair<ll,ll> p2){
     return mp(max(p1.xx,p2.xx),min(p1.yy,p2.yy)) ;
 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int n ; cin >> n ;
    FORN(i,0,n){
        cin >> a[i] ;
        build(0,0,n-1,i) ;
    }
    string sb ; cin >> sb ;
    FORN(i,0,n){
        b[i] = (ll)(sb[i]-'0') ;
    }
    lp = mp(me9,e9) ;
    rp = mp(me9,e9) ;
    pair<ll,ll> q ;
    for(int i = 4 ; i < n ; i++){
        if (b[i] != b[i-1]){
            if (b[i-1]==1){
                q = query(0,0,n-1,i-4,i) ;
                rp = intersect(rp,mp(me9,q.xx-1)) ;
            }
            if (b[i-1]==0){
                q = query(0,0,n-1,i-4,i) ;
                lp = intersect(lp,mp(q.yy+1,e9)) ;
            }
        }
    }
    cout << lp.xx << sp << rp.yy << el ;
    return 0 ;
 }
