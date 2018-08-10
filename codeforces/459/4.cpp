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
 const int N = 120 ;
 vector<pair<char,int> > adj[N] ;
 int dp[N][N][2][207] ;
 char a[N][N] ;
 int n , m ;

 int dfs(int mad , int luc, int turn, int prev){
     if (dp[mad][luc][turn][prev] != -1){
         return dp[mad][luc][turn][prev] ;
     }
     if (turn == 0){

         for(auto it : adj[mad]){
             int x ;
             if (it.xx < prev){
                 x = 1 ;
             }
             else
                x = dp[it.yy][luc][1][it.xx] = dfs(it.yy,luc,1,it.xx) ;
             if (x == 0) return 0 ;
         }
         return 1 ;
     }
     if (turn == 1){
         for(auto it :  adj[luc]){
             int x ;
             if (it.xx < prev){
                 x = 0 ;
             }
             else{
                 x = dp[mad][it.yy][0][it.xx] = dfs(mad,it.yy,0,it.xx) ;
             }
             if (x == 1) return 1 ;
         }
         return 0 ;
     }
     return 0 ;
 }


 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    FORN(i,0,N){
        FORN(j,0,N){
            FORN(k,0,200){
                dp[i][j][0][k] = -1 ;
                dp[i][j][1][k] = -1 ;
            }
        }
    }
    cin >> n >> m ; int u , v ; char ch ;
    FORN(i,0,m){
        cin >> u >> v >> ch ;
        u-- ; v-- ;
        a[u][v] = ch ;
        adj[u].pb(mp(ch,v)) ;
    }

    FORN(i,0,N){
        sort(all(adj[i]),greater<pair<char,int> >()) ;
    }
    FORN(i,0,n){
        FORN(j,0,n){
            dp[i][j][0][0] = dfs(i,j,0,0) ;
        }
    }
    FORN(i,0,n){
        FORN(j,0,n){
            cout << (char)('A'+dp[i][j][0][0]) ;
        }
        cout << el ;
    }
 }
