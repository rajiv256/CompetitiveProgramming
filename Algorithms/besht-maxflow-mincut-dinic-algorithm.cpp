/* Resilience is the greatest of all virtues
    Code by rajiv

    Tags : Max flow, Mincut, Dinic algorithm , Undirected graph
    Link : http://www.spoj.com/problems/FASTFLOW/
    Complexity : O(N^2 M)
                        M -> No.of edges
                        N -> No.of vertices

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

 const int N = 5050 ;
 ll residual[N][N] ;
 vector<int> graph[N] ;
 int parent[N] ;
 bool vis[N] ;
 int level[N] ;
 int src , snk ;
 int n , m ;
 pair<int,int> Q[N] ;
 int ptr[N] ;

 /*
 - if parent[snk] == -1 then there is no path from src to snk
 - This bfs will setup the levels of each node and parent of each node.
 - Helps in finding the shortest possible path in terms of number of edges.

 */
 void bfs(){
     queue<PII > q ;
     q.push(mp(src,0)) ;
     memset(parent,-1,sizeof parent) ;
     memset(vis,false,sizeof vis) ;
     memset(level,0,sizeof level) ;
     level[src] = 0 ;
     while (!q.empty()){
         PII p = q.front() ;
         level[p.xx] = p.yy ;
         vis[p.xx] = true ;
         q.pop() ;
         for(int i = 0 ; i < n ; i++){
             if (!vis[i] && residual[p.xx][i]!=0){
                 parent[i] = p.xx ;
                 q.push(mp(i,p.yy+1)) ;
                 vis[i] = true ;
                 level[i] = p.yy+1 ;
                 if (i == snk){
                     return ;
                 }
             }
         }
     }
     return ;
 }
 /*
 - This function keeps on sending flow through the source vertex until a blocking flow.
 - This is essentially DFS which ends right after it finds the source vertex.

 - Important thing to note here is the ptr[] array. Because this keeps track of the number of
   children vertices the source has already visited before that are invalid and not lets us to
   iterate over the same vertices which are not required at all.
 - If we watch closely, what ptr[u] is  doing is that, it keeps track of how many children
   of vertex have we not found path. If we found a path through the vertex at ptr[u]-th index in graph[u]
   then the ptr[u] will not get updated to its next index unless the residual of u->i is zero. Makes sense.

 - Not using ptr gives a TLE.

 - Also note that the DFS ends as soon as it finds a path to sink.
 - If no path is found to sink it returns 0.
 */
 ll sendflow(int u , ll vload){
     if (u==snk){
         return vload  ;
     }
     for(; ptr[u] < graph[u].size() ; ++ptr[u]){
         int i = graph[u][ptr[u]] ;
         if ((level[i]==level[u]+1) && (residual[u][i]!=0)){
             ll eflow = min(vload,residual[u][i]) ;
             ll ret = sendflow(i,eflow) ;
             if (ret > 0){
                 residual[u][i] -= ret ;
                 residual[i][u] += ret ;
                 return ret ;
             }
         }
     }
     return 0 ;
 }
 /*
    => First do the bfs and find the levels.
    => Next do DFS(sendFlow) until you don't have an augmenting path.
    => But it is not like that of Edmond-Karp where we had to run a BFS for
       every iteration of augmenting path.
    => Why? Ahuja and Orlin improved the shortest augmenting path algorithm in 1987. They exploited the fact that the minimum distance in terms of edges from any node i to the sink node t is monotonically nondecreasing over all augmentations and reduced the average time per augmentation to O(n).
 */
 ll dinic(){
     if (src == snk){
         return 0 ;
     }
     ll ans = 0 ;
     while (true){
         bfs() ;
         if (parent[snk]==-1) break  ;
         memset(ptr,0,sizeof ptr) ;
         while (true){
             ll ret = sendflow(src,INF) ;
             if (ret == 0) break ;
             ans += ret ;
         }
     }
     return ans ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    scanf("%d%d",&n,&m) ;
    memset(residual,0,sizeof(residual)) ;
    src = 0 ; snk = n-1 ;
    int x , y ; ll w ;
    for(int i = 0 ; i < m ; i++){
        scanf("%d%d%lld",&x,&y,&w); x-- ; y-- ;
        if (residual[x][y]==0){
            if (x==y){
                graph[x].pb(y) ;
            }
            else{
                graph[x].pb(y) ;
                graph[y].pb(x) ;
            }

        }
        residual[x][y] += w ;
        residual[y][x] += w ;
    }
    ll ans = dinic()  ;
    cout << ans << el ;
 }
