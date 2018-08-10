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
 int nc[1050] ;
 int n ;
 bool vis[1050] ;
 void dfs(int src, VVI& adj){
     vis[src] = true ;
     int cnt = 0 ;
     for(int i = 0 ; i < adj[src].size() ; i++){
         int ch = adj[src][i] ;
         if(!vis[ch]){
             cnt++ ;
             dfs(ch, adj) ;
         }
     }
     nc[src] = cnt ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> n ;
    VVI adj(n,VI()) ;
    for(int i = 0 ; i < n-1 ; i++){
        int x ; cin >> x ; x-- ;
        adj[x].pb(i+1) ;
    }
    memset(vis,false,sizeof vis) ;
    dfs(0,adj) ; bool b = true ;
    for(int i = 0 ; i < n ; i++){
        if (adj[i].size()<3 && adj[i].size()!=0){
            b = false ;
            break ;
        }
        int cnt = 0 ;
        for(auto it : adj[i]){
            if (nc[it]==0) cnt++ ;
        }
        if (cnt < 3 && adj[i].size()!=0){
            b = false ;
            break ;
        }
    }
    cout << ((b)?"Yes":"No") << el ;
    return 0 ;
 }
