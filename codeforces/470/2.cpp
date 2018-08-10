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
 const int N = 1000010 ;
 bool prime[N] ;

 void sieve(){
     for(int i = 1 ; i < N ; i++) prime[i] = true ;
     for(int i = 2 ; i < N ; i++){
         if (prime[i]){
             for(int j = 2 ; i*j < N ; j++){
                 prime[i*j] = false ;
             }
         }
     }
 }
 VI div(int n){
     VI v ;
     for(int i = 2 ; i < sqrt(n) ; i++){
         if (n%i == 0){
             v.pb(n/i) ; v.pb(i) ;
         }
     }
     if (sqrt(n)==floor(sqrt(n))){
         int ff = floor(sqrt(n)) ;
         if (n%ff==0){
             v.pb(ff) ;
         }
     }
     sort(all(v)) ;
     return v ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    sieve() ; 
    int maxdiv = 2 ;
    int X2 ; cin >> X2 ;
    VI v = div(X2) ;
    for(auto it : v){
        if (prime[it]){
            maxdiv = max(maxdiv,it) ;
        }
    }
    int lbx1 = X2-maxdiv+1 ;
    int ubx1 = X2 ;
    int ans = X2 ;
    for(int p = 2 ; p < N ; p++){
        if (prime[p]){
            int quo = lbx1/p + ((lbx1%p==0)?0:1) ;
            int X1 = p*quo ;
            if (X1 > X2) continue ;
            int X0 = X1-p+1 ;
            if (X0 <= p) continue ;
            ans = min(X0,ans) ;
        }
    }
    cout << ans << el ;
 }
