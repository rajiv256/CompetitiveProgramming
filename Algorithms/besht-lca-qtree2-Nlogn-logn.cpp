/* Resilience is the greatest of all virtues */
 /* Code by rajiv */

 // Tags : Lowest common ancestor using Sparse tables and DP
 // Link : http://www.spoj.com/problems/QTREE2/
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
 #define INF (int)1E10+1
 #define MOD (int)1E9+7
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 int Par[MAXN] ; // Parent
 int Anc[MAXN][28] ; // Anc[i][j] the 2^j th parent of node 'i'
 ll cost[MAXN] ;
 int depth[MAXN] ;
 int N ;

 int dfs(int src, VVPII& adj, VB& vis, ll co, int depp){
     vis[src] = true ;
     cost[src] = co ;
     depth[src] = depp ;

     int maxl = 0  ;
     for(int i= 0 ; i < adj[src].size() ; i++){
         int child = adj[src][i].xx ;
         int wt =  adj[src][i].yy ;
         if (!vis[child]){
             Par[child] = src ;
             maxl = max(maxl,dfs(child,adj,vis,co+wt,depp+1)) ;
         }
     }
     return maxl ;
 }
// We preprocess the ancestors of nodes using DP as shown below.
// Anc[i][j] the 2^j th parent of node 'i'
 void preprocess(VVPII& adj){

     memset(Anc,-1,sizeof(Anc)) ;

     for(int i = 0 ; i < N ; i++){
         Anc[i][0] = Par[i] ;
     }

     for(int j = 1 ; 1<<j <= N ; j++){
        for(int i = 0 ; i < N ; i++){
            Anc[i][j] = Anc[Anc[i][j-1]][j-1] ;
        }
     }
 }
/*
 Intuitively, say we start from log2(N), then common ancestors from any node with this j = log2(N) will be the root.
 If the 2^j th ancestors of x and y are equal then it means that theit LCA exists in further lower levels.
 Some times the 2^j th ancestor may be the LCA but as we cannot easily decide with that we try to approach one level down the lca and
 simply return the parent of x.
*/
/*
 This is employed because from the LCA to top everything is a common ancestor. So we are finding for x and y the least ancestor which is not
 common for them and return its parent so that we get LCA.
*/
/*
 Before that we need to get both x and y on to the same level. From then, each ancestor of x and y will be on the same level.
*/
 int LCA(int x, int y){
     if (x == y) return x;

     if (depth[y] > depth[x]){
        swap(x,y) ;
     }

     int logn = ceil(log2(N)) ;

     for(int j = logn ; j >= 0 ; j--){
         if (Anc[x][j]!=-1 && depth[x]-(1<<j) >= depth[y]){
             x = Anc[x][j] ;
         }
     }
     if (x == y)
        return x ;

     logn = ceil(log2(N)) ;
     for(int j = logn ; j >= 0 ; j--){
         if (Anc[x][j]!=Anc[y][j]){
             x = Anc[x][j] ;
             y = Anc[y][j] ;
         }
     }
     return Par[x] ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int t ; cin >> t ;

    while (t--){
        cin >> N ;
        memset(depth,0,sizeof depth) ;
        memset(Par,0,sizeof Par) ;
        memset(cost,0,sizeof cost) ;
        VVPII adj(N,VPII()) ;
        int x , y, k , wt;
        for(int i = 0 ; i < N-1 ; i++){
            cin >> x >> y >> wt ;
            x-- ; y-- ;
            adj[x].pb(mp(y,wt)) ;
            adj[y].pb(mp(x,wt)) ;
        }
        VB vis(N,false) ;
        int maxL = dfs(0,adj,vis,0,0) ;
        Par[0] = -1 ;

        preprocess(adj) ;
        string s ;
        cin >> s;
        while (s != "DONE"){

            if (s == "DIST"){
                cin >> x >> y ; x-- ; y-- ;
                int lca = LCA(x,y) ;
                ll ans = cost[x]+cost[y]-2*cost[lca] ;
                cout << ans << el ;
            }
            else if (s == "KTH"){

                cin >> x >> y >> k ;
                x-- ; y-- ;
                int lca = LCA(x,y) ;
                int dx = depth[x]-depth[lca]+1 ;
                int dy = depth[y]-depth[lca]+1 ;
                if (x == lca){
                    k = dy-1-(k-dx)+1 ;
                    swap(x,y) ;
                }
                else if (k > dx){
                    k = (dy-1)-(k-dx)+1 ;
                    swap(x,y) ;
                }

                int ncov = 0 ; int logn = ceil(log2(N)) ;
                for(int i = logn ; i >= 0 ; i--){
                    if (ncov+(1<<i) <= k-1){
                        x = Anc[x][i] ;
                        ncov += 1<<i ;
                    }
                }
                cout << max(1,x+1) << el;
            }
            cin >> s ;
        }
        cout << el ;


    }

 }
