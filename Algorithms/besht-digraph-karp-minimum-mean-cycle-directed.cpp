/*
   Resilience is the greatest of all virtues
   Code by rajiv
*/
// Tags : Minimum Mean Cycle , Strongly Connected Graph, Karp's algorithm
// Link : https://www.codechef.com/problems/AVGSHORT

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

 double dp[550][550] ;

 /*
 -  Karp's algorithm to find the Minimum Mean Cycle is applicable only for Strongly connected graphs.
 -  If the graph is not strongly connected, then we divide the graph into strongly connected components
    and apply Karp's algorithm on each of them.
 - According to his Algorithm,

    Minimum_Mean_Cycle_wt = minV{ maxK { (dist[n][v]-dist[k][v])/(n-k) }}
    where ,
     n -> No.of vertices in the graph/component.
     dist[n][v] -> distance of a path with exactly n-edges from an arbitrary source node to the node 'v'
     dist[k][v] -> length of a path from source to 'v' with exactly 'k' edges.
    A detailed Proof of this algorithm is available here : http://www.sciencedirect.com/science/article/pii/0012365X78900110
*/


 void dfs(int src, vector<vector<pair<int,double> > >& adj , VB& vis){
     vis[src] = true ;
     for(int i = 0 ; i < adj[src].size() ; i++){
         int ch = adj[src][i].xx ;
         if (!vis[ch]){
             dfs(ch,adj,vis) ;
         }
     }
     return ;
 }
 // Just following from the Karp's algorithm.
 // dp[k][v] is the distance of the path from 'src' to the vertex 'v' that has exactly k-edges.
 // If no such path exists then the value will be INF.
 void minimum_mean_cycle(int src,vector<vector<pair<int,double> > >& adj ,  int n){
     for(int i = 0 ; i <= n ; i++){
         for(int j = 0 ; j <= n ; j++){
             dp[i][j] = INF ;
         }
     }
     dp[0][src] = 0 ;
     for(int k = 1; k <= n ; k++){
         for(int i = 0 ; i < n ; i++){
            for(auto it : adj[i]){
                int u = i ; int v = it.xx ; double w = it.yy ;
                dp[k][v] = min(dp[k][v],dp[k-1][u]+w) ;
            }
         }
     }
 }
 int main(){
     ios_base::sync_with_stdio(false) ;
     cin.tie(0) ;

     int t ; cin >> t ;
     while (t--){
         int n , m ; cin >> n >> m ;
         int x , y , w ;
         vector<vector<pair<int,double> > >adj(n,vector<pair<int,double> >()) ;
         vector<vector<pair<int,double> > >adjRev(n,vector<pair<int,double> >()) ;
         for(int i = 0 ; i < m ; i++){
            cin >> x >> y >> w ; x-- ; y-- ;
            adj[x].pb({y,w}) ;
            adjRev[y].pb({x,w}) ;
         }
         VB vis(n,false) ;
          VB visRev(n,false) ;
         int a, b ; cin >> a >> b ; a-- ; b-- ;
         dfs(a,adj,vis) ;

         if (!vis[b]){
             cout << -1 << el ;
             continue ;
         }
         else{
             // We need this dfs because the graph should be strongly connected and the Karps algorithm is valid for
             // strongly connected graphs only.
             dfs(b,adjRev,visRev) ;
             
             minimum_mean_cycle(a,adj,n) ;
             double ans = INF ;
             for(int i = 1 ; i < n ; i++){
                 if (dp[i][b]!=INF)
                    ans = min(ans,dp[i][b]/i) ;
             }
             for(int u = 0 ; u < n ; u++){
                 // This means we only need to use those vertices reachable from sink.
                 if (!visRev[u]){     // Find out why we need to do this.
                     continue ;
                 }
                 double maxi = 0 ;
                 for(int k = 0 ; k <= n-1 ; k++){
                     if (dp[n][u] > dp[k][u]){
                         maxi = max(maxi,(dp[n][u]-dp[k][u])/(n-k)) ;
                     }
                 }
                 if (maxi > 0){
                     ans = min(ans,maxi) ;
                 }
             }
             cout << setprecision(8) << ans << el;
         }
     }
 }
