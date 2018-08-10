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
 int n ;
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    CASET {
        cin >> n ;
        VI v(n,0) ;
        VPII temp(n,mp(0,0)) ;
        FORN(i,0,n){
            cin >> v[i] ;
        }
        sort(all(temp)) ;
        map<int,int> cnt ;
        FORN(i,0,n){
            cnt[v[i]]++ ;
        }
        vector<int> twos ;
        vector<int> ones ;
        for(map<int,int>::iterator it = cnt.begin() ; it != cnt.end() ; it++){
            if (it->yy == 2){
                twos.pb(it->xx) ;
            }
            if (it->yy == 1){
                ones.pb(it->xx) ;
            }
        }
        map<int,VI> m ;

        int fl = 1 ;
        if (twos.size()==1){
            int x = twos[0] ;
            ones.pb(x) ;
            ones.pb(x) ;
            fl = 2  ;
            twos.erase(twos.begin()) ;
        }
        for(int i = 0 ; i < twos.size(); i++){
            ones.pb(twos[i]); 
        }
        for(int i = 0 ; i < twos.size() ;i++){
            m[twos[i]].pb(twos[(i+1)%twos.size()]) ;
            //m[twos[i]].pb(twos[(i+1)%twos.size()]) ;
        }
        for(int i = 0 ; i < ones.size() ; i++){
            m[ones[i]].pb(ones[(i+fl)%ones.size()]) ;
        }
        int ans[n]  ; int ham = 0 ;
        for(int i = 0 ; i < n ; i++){
            ans[i] = m[v[i]][0] ;
            m[v[i]].erase(m[v[i]].begin()) ;
            if (ans[i] != v[i]) ++ham ;
        }
        cout << ham << el ;
        for(int i = 0 ; i < n ; i++){
            cout << ans[i] << sp ;
        }
        cout << el ;
    }

 }
