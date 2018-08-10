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

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    vector<double> v ;
    int n ; double U ; cin >> n >> U ;
    for(int i = 0 ;i < n ; i++){
        double d ; cin >> d ;
        v.pb(d) ;
    }
    if (v.size() < 3) {cout << "-1" << el ; return 0 ; }
    sort(all(v)) ;
    bool b = false ;
    double eff = -1.0 ;
    for(int i =0 ; i < v.size()-1 ; i++){
        auto it = upper_bound(all(v),v[i]+U) ; it-- ;
        int diff = it-lower_bound(all(v),v[i]) ;
        if (diff >= 2){
            b = true ;
            eff = max(eff, (*it-v[i+1])/(*it-v[i])) ;
        }
    }
    if (b)
    cout << setprecision(9) << eff << el ;
    else{
        cout << "-1" << el ;
    }
    return 0 ;
 }
