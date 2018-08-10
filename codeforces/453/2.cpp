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
 int n ;
 int col[10005] ;
 bool vis[10005] ;
 bool inq[10005] ;

 void bfs(int s, VVI& adj, int c){
     queue<int> q ;
     q.push(s) ;
     clr(inq) ;
     inq[s] = true ;
     while (!q.empty()){
         int src = q.front() ;
         vis[src] = true ;

         q.pop() ;
         FORN(i,0,adj[src].size()){
             int ch = adj[src][i] ;
             if (col[ch] == c && !inq[ch]){
                 q.push(ch) ;
                 inq[ch] = true ;
             }
         }
     }
     return ;

 }



 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> n ;
    VVI adj(n,VI()) ;
    clr(col) ;
    int p[n+1] ;
    FORN(i,2,n+1){
        int x ; cin >> x ;
        p[i] = x ;
    }
    FORN(i,2,n+1){
        adj[i-1].pb(p[i]-1) ;
        adj[p[i]-1].pb(i-1) ; 
    }
    FORN(i,0,n){
        cin >> col[i] ;
    }
    int ans = 0 ;
    FORN(i,0,n){
        if (!vis[i]){
            clr(inq) ;
            bfs(i,adj,col[i]) ;
            ans++ ;
        }
    }
    cout << ans << el ;
 }
