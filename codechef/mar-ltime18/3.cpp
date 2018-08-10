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

 char s[10*MAXN] ;

 vector<ll> div(ll num){
     vector<ll> v ;
     v.pb(1) ; v.pb(num) ;
     for(int i = 2 ; i < sqrtl(num) ; i++){
         if (num % i == 0){
             v.pb(i) ; v.pb(num/i) ;
         }
     }
     ll sq = sqrtl(num) ;
     if (sq*sq == num){
         v.pb(sq) ;
     }
     set<ll> se =set<ll>(all(v)) ;
     return vector<ll>(all(se))  ;
 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    map<ll,ll> m ;
    CASET {
        m.clear() ;
        int n ; cin >> n ;
        ll a[n] ;
        for(int i = 0 ;i < n ; i++){
            cin >> a[i] ;
        }
        ll pre[n] ;
        pre[0] = a[0] ;
        for(int i = 1 ; i < n ; i++){
            pre[i] = pre[i-1] + a[i] ;
        }
        for(int i = 0 ; i <= n ; i++) s[i] = '0' ;
        s[1] = '1' ;
        for(int i = 2 ; i <= n ; i++){
            if (pre[n-1]%i != 0) continue ; 
            ll ssum = pre[n-1]/i ;
            ll val = ssum ;
            int fl = 1 ;
            for(int j = 0 ; j < i ; j++){
                if (!binary_search(pre,pre+n,val+ssum*j)){
                    fl = 0 ; break ;
                }
            }
            if (fl)  s[i] = '1' ;
        }
        for(int i = 1 ; i<= n ; i++){
            cout << s[i] ;
        }
        cout << el ;
    }

 }
