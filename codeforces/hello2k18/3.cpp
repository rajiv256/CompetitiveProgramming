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




 ll ci[40] ;
 ll pre[40] ;
 ll cost[40] ;
 ll n , L ;

 ll solve(ll L, ll idx){
     if (L < 0) return 1LL<<40 ;

     if (idx == 0){
         return (L*(cost[0])) ;
     }
     ll d = 1LL<<idx ;
     ll ans = L/d * cost[idx] + (L%d != 0)*cost[idx] ;
     //ll q1 = solve(L,idx-1) ;
     ll q2 = L/d*cost[idx] + solve(L-(L/d)*d, idx-1) ;
     ans = min(ans,q2) ;
     //cout << L << sp << idx << sp << ans << el ;
     return ans ;
 }


 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> n >> L ;
    FORN(i,0,n){
        cin >> ci[i] ;
    }
    pre[0] = ci[0] ;
    FORN(i,1,n){
        pre[i] = ci[i]+pre[i-1] ;
    }
    cost[0] = ci[0] ;
    FORN(i,1,n){
        cost[i] = min(pre[i-1]+ci[0],ci[i]) ;
    }
    FORN(i,1,n){
        cost[i] = min(cost[i],cost[i-1]*2) ;
    }
    ll d = 1LL<<(n-1) ;
    ll ans = L/d * cost[n-1] + (L%d!=0)*cost[n-1] ;
    for(int i = n-2 ; i>=0 ; i--){
        d /= 2;
        ans = L/d * cost[i] + (L%d!=0)*cost[i] ;
    }
    ans = min(ans,solve(L,n-1)) ;
    cout << ans << el ; 
    return 0 ;


 }
