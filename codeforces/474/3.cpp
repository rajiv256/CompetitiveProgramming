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

 ll po(ll a , ll x){
     if (x == 0) return 1 ;
     ll tmp = po(a,x/2) ;
     tmp = tmp*tmp ;
     if (x&1) return a*tmp ;
     return tmp ;
 }
 ll X , d ;
 vector<ll> solve(ll rem, ll add){

     vector<ll> v ;
     if (rem == 0){
         return v;
     }
     if (rem == 1){
         v.pb(add) ;
         return v ;
     }
     int e = (ll)log2(rem+1) ;
     for(int i = 0 ; i < e ; i++){
         v.pb(add) ;
     }
     ll rem1 = rem-po(2,e)+1 ;
     vector<ll> vv = solve(rem1, add+d+2) ;
     v.insert(v.end(),all(vv)) ;
     return v ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> X >> d ; int x = 1 ;

    vector<ll> v = solve(X,x+d+3) ;
    cout << v.size() << el ;
    for(auto it : v){
        cout << it << sp ;
    }
    cout << el ;
    return 0 ;
 }
