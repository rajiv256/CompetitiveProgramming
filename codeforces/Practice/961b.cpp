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
    int n ; cin >> n ; int k ; cin >> k ;
    int a[2*n] ;
    int b[2*n] ;

    for(int i = 1 ;i <= n ; i++){
        cin >> b[i] ;
    }
    for(int i = n+1; i < 2*n ; i++){
        b[i] = 0 ;
    }
    for(int i = 1 ;i <= n ; i++){
        cin >> a[i] ;
    }
    for(int i = n+1; i < 2*n ; i++){
        a[i] = 1 ;
    }
    int pre[2*n] ;
    int preb[2*n] ;
    int awake[2*n] ;
    preb[0] = 0 ;
    pre[0] = 0 ;
    awake[0] = 0 ;
    for(int i = 1 ; i <= n ; i++){
        pre[i] = pre[i-1] + ((a[i]==0)?1:0) ;
        preb[i] = preb[i-1] + b[i] ;
        awake[i] = awake[i-1]+((a[i]==1)?1:0)*b[i]  ;
    }
    for(int i = n+1 ; i < 2*n ; i++){
        awake[i] = 0 ;
        preb[i] = 0 ;
    }
    int maxi = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if (a[i] == 0){
            int ub = lower_bound(pre,pre+n+1,pre[i]+k-1)-pre ;
            maxi = max(maxi, preb[ub]-preb[i-1]+awake[i-1] + ((n>=ub)?1:0)*(awake[n]-awake[ub]) ) ;
        }
        if (a[i] == 1){
            int ub = lower_bound(pre,pre+n+1,pre[i]+k)-pre ;
            maxi = max(maxi,preb[ub]-preb[i-1]+awake[i-1] + ((n>=ub)?1:0)*(awake[n]-awake[ub])) ;
        }
        cout << maxi << el ;
    }
    cout << maxi << el ;
    return 0 ;
 }
