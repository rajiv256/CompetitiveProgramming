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

 const int N = 200050 ;
 int F[N] ;
 int Fi[N] ;
 vector<int> adj[N] ;
 void build_failure_fn(string pat){
     F[0] = 0 ; F[1] = 0 ;
     for(int i = 2 ; i < pat.size() ; i++){
        int j = i-1 ;
        while (j > 0){
            if (pat[i-1]== pat[F[j]]){
                F[i] = F[j]+1 ;
                break ;
            }
            else{
                j = F[j] ;
            }
        }
        if (j == 0){
            F[i] = 0 ;
        }
     }
 }





 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    CASET {
        int n , q ; cin >> n >> q ;
        string pat ; cin >> pat ; pat += '$'  ;
        memset(F,0,sizeof F) ;
        build_failure_fn(pat) ;
        memset(adj,0,sizeof adj) ;

        for(int i = 2 ; i <= n ; i++){
            int j = F[i] ;
            if (j == 0){
                Fi[i] = 0 ;
            }
            else{
                Fi[i] = Fi[j] + 1 ;
                adj[i] = adj[j] ;
                adj[i].pb(j) ; 
            }

        }
        // for(int i = 2 ; i <= n ; i++){
        //     sort(all(adj[i])) ;
        // }
        while (q--){
            int p , k ; cin >> p >> k ;
            int nk = Fi[p] - k ;
            if (nk == -1){
                cout << p << el ;
            }
            else if (nk < -1){
                cout << -1 << el ;
            }
            else{
                cout << adj[p][k-1] << el ;
            }


        }


    }
 }
