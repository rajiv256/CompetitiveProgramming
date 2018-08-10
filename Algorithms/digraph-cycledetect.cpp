/* Resilience is the greatest of all virtues
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
 #define MAXN 100005
 #define INF 10000000010
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 bool visited[MAXN] ;
 bool subtree_done[MAXN] ;

 bool dfs(int src, VVI& adj){
     visited[src] = true ;
     bool b = false ;
     cout << src << el ;
     for(int i = 0 ; i < adj[src].size() ; i++){
         int ch = adj[src][i] ;
         if (!visited[ch]){
            return dfs(ch,adj) ;
         }
         else if (!subtree_done[ch]){
             cout << "In rec stack So boom cycl" << ch << el ;
             return true ;
         }
     }
     subtree_done[src] = true ;
     return b ;
 }
 bool hasCycle(VVI& adj){
     memset(visited,false,sizeof(visited)) ;
     memset(subtree_done,false,sizeof subtree_done) ;
     bool b = false ;
     for(int i = 0 ; i < adj.size() ; i++){
         cout << "starting at " << i << el ;
         if (!subtree_done[i]){
             bool res = dfs(i,adj) ;

             b |= res ;
         }
     }
     return b ;
 }




 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int n , m ; cin >> n >> m;
    VVI adj(n,VI()) ;
    for(int i = 0; i < m ; i++){
        int x, y ; cin >> x >> y ; x-- ; y-- ;
        adj[x].pb(y) ;
    }
    if (hasCycle(adj)){
        cout << "Cycle Detected!" << el ;
    }
    else{
        cout << "Its a DAG. You've got SWAG." << el ;
    }

 }
