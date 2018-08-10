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
 const int N = MAXN ;
 ll a[N] ;
 ll n , x , k ;
 pair<ll,ll> solve(int st){
     if (st%x == 0){
         return mp(st+(k-1)*x, st+k*x-1) ;
     }
     else{
         return mp(x*(st/x)+(k*x),x*(st/x)+(k+1)*x-1) ;
     }
 }


 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> n >> x >> k ;
    clr(a)  ;
    FORN(i,0,n){
        cin >> a[i] ;
    }
    sort(a,a+n) ;
    ll ans = 0 ;

    for(int i = 0 ; i < n ; i++){
        pair<ll,ll> p = solve(a[i]);
        ll st = p.xx;
        ll en = p.yy ;
        if (k == 0){
            if (a[i]%x == 0){
                continue ;
            }
            ll val = a[i]/x*x+x-1 ;
            ll* spup = upper_bound(a,a+n,val) ;
            ll* splo = lower_bound(a,a+n,a[i]) ;
            ans += spup-splo ;
            continue ;
        }
        ll* up = upper_bound(a,a+n,en) ;
        ll* lo = lower_bound(a,a+n,st) ;
        ans += max(0,(ll)(up-lo)) ;
    }
    cout << ans << el ;

 }
