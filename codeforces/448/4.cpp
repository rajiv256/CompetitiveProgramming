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
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 const int N = 1000050 ;
 ll fact[N] ;
 ll ifact[N] ;
 char s1[N] , s2[N] ;
 int acnt[N] ;
 int sz ;

 ll po(ll a , ll x){
     if (x == 0) return 1LL ;
     ll temp = po(a,x/2) ;
     temp = (temp*temp)%MOD ;
     if (x&1) return (a*temp)%MOD ;
     return temp ;
 }

 ll invmod(ll val){
     return po(val,MOD-2) ;
 }

 void init(){
     fact[0] = 1 ; fact[1] = 1;
     FORN(i,2,N){
         fact[i] = (fact[i-1]*i)%MOD ;
     }
     ifact[N-1] = invmod(fact[N-1]);
     for(int i = N-2 ; i >= 0 ; i--){
         ifact[i] = (ifact[i+1]*(i+1))%MOD ;
     }
 }
 void add1(ll& ret, ll val){
     ret = (ret+val)%MOD ;
 }
 ll solve(char s[]){
     ll ret = 0 ;
     ll cur = 1;  cur = fact[sz] ;
     for(int i = 0 ; i < 26 ; i++){
         cur = (cur*ifact[acnt[i]])%MOD ;
     }

     for(int idx = 0 ; idx < sz ; idx++){
         for(int ch = 0 ; ch < s[idx]-'a' ; ch++){
             if (acnt[ch]){
                 ll val = cur*ifact[sz-idx] % MOD ;
                 val = val*fact[sz-idx-1] %MOD  ;
                 val = val*fact[acnt[ch]] %MOD ;
                 val = val*ifact[acnt[ch]-1] ;
                 add1(ret,val) ;
             }
         }

         if (acnt[s[idx]-'a']){
             cur = cur*acnt[s[idx]-'a']%MOD ;
             cur = cur*ifact[sz-idx] %MOD ;
             cur = cur*fact[sz-idx-1] % MOD ; 
             acnt[s[idx]-'a']-- ;
         }
         else break ;
     }

     return ret ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    init() ;
    gets(s1) ;
    gets(s2) ;
    sz = strlen(s1) ;
    clr(acnt) ;
    for(int i = 0 ; i < sz ; i++){
        acnt[s1[i]-'a']++ ;
    }


    ll ans = solve(s2) ;
    clr(acnt) ;
    sz = strlen(s1) ;
    for(int i = 0 ; i < sz ; i++){
        acnt[s1[i]-'a']++ ;
    }
    ans -= solve(s1) +1 ;
    ans += MOD ;
    ans %= MOD ;
    cout << ans << el ;
    return 0 ;

 }
