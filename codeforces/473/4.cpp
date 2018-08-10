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
 const int N = 2000050 ;
 bool prime[N] ;
 vector<int> pf[N] ;
 void sieve(){
     for(int i = 0 ; i < N ; i++){
         prime[i] = true ;
     }
     for(int i = 2 ; i < N ; i++){
         if (!prime[i]) continue ;
         pf[i].pb(i) ;
         for(int j = 2 ; i*j < N ; j++){
             prime[i*j] = false  ;
             pf[i*j].push_back(i) ;
         }
     }
 }

 int main(){
  	ios_base::sync_with_stdio(false) ;
  	cin.tie(nullptr) ;
     sieve() ;
     VI v ;
     int n ; cin >> n ;
     int a[n] ;
     for(int i = 0 ; i < n ; i++){
         cin >> a[i] ;
     }
     set<int> ps ;
     set<int> nums ;
     for(int i = 2 ; i <= N ; i++){
         nums.insert(i) ;
     }
     int ans[n] ; int fl = 0 ;

     for(int i = 0 ; i < n ; i++){

         if (fl == 1){
             ans[i] = *nums.begin() ;
         }
         else{
             ans[i] = *nums.lower_bound(a[i]) ;
             if (ans[i] > a[i]){
                 fl = 1;
             }
         }
         v = pf[ans[i]] ;
         for(auto it : v){
             int x = it ;
             if (ps.find(x) != ps.end())  continue ;
             while (it < N){
                 nums.erase(it) ;
                 it += x ;
             }

             ps.insert(x) ;
         }
     }
     for(int i = 0;i < n ; i++){
         cout << ans[i] << sp ;
     }
     cout << el  ;

  }
