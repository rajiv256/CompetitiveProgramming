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
    VI v ; int k1, k2 , k3 ; cin >> k1 >> k2 >> k3 ;
    v.pb(k1) ; v.pb(k2) ; v.pb(k3) ;
    sort(all(v)) ;
    int big = v[2] ; int med = v[1] ; int small = v[0] ;
    bool mark[100] ;
    int fl = 0 ;
    for(int bs = 0 ; bs < big ; bs++){
        for(int ms = 0 ; ms < med ; ms++){
            memset(mark,0,sizeof mark) ;
            int B = bs ; int C = ms ;
            while (B < 100){mark[B] = true ; B += big  ; }
            while (C < 100){mark[C] = true ; C += med ; }
            set<int> s ;
            for(int i = 0 ; i < 100 ; i++){
                if (!mark[i]){
                    s.insert(i%small) ;
                }
                if (s.size() > 1){
                    break ;
                }
            }
            if (s.size() == 1) fl = 1 ;
        }
    }
    if (fl){
        cout << "YES" << el ;
    }
    else{
        cout << "NO" << el ;
    }

 }
