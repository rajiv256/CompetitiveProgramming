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
 #include <climits>

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
 const int N = 100050 ;


 vector<pair<int,ll >> v[N] ;

 ll D[N] ;
 int n , m  ;
 int dfs(int s, ll dist){
     if (D[s] != (LLONG_MAX)){
         return (D[s] == dist)?1:0 ;
     }
     D[s] = dist ;
     int ret = 1 ;
     for(auto it : v[s]){
         int x = dfs(it.xx,dist+it.yy) ;
         ret = min(ret,x) ;
     }
     return ret ;



 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> n >> m ;
    ll l , r , d ;
    for(int i = 0 ; i < m ; i++){
        cin >> l >> r >> d ;

        v[l].pb(mp(r,d)) ;
        v[r].pb(mp(l,-d));
    }

    for(int i = 0 ; i < N ; i++){
        D[i] = LLONG_MAX ;
    }
    bool ans = true ;
    for(int i = 1 ; i <= n ; i++){
        if (D[i]==(LLONG_MAX) && dfs(i,0)==0){
            ans = false ;
            break ;
        }
    }
    cout << (ans?"Yes":"No") << el ;
 }
