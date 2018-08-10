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

 int sbits(int x){
     int ret = 0 ;
     for(int i = 0 ; i <= 30 ; i++){
        if ((x&(1<<i)) == (1<<i)) ret++ ;
     }
     return ret ;
 }
 ll nsteps[1004] ;
 ll fact[1004] ;
 ll ifact[1004] ;
 ll ncr[1004][1004] ;
 ll po(ll a, ll x){
     if (x == 0) return 1LL ;
     ll tmp = po(a,x/2) ;
     tmp = tmp*tmp % MOD ;
     if (x&1) return (a*tmp)%MOD ;
     return tmp ;
 }
 ll invmod(ll x){
     return po(x,MOD-2) ;
 }
 void init(){
     fact[0] = fact[1] = 1 ;
     ifact[1] = 1 ; ifact[0] = 1;
     for(ll i = 2 ; i <= 1002 ; i++){
         fact[i] = fact[i-1]*i % MOD ;
         ifact[i] = invmod(fact[i]) ;
         // cout << ifact[i] << sp ;
     }
     ncr[0][0] = 1;
     for(ll i = 1 ; i <= 1002 ; i++){
         // ncr[i][0] = 1 ;
         for(ll j = 0 ; j <= i ; j++){
             // ncr[i][j] = (ncr[i-1][j]+ncr[i-1][j])%MOD ;
             ncr[i][j] = (fact[i]*ifact[j] % MOD )*ifact[i-j] % MOD ;
         }
     }

 }
 ll solve(string s, int nones){

     if (s.size()==0){
         return (nones==0)?1:0 ;
     }
     if (nones == 0) return 1 ;
     if (s[0]=='0'){
         return solve(s.substr(1,s.size()),nones) ;
     }
     int sz = s.size()-1 ;
     ll pre = ncr[sz][nones] ;
     ll later = 0 ;
     if (s.size()==1){
         later = solve("",nones-1) ;
     }
     else
        later = solve(s.substr(1,s.size()),nones-1) ;
     return (pre+later)  % MOD ;
 }
 ll dp[1003][1003] ;
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    memset(ncr,0,sizeof ncr) ;
    memset(fact,0,sizeof fact) ;
    memset(dp,0,sizeof dp) ;
    init() ;
    string s ; cin >> s ;
    int k ; cin >> k ;
    nsteps[0] = nsteps[1] = 0 ;
    for(int i = 2 ; i <= 1001 ; i++){
        nsteps[i] = nsteps[sbits(i)]+1 ;
    }
    ll N = 0 ;
    for(int i = s.size()-1 ; i >= 0 ; i--){
        if (N > 1000){
            break ;
        }
        N *= 2 ;
        N += s[i]-'0' ;
    }
    int ps = 1000 - s.size() ;
    string pad = "" ;
    FORN(i,0,ps) pad += '0' ;
    string big = pad + s ;
    ll ans = 0 ;
    set<int> se ;
    set<int> se2  ;
    for(int i = 1 ; i <= 1000 ; i++){
        if (nsteps[i]+1 == k ){
            se.insert(i) ;
        }
        else if (nsteps[i] == k){
            se2.insert(i) ;
        }
    }
    for(auto it : se){
        ans += solve(s,it) ;
        ans %= MOD ;
    }
    set<int> se3 ;
    for(auto it : se2){
        if (se.find(sbits(it))==se.end()){
            se3.insert(it) ;
        }
    }
    for(auto it : se3){
        if (it <= min(N,1000LL) ){
            ans += 1 ;
        }
        ans %= MOD ;
    }
    if (k == 1){
        ans -= 1 ; ans += MOD ; ans %= MOD ;
    }
    cout << ans << el ;
    return 0 ;
 }
