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

 bool check(int n){
     VI v ;
     while (n != 0){
         v.pb(n%10) ;
         n /= 10 ;
     }
     for(int i = 0 ; i < v.size()/2 ; i++){
         if (v[i] != v[v.size()-1-i]) return false ;
     }
     return true ;
 }
 ll rev(int n){
     VI v ;
     while (n!=0){
         v.pb(n%10) ;
         n /= 10  ;
     }
     ll ans = 0 ;
     for(int i = 0 ; i <v.size() ; i++){
         ans *= 10 ;
         ans += v[i] ;
     }
     return ans ;
 }
 int len(int n){
     int ret = 0 ;
     while(n!=0){
         n /= 10 ;
         ret++ ;
     }
     return ret ;
 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int k , p ;
    cin >> k >> p ;

    vector<ll> v ;
    for(int i = 1 ; i <= 9 ; i++){
        v.pb(i) ;
    }
    vector<ll> prev = vector<ll>(all(v));

    for(int l = 2 ; l <= 18 ; l++){
        vector<ll> curr ;
        for(int j = 0 ; j < prev.size() ; j++){
            for(int i = 0 ; i < 10 ; i++){
                curr.pb(prev[j]*10+i) ;
            }
        }
        sort(all(curr)) ;
        v.insert(v.end(),all(curr)) ;
        prev = curr ;
        if (v.size() >= 100004) break ;
    }
    ll sum = 0 ;
    for(int i = 0 ; i < k ; i++){
        sum += v[i]*pow(10,len(v[i]))+rev(v[i]) ;
        sum %= p ;
    }
    cout << sum << el ;
 }
