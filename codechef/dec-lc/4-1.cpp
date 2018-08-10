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

 const int N = 1000050 ;
 vector<int> arr[N] ;
 int prevXor[N] ;
 bool vis[N] ;



 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int n , q ; cin >> n >> q ;
    int a[n] ;
    int pre[n]  ;
    memset(pre,0,sizeof pre) ;
    cin >> a[0] ;
    pre[0] = a[0]  ;
    arr[pre[0]].pb(0) ;
    FORN(i,1,n){
        cin >> a[i] ;
        pre[i] = pre[i-1]^a[i] ;
        arr[pre[i]].pb(i);
    }
    memset(vis,false,sizeof vis) ;
    memset(prevXor,false,sizeof vis) ;
    set<pair<int,int> > updates ;
    while (q--){
        int type , idx, k , x ;
        cin >> type >> idx >> k ;
        idx-- ;

        if (type==1){
            int Xor = a[idx]^k ;
            a[idx] = k ;
            if (vis[idx] == true){
                set<pair<int,int> >::iterator itset = updates.lower_bound(mp(idx,0)) ;
                prevXor[idx] = itset->yy ;
                updates.erase(itset) ;
            }
            updates.insert(mp(idx,prevXor[idx]^Xor)) ;
            vis[idx] = true ;

        }
        if (type==2){
            int ans = 0 ;
            int Xor = 0 ;
            int begin = 0 ;
            set<pair<int,int> >::iterator it = updates.begin() ;
            VI::iterator up , lo ;

            while (it != updates.end()){
                int index = it->xx ;
                if (index > idx){
                    break ;
                }
                up = upper_bound(all(arr[k^Xor]),index-1) ;
                lo = lower_bound(all(arr[k^Xor]),begin) ;
                ans += max(0,(int)(up-lo)) ;
                begin = index ;
                Xor ^= it->yy ;
                it++ ;

            }

            up = upper_bound(all(arr[k^Xor]),idx) ;
            lo = lower_bound(all(arr[k^Xor]),begin) ;
            ans += max(0,(int)(up-lo)) ;

            cout << ans << el ;

        }
    }

 }
