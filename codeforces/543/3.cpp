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

    int n , k ; cin >> n >> k ;
    k = min(n,k) ;
    int a[n] ;
    int curr[k] ;
    int kq[k] ;
    memset(kq,0,sizeof kq) ;
    memset(curr,0,sizeof curr) ;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    for(int i = 0 ; i < k ; i++){
        curr[i] = i ;
        kq[i]   = a[i] ;
    }
    int next = k ;
    int comp = 0 ;
    int ans  = 0 ;
    int ncomp = 0 ;
    for(int t = 1 ; t <= 200*n ; t++){

        for(int i = 0 ; i < k ; i++){
            if (kq[i] == 0) continue ;
            double testingnow = a[curr[i]] - kq[i] + 1 ;
            double qq         = floor(100.0 * (double)comp/n + 0.5)  ;
            if (testingnow == qq){
                ans++ ;
            }
            kq[i]-- ;
            if (kq[i] == 0){
                if (next >= n) continue ;
                ncomp++ ;
                kq[i] = a[next] ;
                curr[i] = next ;
                next++ ;
            }
        }
        comp += ncomp ;
        ncomp = 0 ;
    }
    cout << ans << el ;
    return 0 ;


}

















//}
