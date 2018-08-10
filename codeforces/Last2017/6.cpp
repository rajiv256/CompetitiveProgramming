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
 #define INF 1000000007
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 #define ub upper_bound
 #define lb lower_bound
 int fd[3*MAXN] ;
 int bd[3*MAXN] ;


 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    vector<ll> g , r, b , gi,bi,ri ;
    int n ; cin >> n ;
    char ch ; ll x  ;
    g.pb(-1000000000000LL) ;
    FORN(i,0,n){
        cin >> x >> ch ;
        if (ch == 'G'){g.pb(x) ; gi.pb(i) ; }
        if (ch == 'B'){b.pb(x) ; bi.pb(i) ; }
        if (ch == 'R'){r.pb(x) ; ri.pb(i) ; }
    }
    g.pb(1000000000000LL) ;
    sort(all(g)) ; sort(all(b)) ; sort(all(r)) ;
    ll ans = 0 ;
    int st =  0 ;
    while (st < b.size()){
        ll bst = b[st] ;
        ll gst = *(lb(all(g),bst)-1) ;
        ll gen = *(ub(all(g),bst)) ;
        ll ret = gen-b[st] ;
        while (st < b.size() && st+1 < b.size() && b[st]<gen && b[st+1]<gen){
            ret = min(ret,b[st]-gst+gen-b[st+1]) ;
            st++ ;
        }
        if(st<b.size() && b[st]<gen)
            ret = min(ret,b[st]-gst) ;
        ans += ret ;
        st++ ;
    }
    st =  0 ;
    while (st < r.size()){
        ll rst = r[st] ;
        ll gst = *(lb(all(g),rst)-1) ;
        ll gen = *(ub(all(g),rst)) ;
        ll ret = gen-r[st] ;
        while (st < r.size() && st+1 < r.size() && r[st]<gen && r[st+1]<gen){
            ret = min(ret,r[st]-gst+gen-r[st+1]) ;
            st++ ;
        }
        if(st<r.size() && r[st]<gen)
            ret = min(ret,r[st]-gst) ;
        ans += ret ;
        st++ ;
    }
    for(int i = 2 ; i < g.size()-1 ; i++){
        ans += g[i]-g[i-1] ;
    }
    cout << ans << el ;
 }
