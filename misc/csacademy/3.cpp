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
 ll maxi = -1000000000000LL ;
 vector<ll> fact(ll n){
     vector<ll> v ;
     if (n <= 0){
         return v ;
     }
     int i = 2 ;
     for(; i*i < n ; i++){
         if (n % i == 0){
             v.pb(i) ;
             v.pb(n/i) ;
         }
     }
     if (i*i == n) v.pb(i) ;
     v.pb(n) ; v.pb(1) ;
     return v ;
 }



 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int n ; cin >> n ;
    ll a[n] , b[n] ;
    maxi = -1 ;
    FORN(i,0,n){
        cin >> a[i] ;
        maxi = max(maxi,a[i]) ;
    }
    FORN(i,0,n) cin >> b[i] ;
    FORN(i,0,n){
        if (a[i] == 0 && b[i] == 0){
            continue ;
        }
        if (b[i] > a[i]){
            cout << -1 << el ;
            return 0 ;
        }
    }
    int cnt = 0 ;
    FORN(i,0,n){
        if (a[i]==0 && b[i]==0){
            cnt++ ;
        }
    }
    if (cnt == n){
        cout << -1 << el ;
        return 0 ;
    }
    int i = 0 ;
    while (a[i]==0 && b[i] == 0) i++ ;
    ll g = a[i]-b[i] ;
    for(; i < n ; i++){
        if (a[i] == 0 && b[i] == 0){
            continue ;
        }
        g = __gcd(a[i]-b[i],g) ;
    }
    vector<ll> v ; 
    v.pb(g) ;
    v.pb(maxi+1) ;
    if (v.size() == 0){
        cout << -1 << el ;
        return 0 ;
    }
    sort(all(v)) ;
    v.pb(maxi+1) ;
    ll x = -1 ;
    for(auto p : v){
        int fl = 1 ;
        FORN(i,0,n){
            if (a[i]==0 && b[i] == 0) continue ;
            if (b[i] != a[i]%p){
                fl = 0 ;
                break ;
            }
        }
        if (fl){
            x = p ; break ;
        }
    }

    cout << x << el ;
    return 0 ;
 }
