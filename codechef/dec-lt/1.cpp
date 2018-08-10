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
 ll solve(ll n){
     ll ret = 0 ;
     while (n!=0){
         ret += n%10 ;
         n /= 10 ;
     }
     if (ret < 10) return ret ;
     return solve(ret) ;
 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    vector<vector<ll> > v(10,vector<ll>()) ;


    int period[10] ;
    period[1] = 1;
    period[2] = 6 ;
    period[3] = 1 ;
    period[4] = 3 ;
    period[5] = 6 ;
    period[6] = 1 ;
    period[7] = 3 ;
    period[8] = 2 ;
    period[9] = 1 ;
    for(int i = 1 ; i <= 9 ; i++){
        ll val = i*i ;
        for(int j = 0 ; j < period[i] ; j++){
            v[i].pb(solve(val)) ;
            val *= i ;
        }
    }

    CASET {
        ll A , N ; cin >> A >> N ;
        int sum = solve(A) ;
        if (N == 1){
            cout << sum << el ;
        }
        else{
            cout << v[sum][(N-2)%period[sum]] << el ;
        }
    }


 }
