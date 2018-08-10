/* Resilience is the greatest of all virtues
 Code by rajiv

 Tags : LCA + Heavy Light Decomposition , QTREE , Hard
 Link : http://www.spoj.com/problems/QTREE/

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

 const int N = 10050 ;
 int chainNo = 0 ;
 int chainIndex[N] ;
 int chainHead[N] ;
 int parent[N] ;
 ll subtree[N] ;
 int depth[N] ;
 int Anc[N][30] ;
 int baseArr[N] ;      // Gives the weight of the edges as processed in DFS.
 int posInBase[N];     // Gives the position of each vertex in baseArr
 int otherEnd[N] ;     // The vertex that lies on the other end of edge starting from i-th vertex while DFS
 vector<int> indexx[N] ;

 typedef struct node {
     int left , right , val ;
 }node ;
 node stree[6*N] ;
 int ptr = 0 ;

 void build(int s, int low, int high){
     if (low > high) return ;
     if (low==high){
         assert(s>=0 && s<6*N && low>=0 && low < N) ;
         stree[s].val = baseArr[low] ;
         return ;
     }
     int mid = (low+high)>>1 ;
     build(2*s+1,low,mid) ;
     build(2*s+2,mid+1,high) ;
     stree[s].val = max(stree[2*s+1].val,stree[2*s+2].val) ;
 }
 void update(int s, int low, int high , int idx, int val){
     if (low > idx || high < idx || low > high){
         return ;
     }
     if (low == high && low == idx){
         stree[s].val = val ;
         return ;
     }
     int mid = (low+high)>>1 ;
     update(2*s+1,low,mid,idx,val) ;
     update(2*s+2,mid+1,high,idx,val) ;
     stree[s].val = max(stree[2*s+1].val,stree[2*s+2].val) ;
 }
 ll query(int s, int low, int high, int left, int right){
     if (low > right || high < left){
         return 0LL ;
     }
     if (low >=left && high<=right){
         return (ll)stree[s].val ;
     }
     int mid = (low+high)>>1 ;
     ll q1 = query(2*s+1,low,mid,left,right) ;
     ll q2 = query(2*s+2,mid+1,high,left,right) ;
     return max(q1,q2) ;
 }
/*
Keep track of the size of the subtree as it will be used in HLD.
Also keep track of the vertex at which each edge ends.
*/
 void dfs(int src , vector<VPII >& adj, VB& vis, int depp){
     vis[src] = true ;
     subtree[src] = 1 ;
     depth[src] = depp ;
     for(int i = 0 ; i < adj[src].size() ; i++){
         PII ch = adj[src][i] ;
         if (vis[ch.xx]) continue ;
         parent[ch.xx] = src ;
         otherEnd[indexx[src][i]] = ch.xx ;
         dfs(ch.xx,adj,vis,depp+1) ;
         subtree[src] += subtree[ch.xx] ;
     }
     return ;
 }

 bool cmp(const PII& p1, const PII& p2){
     return (subtree[p1.xx] > subtree[p2.xx]) ;
 }
