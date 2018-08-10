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

 const int N = MAXN ;
 const int K = 120 ;
 VI adj[N] ;
 int good[N] ;
 int ans[N][K] ;


 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int n , m , k , s ; cin >> n >> m >> k >> s ;
    for(int i = 0 ; i < n ; i++){
        cin >> good[i] ;
    }
    int x , y ;
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y ; x-- ; y-- ;
        adj[x].pb(y) ; adj[y].pb(x) ;
    }
    memset(ans,0,sizeof ans) ;

    for(int i = 0 ; i < k ; i++){
        queue<int> q ;
        for(int j = 0 ; j < n ; j++){
            if (good[j]==i+1){
                q.push(j) ;
                ans[j][i] = 1 ;
            }
        }
        int vis[n] ; memset(vis,false, sizeof vis) ;
        while (!q.empty()){
            int src = q.front() ;
            q.pop() ;
            vis[src] = true ;
            for(auto ch: adj[src]){
                if (!vis[ch]){
                    q.push(ch) ;
                    if (!ans[ch][i]){
                        ans[ch][i] = ans[src][i] + 1 ;
                    }
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        sort(ans[i],ans[i]+k) ;
        int sum = 0 ;
        for(int j = 0 ; j < s ; j++){
            sum += ans[i][j] ;
        }
        cout << sum -s << sp ;
    }
    return 0 ; 
 }
