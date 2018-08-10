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
 #define MAXN 100005
 #define INF 10000000010
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 const int N = 300050 ;
 bool marked[N] , done[N] ;
 int n , m ;
 vector<int> adj[N]  ;
 char a[N] ;
 int ts[N] ;
 int cnt ;
 bool visited[N] ;
 bool over[N] ;
 vector<int> values[N] ;
 bool vis[N] ;
 void dfs(int src){
     vis[src] = true ;
     if (adj[src].size()==0){
         values[src][a[src]-'a'] = 1 ;
         over[src] = true ;
         return ;
     }
     for(auto it : adj[src]){
         if (!vis[it]){
             dfs(it) ;
         }
         for(int i = 0 ; i < 26 ; i++){
             values[src][i] = max(values[src][i],(i==(a[src]-'a'))+values[it][i]) ;
         }
     }
     over[src] = true ;
 }

 void endgame(){
     memset(over,false,sizeof over) ;
     memset(vis,false,sizeof vis) ;
     FORN(i,0,N){
         VI v(26,0) ;
         values[i] = v ;
     }
     for(int i = 0 ; i < n ; i++){
         int src = ts[i] ;
         if (!over[src]){
             dfs(src) ;
         }
     }
 }

void tsort(int src){
    visited[src] = true ;
    for(auto it : adj[src]){
        if (!visited[it]){
            tsort(it) ;
        }
    }
    ts[--cnt] = src ;
}


 void tsortHelper(){
     cnt = n ;
     memset(visited,false,sizeof visited) ;
     for(int i = 0 ; i < n ; i++){
         if (!visited[i]){
             tsort(i) ;
         }
     }
 }
 bool dfs1(int src){
     marked[src] =true ;
     bool b = false ;
     for(auto it : adj[src]){
         if (!marked[it]){
             b |= dfs1(it) ;
         }
         else if (!done[it]){
             return true ;
         }
     }
     done[src] = true ;
     return  b ;
 }

 bool hasCycle(){
     memset(done,false, sizeof done) ;
     memset(marked,false,sizeof marked);
     bool b = false ;
     for(int src = 0 ; src < n ; src++){
         if (!done[src]){
            b |= dfs1(src) ;
         }
     }
     return b ;
 }


int in[N] ;

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> n >> m ;
    FORN(i,0,n){
        cin >> a[i] ;
    }
    int x , y;
    memset(in,0,sizeof in) ;
    FORN(i,0,m){
        cin >> x >> y ; x-- ; y-- ;
        adj[x].pb(y) ;
        in[y]++ ;
    }
    if (hasCycle()){
        cout << "-1" << el ;
        return 0 ;
    }
    tsortHelper() ;
    endgame() ;
    int ans = 0 ;
    for(int i = 0 ; i < n  ; i++){
        for(int j = 0 ; j < 26 ; j++){
            ans = max(ans,values[i][j]) ;
        }
    }
    cout << ans << el ;
    return 0 ;
 }
