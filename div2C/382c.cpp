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

 typedef pair<ll,ll> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<ll,ll> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    ll n ; cin >> n ;
    ll a[n] ;
    FORN(i,0,n){
        cin >> a[i] ;
    }
    sort(a,a+n) ;
    if (n == 1){ cout << "-1" << el ; return 0 ; }
    if (n == 2){
        ll d = a[1]-a[0] ;
        set<ll> aa ;
        aa.insert(a[0]-d) ; aa.insert(a[1]+d) ;
        if (d%2 == 0){
            aa.insert(a[0]+d/2) ;
        }
        cout << aa.size() << el ;
        for(auto it : aa){
            cout << it << sp ;
        }
        cout << el ;
        return 0 ;
    }
    map<ll,ll> m ;
    for(int i = 0 ; i < n-1 ; i++){
        m[a[i+1]-a[i]]++ ;
    }
    if (m.size() > 2){
        cout << "0" << el ;
        return 0 ;
    }
    if (m.size()==1){
        set<ll> aa ;
        aa.insert(a[0]-(a[1]-a[0])) ;
        aa.insert(a[n-1]+(a[1]-a[0])) ;
        cout << aa.size() << el ;
        for(auto it : aa){
            cout << it << sp ;
        }
        cout << el ;
        return 0 ;
    }
    VPII v ;
    for(MII::iterator it = m.begin() ; it != m.end() ; it++){
        v.pb(mp(it->yy,-it->xx)) ;
    }
    sort(all(v)) ;
    v[0].yy = -v[0].yy ;
    v[1].yy = -v[1].yy ;
    //cout << v[0].yy << sp << v[1].yy << el ;
    if (2*v[1].yy != v[0].yy || v[0].xx > 1){
        cout << "0" << el ;
        return  0 ;
    }
    set<ll> ans ;
    for(int i = 0 ; i < n-1 ; i++){
        if (a[i+1]-a[i] == v[0].yy){
            ans.insert(a[i]+v[1].yy) ;
        }
    }

    cout << ans.size() << el ;
    for(auto it : ans ){
        cout << it << sp ;
    }
    cout << el ;

    return 0 ;



 }
