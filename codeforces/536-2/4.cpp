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
 int times[MAXN] ;

 bool cmp(int x , int y){
     return x < y;
 }
 int t = 0 ;
 bool mark[MAXN] ;
 void dfs(int src, VVI& adj, vector<int>& vis, set<int>& s){

     s.insert(src) ;
     while(s.size()!=0){
         src = *s.begin() ;
         vis[src] = true ;
         if (times[src] == -1) times[src] = ++t ;
         s.erase(s.begin()) ;
         for(auto ch: adj[src]){
             if (!vis[ch]){
                 s.insert(ch) ;
             }
         }
     }


 }
 int main(){
     int n, m ; cin >> n >> m ;
     vector<vector<int> > adj(n+1, vector<int>()) ;
     memset(times, -1, sizeof times) ;
     memset(mark, false, sizeof mark) ;
     for(int i = 1 ; i <= m ; i++){
         int x , y ;
         cin >> x >> y ;
         adj[x].pb(y)  ;
         adj[y].pb(x)  ;
     }

     for(int i = 1 ; i <= n ; i++){
         sort(all(adj[i]), cmp) ;
     }
     set<int> s  ;
     // for(int i = 1 ; i <= n ; i++){
     //     cout << i << ":"  ;
     //     for(auto ch  : adj[i]){
     //         cout << ch <<sp ;
     //     }
     //     cout << el ;
     // }
     vector<int> vis(n+1,0) ;
     dfs(1, adj, vis, s) ;
     VPII v ;
     for(int i = 1 ; i <= n ; i++){
         v.pb(mp(times[i], i)) ;
         //cout << i << sp << times[i] << el ;
     }
     sort(all(v)) ;
     for(auto it : v){
         cout << it.yy << sp ;
     }
     cout << el ;
     return 0 ;
 }
