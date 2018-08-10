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
    VI vf , vm , vc ;
    int f , m  , c ; int ma ;
    cin >> f >> m >> c  >> ma ;
    FORN(i,f,2*f+1){
        vf.pb(i) ;
    }
    FORN(i,m,2*m+1){
        vm.pb(i) ;
    }
    FORN(i,c,2*c+1){
        vc.pb(i) ;
    }
    if (ma > vc[vc.size()-1] || 2*ma < vc[0]){
        cout << "-1" << el ;
        return 0 ;
    }
    for(int i = 0 ; i < vc.size() ; i++){
        int cs = vc[i] ;
        if (cs >= ma && cs<=2*ma){
            for(auto xx : vm){
                for(auto ff : vf){
                if (ma<=ff && 2*ma<ff && ma<=xx && 2*ma<xx && xx > cs && ff >xx){
                        cout << ff << el << xx << el << cs << el ;
                        return 0 ;
                    }

                }
            }
        }
    }
    cout << "-1" << el ;

 }
