/* Resilience is the greatest of all virtues */
 /* Code by rajiv */

 // Tags : Lowest common Ancestor
 // Link : http://www.spoj.com/problems/QTREE2/
 // Complexity : O(N*sqrt(N))

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

 int P[MAXN]  ;
 int Anc[MAXN] ;
 ll cost[MAXN] ;
 int depth[MAXN] ;
 int D ;
 // Make P[root] = 0
 int dfs1(int src, VVPII& adj, VB& vis, int len, int depp){
     vis[src] = true ;
     cost[src] = len ;
     depth[src] = depp;
     int ans = 1 ;
     for(int i = 0 ; i < adj[src].size() ; i++){
         int child = adj[src][i].xx ;
         int wt = adj[src][i].yy ;
         if (!vis[child]){
             P[child] = src ;
             ans = max(ans,dfs1(child,adj,vis,len+wt,depp+1)) ;
         }
     }
     return ans ;
 }
 // Assign Anc[root]
 void dfs2(int src, VVPII& adj, VB& vis, int depp, int dsqrt){
     vis[src] = true ;

     for(int i = 0 ; i < adj[src].size() ; i++){
         int child = adj[src][i].xx ;

         if (vis[child]) continue ;

         if (depp%dsqrt == 0){
             Anc[child] = Anc[src] ;
         }
         else{
             Anc[child] = Anc[P[child]] ;
         }
         dfs2(child,adj,vis,depp+1,dsqrt) ;
     }
     return ;
 }

 int LCA(int x, int y, int Nr){
     if (x == y){
         return x ;
     }
     if (Anc[x] != Anc[y]){
         if (depth[x] > depth[y]){
             x = Anc[x] ;
         }
         else{
             y = Anc[y] ;
         }
     }
     while (x != y){

         if (depth[x] > depth[y]){
             x = P[x] ;
         }
         else{
             y = P[y] ;
         }

     }
     return x ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int t ; cin >> t ;
    while (t--){
        int N ; cin >> N ;
        int x , y, w  ;
        memset(P,0,sizeof(P)) ;
        memset(Anc,0,sizeof(Anc)) ;
        memset(cost,0,sizeof(cost)) ;
        memset(depth,0,sizeof(depth)) ;
        VVPII adj(N,VPII()) ;
        for(int i = 0 ; i < N-1 ; i++){
            cin >> x >> y >> w ; x-- ; y-- ;
            adj[x].pb(mp(y,w)) ;
            adj[y].pb(mp(x,w)) ;
        }
        VB vis(N,false) ;
        P[0] = -1 ;
        Anc[0] = -1 ;
        D = dfs1(0,adj,vis,0,0) ;
        VB vis2(N,false) ;

        dfs2(0,adj,vis2,0,(int)sqrt(N)) ;

        string s ;
        cin >> s ;
        while (s != "DONE"){

             if (s == "DIST"){
                 cin >> x >> y ; x-- ; y-- ;
                 int lca = LCA(x,y,(int)sqrt(D)) ;

                 ll ans = cost[x]+cost[y]-2*cost[lca] ;
                 cout << ans << el ;
             }
             if (s == "KTH"){
                 int k ; cin >> x >> y >> k ; x-- ; y-- ;
                 int lca = LCA(x,y,(int)sqrt(D)) ;
                 int dx = depth[x]-depth[lca]+1 ;
                 int dy = depth[y]-depth[lca]+1 ;

                 if (lca == x){
                     k = dy-1 -(k-dx)+1 ;
                     swap(x,y) ;
                 }
                 else{
                     if (k > dx){
                         k = dy-1-(k-dx)+1 ;
                         swap(x,y) ;
                     }
                 }
                 while (x!=0 && k > depth[x]-depth[Anc[x]]){
                     k -= depth[x]-depth[Anc[x]] ;
                     x = Anc[x] ;
                 }
                 while (x != 0 && k > 1){
                     x = P[x] ;
                     k-- ;
                 }
                 cout << x+1 << el ;
                 // int dx = depth[x]-depth[lca]+1 ;
                 // int dy = depth[y]-depth[lca]+1 ;
                 // if (k <=dx){
                 //     while (x!=0 && k > depth[x]-depth[Anc[x]]) {
                 //         k -= depth[x]-depth[Anc[x]] ;
                 //         x = Anc[x] ;
                 //     }
                 //     while (x != 0 && k > 1){
                 //         k-- ;
                 //         x = P[x] ;
                 //     }
                 //     cout << x+1 << el ;
                 // }
                 // else{
                 //     k = dy-1-(k-dx)+1  ;
                 //     while (y!=0 && k > depth[y]-depth[Anc[y]]){
                 //         k -= depth[y]-depth[Anc[y]] ;
                 //         y = Anc[y] ;
                 //     }
                 //     while(y!=0 && k > 1){
                 //         k-- ;
                 //         y = P[y] ;
                 //     }
                 //     cout << y+1 << el ;
                 // }
             }
             cin >> s ;
        }
        cout << el ;
    }
 }