/*
Divides the TREE into several contiguous chains.
-> chainIndex tells the serial number of the chain the vertex is in.
-> chainHead tells the representative of the specific chain in which vertex is in.
-> baseArr holds the edge costs in the order in which they are processed in dfs,
   Also each chain in this baseArr functions as a base array for segment tree.
-> posInBase stores where each vertex appears in the baseArr. It should be noted that vertices
   in the same chain will occur contiguously in the baserr.
-> And each vertex position holds the cost of edge that ends at that vertex while DFS.
-> Since the vertices in a single chain occur continuously in the baseArr we can use a segment tree
   to calculate the maximum edge in a particular chain.
*/
 void HLD(int src, vector<VPII >&  adj, VB& vis,int cost, int head){
     vis[src] = true ;
     chainIndex[src] = chainNo ;
     chainHead[src] = head ;
     baseArr[ptr] = cost ;
     posInBase[src] = ptr++ ;
     int st = 0 ;
     while (st < adj[src].size() && vis[adj[src][st].xx]) st++ ;
     if (adj[src].size()>st){
         HLD(adj[src][st].xx,adj,vis,adj[src][st].yy,head) ;
     }
     for(int i = st+1 ; i < adj[src].size() ; i++){
         if (vis[adj[src][i].xx]) continue ;
         chainNo++ ;
         HLD(adj[src][i].xx,adj,vis,adj[src][i].yy,adj[src][i].xx);
    }
    return ;
 }
 void preprocess(int n){

     for(int i = 0 ; i < n ; i++){
         Anc[i][0] = parent[i] ;
     }
     for(int j = 1 ; 1<<j <= n ; j++){
         for(int i = 0 ; i < n ; i++){
             Anc[i][j] = Anc[Anc[i][j-1]][j-1] ;
         }
     }
 }

 int LCA(int x, int y, int n){
     if (x == y) return x ;
     if (depth[y] > depth[x]){
         swap(x,y) ;
     }

     int logn = ceil(log2(n)) ;
     for(int i = logn ; i >= 0 ; i--){
         if (depth[y]+(1<<i) <= depth[x]){

             x = Anc[x][i] ;
         }
     }
     if (x == y)
        return x ;
     for(int i = logn ; i >= 0 ; i--){

         if (Anc[x][i] != Anc[y][i]){
             x = Anc[x][i] ;
             y = Anc[y][i] ;
         }
     }
     return parent[x] ;
 }

 ll query_up(int u , int v, int n){
     if (u == v) return 0 ;
     int uchain , vchain = chainIndex[v] ;
     ll ans = -1 ;
     while (1){
         uchain = chainIndex[u] ;
         if (uchain == vchain){
             if (u == v) break ;
             ll q = query(0,0,ptr,posInBase[v]+1,posInBase[u]) ;
             ans = max(q,ans) ;
             break ;
         }
         else{
             int uhead = chainHead[u] ;
             ll q = query(0,0,ptr,posInBase[uhead],posInBase[u]) ;
             ans = max(ans,q) ;
             u = parent[uhead] ;
         }
     }
     return ans ;

 }
/*
The otherEnd[edgeNum] gets the vertex at the outgoing end of the i-th edge.
*/
 void change(int i , int it, int n){
     int u  = otherEnd[i] ;
     update(0,0,ptr,posInBase[u],it) ;
 }
 ll query_t(int a, int b, int n){

     int lca = LCA(a,b,n) ;
     ll v1 = query_up(a,lca,n) ;
     ll v2 = query_up(b,lca,n) ;
     return max(v1,v2) ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    CASET {
        int n ; cin >> n ;
        vector<VPII > adj(n,VPII()) ;
        int x , y , w ;
        clr(chainIndex) ; clr(chainHead) ; clr(otherEnd) ; clr(parent) ; clr(depth) ; clr(subtree) ; clr(Anc) ;
        clr(baseArr) ; clr(posInBase) ;
        chainNo = 0 ; ptr =0 ;
        for(int i = 0 ; i < N ; i++){
            indexx[i].clear() ;
        }
        FORN(i,0,n-1){
            cin >> x >> y >> w ; x-- ; y-- ;
            adj[x].pb(mp(y,w)) ;
            adj[y].pb(mp(x,w)) ;
            indexx[x].pb(i) ;
            indexx[y].pb(i) ;
        }

        FORN(i,0,n){
            sort(all(adj[i]),cmp) ;
        }

        VB vis(n,false) ;
        parent[0] = -1 ;

        dfs(0,adj,vis,0) ;

        preprocess(n) ;

        VB vis2(n,false) ;
        HLD(0,adj,vis2,0,-1) ;

        build(0,0,ptr) ;

        while (1){
            string s ; cin >> s;
            if (s[0]=='D'){
                break ;
            }
            else if (s[0]=='C'){
                int I , it ; cin >> I >> it ; I-- ;
                change(I,it, n) ;
            }
            else{
                int a, b ; cin >> a >> b ; a-- ; b-- ;

                ll ans = query_t(a,b,n) ;
                cout << ans << el ;
            }
        }
        cout << el ;
    }
 }
