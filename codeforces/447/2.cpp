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
 #define INF 1000000010
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;
 ll powmod(ll a , ll x){
     if (x == 0) return 1LL ;
     ll temp = powmod(a,x/2) ;
     temp = (temp*temp)%MOD ;
     if (x&1){
         return (a*temp)%MOD ;
     }
     return temp ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    ll n , m , k ;
    cin >> n >> m >> k ;
    if (n < m){
        swap(n,m) ;
    }
    ll ans = 0 ;
    if ((k == -1) && ((n+m)%2!=0)){
        cout << 0 << el ;
        return 0 ;
    }
    ll po = powmod(powmod(2,m-1),n-1) ;
    cout << po << el ;
    return 0 ;

 }
