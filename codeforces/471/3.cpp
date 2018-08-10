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
 ll po(ll a, ll x){
     if (x == 0) return 1 ;
     ll temp = po(a,x/2) ;
     temp = temp*temp ;
     if (x & 1 ) return a*temp ;
     return temp  ;
 }
 bool issquare(ll a){
     ll k = sqrtl(a) ;
     return (k*k==a) ;
 }
 ll intersection(ll L, ll R, ll Lsq, ll Rsq){
     ll l = max(L,Lsq) ;
     ll r = min(R,Rsq) ;
     return max(r-l+1,0LL) ;
 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	 cin.tie(nullptr) ;
     set<ll> s ;


     int Q ; cin >> Q ;

     for(ll a=2;a<=1000000;a++){
        ll val=1LL*a*a;
        int op = 18.0/log10(a) ;
        for(int k = 3; k <= op; k++){
            val*=a ;
            if(!issquare(val))
            s.insert(val);
        }
    }
     vector<ll> v = vector<ll>(all(s)) ;

     while (Q--){
         ll L , R ; cin >> L >> R ;
         ll l = lower_bound(all(v),L) - v.begin() ;
         ll r = upper_bound(all(v),R) - v.begin() ; r-- ;
         ll ans = r-l+1 ;

         ll Lsq = ceil(sqrtl(L)) ;
         ll Rsq = floor(sqrtl(R)) ;
         ans += Rsq - Lsq + 1  ;
         cout << ans << el ;
     }

 }
