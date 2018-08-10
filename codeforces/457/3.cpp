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
 bool prime[10*MAXN] ;
 vector<int> pp  ;
 int maxwt[MAXN] ;
 int n , m ;
 void sieve(){
     for(int i = 0 ; i < 10*MAXN ; i++){
         prime[i] = true ;
     }
     for(int i = 2 ; i < 10*MAXN ; i++){
         if (!prime[i]) continue ;
         pp.pb(i) ;
         for(int j = 2 ; i*j < 10*MAXN ; j++){
             prime[i*j] = false ;
         }
     }
 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    sieve() ;
    cin >> n >> m ;
    set<pair<int,int> > edges ;
    edges.insert(mp(1,n)) ;
    edges.insert(mp(n,1)) ;
    maxwt[1] = maxwt[n] = 2 ;
    for(int i = 2 ; i <= n-2 ; i++){
        edges.insert(mp(1,i)) ; edges.insert(mp(i,1)) ;
        maxwt[i] = 2 ;
    }
    int sum = 0 ; int val = 0 ;
    if (n > 2){
        sum = (n-2)*2 ;
        auto it = upper_bound(all(pp),sum+3) ;
        val = *it - (sum) ;
        maxwt[n-1] = val ;
        edges.insert(mp(1,n-1)) ;
        edges.insert(mp(n-1,1)) ;
        cout << 2 << sp << sum+val << el ;
        cout << 1 << sp << n << sp <<  2 << el ;
    }
    else{
        cout << 2 << sp << 2 << el ;
        cout << 1 << sp << 2 << sp << 2 << el ;
        return 0 ;
    }

    for(int i = 2 ; i <= n-2 ; i++){
        cout << 1 << sp << i << sp << 2 << el ;
    }
    cout << "1 " << n-1 << sp << val << el ;
    maxwt[1] = max(maxwt[1],val) ;

    for(int u = 2 ; u <= n ; u++){
        if (edges.size()==2*m) break ;
        for(int v = u+1 ; v <= n ; v++){
            if (edges.size()==2*m) break ;
            edges.insert(mp(u,v)) ;
            edges.insert(mp(v,u)) ;
        }
    }
    map<int,set<int> > m ;
    for (auto it : edges){
        int x = min(it.xx,it.yy) ;
        int y = max(it.xx,it.yy) ;
        m[x].insert(y) ;
    }
    for(int u = 2 ; u <= n ; u++){
        for(auto it : m[u]){
            cout << u << sp << it << sp << 1000000000LL << el ;
        }
    }
    return 0 ;



 }
