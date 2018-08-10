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

 class TopXorerEasy {
public:
	int maximalRating(int A, int B, int C) {
        int a = A ; int b = B ; int c = C ;
        ll ret = 0 ;
        int fl = 0 ;
        for(int bit = 31 ; bit >= 0 ; bit--){
            int cnt = 0 ;
            if (fl) {
            	ret += 1<<bit ;
            	continue ;
            }
            cnt = ((a&(1<<bit))>>bit)+((b&(1<<bit))>>bit) + ((c&(1<<bit))>>bit) ;
            if (cnt > 1){
               fl = 1 ;

            }
            if (cnt >= 1) ret += 1<<bit ;
        }
        return (int)ret ;
	}
};


 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    TopXorerEasy  te = TopXorerEasy() ;
    int A = 9 ;
    int B = 8 ;
    int C = 8 ;
    for(int i = 31 ; i >= 0 ; i--){
        cout << ((A&(1<<i))>> i) << sp ;
    }
    cout << el ;
    cout << te.maximalRating(A,B,C) << el  ;

 }
