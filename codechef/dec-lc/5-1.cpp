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
 #define INF 1000000000
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;
 ll x , y , z , a , b , c ;
 ll dp[12][12][12] ;
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int inc[7][3] = {{0,0,1},{0,1,0},{1,0,0},{1,0,1},{1,1,0},{0,1,1},{1,1,1}} ;
    int incval[7] = {0,0,0,0,0,0,0} ;
    CASET {
        cin >> x >> y >> z >> a >> b >> c ;
        vector<ll> v ; v.pb(x) ; v.pb(y) ; v.pb(z) ;
        sort(all(v)) ;


        incval[0] = a ; incval[1] = a ; incval[2] = a ;
        incval[3] = b ; incval[4] = b ; incval[5] = b ;
        incval[6] = c ;

        ll ans = (x+y+z)*a ;   // only a
        
        if (x==y && y==z){   // only c
            ans = min(ans,x*min(a+b,c)) ;
        }

        v[0] = x ; v[1] = y ; v[2] = z ;  // only a and b
        sort(all(v)) ;
        ll loc = 0 ; loc += min(2*a,b)*v[1] ; v[2] -= v[1] ;
        sort(all(v)) ;
        loc += min(2*a,b)*v[1] ; v[2] -= v[1] ; loc += v[2]*a ;
        ans = min(ans,loc) ;

        v[0] = x ; v[1] = y ; v[2] = z ;  // only b and c ;
        sort(all(v)) ;
        if (v[1] == v[2]){
            loc = c*v[0] + b*(v[1]-v[0]) ;
            ans = min(ans,loc) ;
        }

        v[0] = x ; v[1] = y ; v[2] = z ;  // only a and c ;
        sort(all(v)) ;
        loc = c*v[0] ; loc += a*(v[1]+v[2]-2*v[0]) ;
        ans = min(ans,loc) ;

        v[0] = x ; v[1] = y ; v[2] = z ;  // All a , b and c ;
        sort(all(v)) ;
        ll cost = min(3*a,min(a+b,c)) ;
        ll nremovals = v[0] ;
        loc = cost*nremovals ;
        v[1] -= v[0] ; v[2] -= v[0] ; v[0] = 0 ;

        nremovals = v[1] ;
        cost = min(2*a,b) ;
        loc += cost*nremovals ;
        v[2] -= v[1] ; v[1] = 0 ;
        loc += v[2]*a ;

        ans = min(loc,ans) ;

        v[0] = x ; v[1] = y ; v[2] = z ;  // All a , b and c ;
        sort(all(v)) ;
        nremovals = v[0]/2 ;
        cost = min(4*a+b,min(a+b+c,min(2*a+2*b,min(6*a,min(3*b,2*c))))) ;
        loc = nremovals*cost ;
        v[2] -= 2*nremovals ; v[1] -= 2*nremovals ; v[0] -= 2*nremovals ;
        if (v[0] != 0){
            nremovals = 1 ;
            cost = min(3*a,min(a+b,c)) ;
            loc += nremovals*cost ;
            v[2] -= 1 ; v[1] -= 1 ; v[0] = 0 ;
        }

        nremovals = v[1] ;
        cost = min(2*a,b) ;
        loc += nremovals*cost ;
        v[2] -= v[1] ; v[1] = 0 ;
        loc += v[2]*a ;
        ans = min(ans,loc) ;

        cout << ans << el ;


    }



 }
