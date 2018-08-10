/*
 		Resilience is the greatest of all virtues.
 		Code by rajiv
*/
/*
 Problem : http://codeforces.com/contest/342/problem/E
 Tags : Centroid Decomposition, LCA
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
 int n  , m ;
 const int N = 100050 ;
 const int LN = 18 ;
 int size[N] ;
  int  level[N] , Anc[N+2][LN+1]  ;
  VI adj[N] ;


 void dfs1(int src, int pa, int lev){
     level[src] = lev ;
     Anc[src][0] = pa ;
     for(auto it : adj[src]){
         if (it != pa){
             dfs1(it,src,lev+1) ;
         }
     }
 }
 void precompute(){
     dfs1(0,-1,0) ;
     for(int j = 1 ; j < LN  ; j++){
         for(int i = 0 ; i < N ; i++){
             if (Anc[i][j-1] != -1){
                 Anc[i][j] = Anc[Anc[i][j-1]][j-1] ;
             }
         }
     }
 }
 int lca(int x , int y){
     if (x == y) return x ;
     if (level[x] < level[y])
        swap(x,y) ;
     int diff = level[x] - level[y] ;
     for(int i = 0 ; i <= 20 ; i++){
         if ((diff>>i)&1){
             x = Anc[x][i] ;
         }
     }
     if (x == y) return x ;
     for(int j = LN ; j>=0 ; j--){
         if (Anc[x][j] != -1 && Anc[x][j] != Anc[y][j]){
             x = Anc[x][j] ;
             y = Anc[y][j] ;
         }
     }
     return Anc[x][0] ;
 }
 int dist(int x , int y){
     return level[x]+level[y]-2*level[lca(x,y)] ;
 }
bool marked[N] ;
int par[N] ;
void dfs2(int x , int pa){
    size[x] = 1 ;
    for(auto it : adj[x]){
        if (it != pa && !marked[it]){
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
 void decompose(int x, int pa){

    dfs2(x,pa) ;
    x = centroid(x,pa,size[x]/2) ;
    marked[x] = true ;
    //cout << x << sp << pa << el ;
    par[x] = pa ;
    for(auto it : adj[x]){
        if (!marked[it]){
            decompose(it,x) ;
        }
    }
 }
 int ans[N] ;
 void Paint(int x){
     int y = x ;
     while (y != -1){
         ans[y] = min(ans[y],dist(y,x)) ;
         y = par[y] ;
     }
 }


int Query(int x){
    int y = x ;
    int mn = ans[y] ;
    while (y != -1){
        mn = min(mn,ans[y]+dist(x,y)) ;
        y = par[y] ;
    }
    return mn ;
}

int main(){
    int  n , m , x , y ;
    memset(ans,63,sizeof ans) ;
    cin >> n >> m ;
    FORN(i,0,n-1){
        cin >> x >> y ; x-- ; y-- ;
        adj[x].pb(y) ;
        adj[y].pb(x) ;
    }
    Anc[0][0] = -1  ;
    precompute() ;
    decompose(0,-1) ;
    memset(marked,false,sizeof marked) ;
    int root = centroid(0,-1,n) ;
    par[root] = -1 ;
    for(int i = 0 ;i < n ; i++){
        ans[i] = dist(i,0) ;
    }

     while (m--){
        int type, u ;
        cin >> type >> u ; u-- ;

        if (type==1){
            Paint(u) ;
        }
        else{
            cout << Query(u) << el ;
        }
    }
    return 0 ;
}
