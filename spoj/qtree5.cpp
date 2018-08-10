/*
 		Resilience is the greatest of all virtues.
 		Code by rajiv
 */
 /* Problem Statement

 You are given a tree (an acyclic undirected connected graph) with N nodes. The tree nodes are numbered from 1 to N. We define dist(a, b) as the number of edges on the path from node a to node b.

Each node has a color, white or black. All the nodes are black initially.

We will ask you to perfrom some instructions of the following form:

0 i : change the color of i-th node(from black to white, or from white to black).
1 v : ask for the minimum dist(u, v), node u must be white(u can be equal to v). Obviously, as long as node v is white, the result will always be 0.
Input
In the first line there is an integer N (N <= 100000)
In the next N-1 lines, the i-th line describes the i-th edge: a line with two integers a b denotes an edge between a and b.
In the next line, there is an integer Q denotes the number of instructions (Q <= 100000)
In the next Q lines, each line contains an instruction "0 i" or "1 v"
Output
For each "1 v" operation, print one integer representing its result. If there is no white node in the tree, you should write "-1".
*/
// Tags : Centroid Decomposition , easy-medium

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
 const int N = 100050 ;
 const int LN = 30 ;
 VI adj[N] ;
 int Anc[N][LN+2] ;
 int level[N] ;
 int n , Q ;
 void dfs1(int src, int pa, int lev){
     level[src] = lev ;
     Anc[src][0] = pa ;
     for(auto it :adj[src]){
         if (it != pa){
             dfs1(it,src,lev+1) ;
         }
     }
 }
 void precompute(){
     memset(Anc,-1,sizeof Anc) ;
     dfs1(0,-1,0) ;
     for(int j = 1 ; (1<<j) <= N ; j++){
         for(int i = 0 ; i < N ; i++){
             if (Anc[i][j-1] != -1){
                 Anc[i][j] = Anc[Anc[i][j-1]][j-1] ;
             }
         }
     }
 }
 int lca(int x , int y){
     if (x == y) return x;
     if (level[x] < level[y]) swap(x,y) ;
     int diff = level[x]-level[y] ;
     for(int j = 0 ; j < 30 ; j++){
         if ((diff>>j)&1){
             x = Anc[x][j] ;
         }
     }
     if (x == y) return x ;
     for(int j = LN ; j >= 0 ; j--){
         if (Anc[x][j] != -1 && Anc[x][j] != Anc[y][j]){
             x = Anc[x][j] ;
             y = Anc[y][j] ;
         }
     }
     return Anc[x][0] ;
 }
 int dist(int x, int y){
     return level[x]+level[y]-2*level[lca(x,y)] ;
 }
 int size[N] ;
 bool marked[N] ;
 void dfs2(int x ,int pa){
     size[x] = 1 ;
     for(auto it : adj[x]){
         if (!marked[it] && it != pa){
             dfs2(it,x) ;
             size[x] += size[it] ;
         }
     }
 }
 int centroid(int x , int pa, int blocksize){
     for(auto it : adj[x]){
         if (!marked[it] && it != pa && size[it]>blocksize){
             return centroid(it,x,blocksize) ;
         }
     }
     return x ;
 }
 int par[N] ;
 void decompose(int x, int pa){
     dfs2(x,pa) ;
     x = centroid(x,pa,size[x]/2) ;
     marked[x] = true ;
     par[x] = pa ;
     for(auto it : adj[x]){
         if (!marked[it] && it != pa){
             decompose(it,x) ;
         }
     }
 }
 multiset<int> ans[N] ;
 int color[N] ;
 void colorWhite(int u){
     int x = u ;
     while (x != -1){
         ans[x].insert(dist(x,u)) ;
         x = par[x] ;
     }
 }
 void colorBlack(int u){
     int x = u ;
     while (x != -1){
         auto it = ans[x].find(dist(x,u)) ;
         if (it != ans[x].end()){
             ans[x].erase(it) ;
         }
         x = par[x] ;
     }
 }
 int query(int u){
     int x = u ;
     int mn = *ans[u].begin() ;
     while (x != -1){
         mn = min(mn,*ans[x].begin()+dist(x,u)) ;
         x = par[x] ;
     }
     return mn ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> n  ; int x , y ;
    FORN(i,0,n-1){
        cin >> x >> y ;
        x-- ; y-- ;
        adj[x].pb(y);
        adj[y].pb(x) ;
    }
    precompute() ;
    memset(par,0,sizeof par) ;
    memset(marked,false,sizeof marked);
    decompose(0,-1) ;

    memset(color,0,sizeof color) ;
    int type ,  u ;
    cin >> Q ;
    for(int i = 0 ; i < n ; i++){
        ans[i].insert(1<<29) ;
    }
    int whites = 0 ;
    while (Q--){
        cin >> type >> u ; u-- ;
        if (type == 0){
            if (color[u]==1){
                color[u] = 0  ;
                colorBlack(u) ;
            }
            else{
                color[u] = 1  ;
                colorWhite(u) ;
            }
        }
        else{
            int val = query(u) ;
            if (val == 1<<29){
                cout << "-1" << el ;
            }
            else
                cout  << query(u) << el ;
        }
    }

 }
