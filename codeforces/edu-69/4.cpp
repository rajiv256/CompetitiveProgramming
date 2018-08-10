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
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ;   typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 int deg[502] ;
 int in[502] ;
 bool vis[502] ;
 bool adj[502][502] ;
 bool radj[502][502] ;
 int n , m  ;
 void dfs(int s){
     vis[s] = true ;
     for(int i = 0 ; i < n ; i++){
         if (adj[s][i] && !vis[i]){
             if (--deg[i] <= 0) dfs(i) ;
         }
     }
 }

 int main(){
     ios_base::sync_with_stdio(false) ;
     cin.tie(0) ;
     cin >> n >> m ;
     int x , y ;
     memset(in,0,sizeof in) ;
     memset(deg,0, sizeof deg) ;

     while (m--){
         cin >> x >> y ; x-- ; y-- ;
         in[y]++ ;
         adj[x][y] = 1;
         radj[y][x] = 1 ;
     }
     for(int i = 0 ; i < n ; i++){
         for(int j = 0 ; j < n ; j++){
             deg[j] = in[j] ;
             vis[j] = false ;
         }
         deg[i]-- ;
         for(int j = 0 ; j < n ; j++){
             if (deg[j]<=0 && !vis[j]) dfs(j) ;
         }
         int GG = 0 ;
         for(int j = 0 ; j < n ; j++){
             if (!vis[j]) GG = 1 ;
         }
         if (!GG){
             cout << "YES" << el ;
             return 0 ;
         }
     }
     cout << "NO" << el ;
     return 0 ; 
 }
