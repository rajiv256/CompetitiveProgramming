/* Resilience is the greatest of all virtues */
 /* Code by rajiv */
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

 int ftime ;
 int leader[MAXN] ;
 int fin[MAXN] ;
 /* KOSARAJU's ALGORITHM

 The algorithm assumes that a DAG equivalent to the given graph exists. Each node
 in the DAG corresponds to a strongly connected component in the actual graph. From
 now on if we refer to a node in the DAG, we actually mean a strongly connected component in the actual graph.
 This correlation should be kept in mind to get a clarity on the algorithm.
 The proof why the following algorithm works can be found here : https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/tutorial/

 In simple words the proof goes like this,
 Result 1 :  First we prove that if each strongly connected component is considered
 as a node and if there is an edge between a vertex in one component to a vertex in another component then there is an edge between
 nodes corresponding to those vertices in the resulting graph. Then that resulting graph will be a DAG.

 Result2 : After this we prove that if there exists an edge from one SC component (C) to another SC component(C1) the finish time of
 atleast one node in C will be greater than the finish times of all nodes in (C1). --> Since finish times are calculated in Post order.
 Therefore if we want to get the strongly connected components, we should be careful enough to not pass through such kind of edges.

 So now we have C -> C1. How can we isolate them from each other.
 We consider a reverse graph of the actual graph. Now we will have C1 -> C. This means the finish time of atleast
 one vertex in C1 will be greater than the finish time of all vertices in C. So if we perform DFS with decreasing order
 of the finish times in the actual graph then we can observe that the SCC corresponding to C1 will come first and then followed by C.
 Therefore the authenticity of the SCCs will not be affected by that edge from C->C1.
----------------------------
ALGORITHM :
In the first DFS, we reverse the graph and calculate the finish times of the vertices/note the vertex covered at each finish time in Post order fashion.

In the second DFS we go through the vertices in the descending order of their finish times and perform DFS. This will be sure to cover all the
strongly connected component the starting vertex belongs to and it will be leader which can be a representative for the SCC.

*/

 void dfs(int src, VVI& adj, VB& vis, int head){
     vis[src] = true ;
     leader[src] = head ;
     for(int i = 0 ; i < adj[src].size() ; i++){
         int ch = adj[src][i] ;
         if (!vis[ch]){
             dfs(ch,adj,vis,head) ;
         }
     }
     fin[ftime++] = src ;
     return ;
 }

 int main(){
     ios_base::sync_with_stdio(false) ;
     cin.tie(0) ;

     int n , m ; cin >> n >> m ;
     int x , y ;
     VVI adj(n,VI()) ;
     VVI radj(n,VI()) ;
     for(int i = 0 ; i < m ; i++){
         cin >> x >> y ; x-- ; y-- ;
         adj[x].pb(y) ;
         radj[y].pb(x) ;
     }
     memset(fin,0,sizeof fin) ;
     memset(leader,0,sizeof leader) ;
     ftime = 0 ;
     VB vis(n,false) ;
     for(int i = 0 ; i < n ; i++){
         if (!vis[i]){
             dfs(i,radj,vis,-1) ;
         }
     }

     VB vis2(n,false) ;
     for(int i = n-1 ; i >= 0 ; i--){
         if (!vis2[fin[i]]){
             dfs(fin[i],adj,vis2,fin[i]) ;
         }
     }
     for(int i = 0 ; i < n ; i++){
         cout << leader[i]+1 << sp ;
     }
     cout << el ;
 }
