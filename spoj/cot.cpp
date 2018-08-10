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
 #define MAXN 100050
 #define INF 10000000010
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 const int N = 111111 ;
 const int LN = 26 ;
 typedef struct node {
     int cnt ;
     struct node* left, *right ;
     node(){
        cnt = 0 ;
        left = NULL ;
        right = NULL ;
     }
 }node ;
 node* null ;
 int Anc[N][LN] ;
 int depth[N] ;
 node* root[N] ;
 int W[N] ;
 vector<int> adj[N] ;
 map<int,int> M , RM ;
 int n , m ;
 node* build(int lo, int hi){
     if (lo == hi){
         return new node() ;
     }
     int mid = (lo+hi)>>1 ;
     node* lc = build(lo,mid) ;
     node* rc = build(mid+1,hi);
     node* curr = new node() ;
     curr->left = lc ; curr->right = rc ;
     return curr ;
 }
 node* insert(int src, node* prev, int lo, int hi,int wt){
     //cout <<lo << sp << hi << sp << wt << sp<< prev << el ;
     if (lo == hi){
         node* curr = new node() ;
         curr->cnt = prev->cnt + 1 ;
         return curr ;
     }
     int mid = (lo+hi)>>1 ;
     node* lc ; node* rc ;
     if (wt <= mid){
         lc = insert(src,prev->left,lo,mid,wt) ;
         rc = prev->right ;
     }
     else{
         lc = prev->left ;
         rc = insert(src,prev->right,mid+1,hi,wt) ;
     }
     node* curr = new node() ;
     curr->cnt = lc->cnt + rc->cnt ;
     curr->left = lc ; curr->right = rc ;
     return curr ;
 }

 void dfs(int src, int par, int lev){
     Anc[src][0] = par ;
     depth[src] = lev ;

     root[src] = insert(src,(par==-1)?null:root[par],0,n-1,M[W[src]]) ;
     for(int i = 0 ; i < adj[src].size() ; i++){
         int it  = adj[src][i] ;
         if (it != par){
             dfs(it,src,lev+1) ;
         }
     }
 }
 void preprocess(){
     int ln = ceil(log2(n))+1 ;
     for(int j = 1 ; j < ln ; j++){
         for(int i = 0 ; i < n ; i++){
             if (Anc[i][j-1] != -1)
                Anc[i][j] = Anc[Anc[i][j-1]][j-1] ;
         }
     }
 }
 int lca(int x , int y){
     if (x == y) return x ;
     if (depth[x] < depth[y]) return lca(y,x) ;
     //cout << x << sp << y << el ;
     int diff = depth[x] - depth[y] ;
     int ln = ceil(log2(n))+1 ;
     for(int j = 0 ; j < ln ; j++){
         if ((diff&(1<<j)) == (1<<j)){
             x = Anc[x][j] ;
         }
     }
     //cout  << x << sp << y << el ;
     if (x == y) return x ;
     for(int j = ln ; j >= 0 ; j--){
         //cout << Anc[x][j] << sp << Anc[y][j] << el ;
         if (Anc[x][j]!=Anc[y][j]){
             x = Anc[x][j] ;
             y = Anc[y][j]   ;
         }

     }
     return Anc[x][0] ;
 }
 int query(node* a, node* b, node* c, node* d, int lo, int hi, int k){
     if (lo == hi) return lo ;

     int count = a->left->cnt + b->left->cnt - c->left->cnt - d->left->cnt ;
     int mid = (lo+hi)>>1 ;
     if (count >=k){
         return query(a->left,b->left,c->left,d->left,lo,mid,k) ;
     }
     return query(a->right,b->right,c->right,d->right,mid+1,hi,k-count) ;
 }
 #define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

 int main(){
 	// ios_base::sync_with_stdio(false) ;
 	// cin.tie(nullptr) ;
    scanint(n) ; scanint(m) ;
    int vv[n] ;
    FORN(i,0,n){
        scanint(W[i]) ;
        vv[i] = W[i] ;
    }
    sort(vv,vv+n) ;
    int cc = 0 ;
    for(int i = 0 ; i < n ; i++){
        M[vv[i]] = cc ;
        RM[cc] = vv[i] ;
        cc++  ;
    }
    int u , v , k ;
    FORN(i,0,n-1){
        scanint(u) ; scanint(v) ;  u-- ; v-- ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }
    null = build(0,n-1) ;
    memset(Anc,-1,sizeof Anc) ;
    dfs(0,-1,0) ;
    preprocess() ;
    while (m--){
        scanint(u) ; scanint(v) ; scanint(k) ;
        u-- ; v-- ;
        int anc = lca(u,v) ;
        int panc = Anc[anc][0] ;
        int ans = query(root[u],root[v],root[anc],(panc==-1)?null:root[panc],0,n-1,k) ;
        printf("%d\n",RM[ans] );
    }


 }
