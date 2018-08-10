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
 ll nck[1020][1020] ;
 ll bell[1020] ;
 ll g[1020] ;
 map<ll,int> m ;
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int M , N ; cin >> M >> N ;
    FORN(x,0,N){
        string s ; cin >> s ;
        for(int j = 0 ; j < M ; j++){
            g[j] = g[j]*2 + (s[j]-'0') ;
        }
    }
    for(int i = 0 ; i < M ; i++){
        m[g[i]]++ ;
    }
    memset(nck,0,sizeof nck) ;
    memset(bell,0,sizeof bell) ;
    bell[0] = 1 ;
    nck[0][0] = 1 ;
    for(int i= 1 ; i <= 1000 ; i++){
        nck[i][0] = 1 ;
        for(int j = 1 ; j <= 1000 ; j++){
            nck[i][j] = (nck[i-1][j] + nck[i-1][j-1]) % MOD ;
        }
        for(int j = 0 ; j < i ; j++){
            bell[i] += bell[j]*nck[i-1][j] ;
            bell[i] %= MOD ;
        }
    }
    ll ans = 1 ;
    for(auto p : m){
        ans = ans*bell[p.yy] % MOD ;
    }
    cout << ans << el ;
    return 0 ;
 }
