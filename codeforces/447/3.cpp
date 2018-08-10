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
 #define INF (int)1E10+1
 #define MOD (int)1E9+7
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;
 int gcd(int a , int b){
     if (a < b) return gcd(b,a) ;
     if (b == 0) return a ;
     return gcd(b,a%b) ;
 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    int n ; cin >> n ;
    VI v ;
    for(int i = 0 ; i < n ; i++){
        int x ; cin >> x ;
        v.pb(x) ;
    }
    int gc = v[0] ;
    for(int i = 0 ; i < n ; i++){
        gc = gcd(gc,v[i]) ;
    }
    if (gc != v[0]){
        cout << -1 << el ;
        return 0 ;
    }
    VI ans ; ans.pb(v[0]) ;
    for(int i = 1 ; i < n ; i++){
        ans.pb(v[0]) ;
        ans.pb(v[i]) ;
    }
    cout << ans.size() << el ;
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << sp ;
    }
    cout << el ;

 }
