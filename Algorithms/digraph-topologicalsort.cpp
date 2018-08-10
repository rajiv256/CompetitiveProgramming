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
 #define MAXN 100005
 #define INF 10000000010
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 int cnt ;
 int ts[MAXN] ;

 void dfs(int src, VVI& adj, VB& vis){
     vis[src] = true ;
     for(auto i : adj[src]){
         if (!vis[i]){
             dfs(i,adj,vis) ;
         }
     }
     ts[--cnt] = src ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int n , m ; cin >> n >> m ;
    cnt = n ; int x, y;
    VVI adj(n,VI()) ;
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y ; x-- ; y-- ;
        adj[x].pb(y) ;
    }
    memset(ts,-1,sizeof ts) ;
    VB vis(n,false) ;
    for(int i = 0 ; i < n ; i++){
        if (!vis[i]){
            dfs(i,adj,vis) ;
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << ts[i]+1 << sp  ;
    }
    cout << el ;
    return 0 ;

 }
