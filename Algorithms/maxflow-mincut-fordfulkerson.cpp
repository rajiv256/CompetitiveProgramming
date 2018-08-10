/* Resilience is the greatest of all virtues
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
 #define INF 1000000010
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 const int N = 5050 ;

 ll graph[N][N] ;
 ll res[N][N] ;  // residual graph
 bool vis[N] ;
 ll n, m ;
 int parent[N] ;
 ll pathMin = INF ;

 bool bfs(int src, int sink){
     pathMin = INF ;
     queue<int> q ;
     q.push(src);

     memset(vis,0,sizeof vis) ;

     while (!q.empty()){
         int s = q.front() ;
         q.pop() ;
         vis[s] = true ; 
         for(int i = 0 ; i < n ; i++){
             if (!vis[i] && res[s][i] != 0){
                 q.push(i) ;
                 parent[i] = s ;
                 vis[i] = true ;
                 if (i == sink){
                     return true ;
                 }
             }
         }
     }
    return false ;
 }

 ll maxflow(int src, int sink){
     ll ret = 0 ;
     while (bfs(src,sink)){
         pathMin = INF ;
         int st = sink ;
         while (st != src){
             pathMin = min(pathMin,res[parent[st]][st]) ;
             st = parent[st] ;
         }
         ret += pathMin ;
         st = sink ;
         while (st != src){
             res[parent[st]][st] -= pathMin ;
             st = parent[st] ;
         }

     }
     return ret ;
 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    memset(graph,0,sizeof graph) ;
    memset(res,0,sizeof res) ;

    scanf("%lld%lld",&n,&m) ; ll x , y , w ;
    FORN(i,0,m){
        scanf("%lld%lld%lld",&x,&y,&w) ;
        x-- ; y-- ;
        graph[x][y] = w ;
        graph[y][x] = w ;
        res[x][y] +=  w ;
        res[y][x] += w  ;
    }
    ll ans = maxflow(0,n-1) ;
    cout << ans << el ;

 }
