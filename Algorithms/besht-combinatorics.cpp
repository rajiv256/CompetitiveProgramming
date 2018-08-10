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
 #define MOD (ll)1000000009
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;
 ll fact[524290] ;
 ll pow1(ll a , ll x){
     if (x == 0) return 1LL ;
     ll temp = pow1(a,x/2) ;
     return (x&1)?(((temp*temp)%MOD)*a)%MOD:(temp*temp)%MOD ;
 }
 /* MODULAR MULTIPLICATIVE INVERSE
 According to the fermat theorem if 'p' is a prime number then there for every 'a'
 a^(p-1) = 1 mod p
 ==> a*a^(p-2) = 1 mod p
 ==> Let x be the inverse of 'a' wrt p
 ==> ((x*a) mod p) * a^(p-2) = x mod p
 ==> x mod p = a^(p-2) mod p
 */

 ll inverse(ll a){
     if (a == 1) return 1LL ;
     return pow1(a,MOD-2) ;
 }
 ll nCr(ll n , ll k){
     if (n < k) return 0LL ;
     return (fact[n]*(inverse((fact[k]*fact[n-k])%MOD) )%MOD) ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    int K ; cin >> K ;

    ll N = pow1(2,K) ;
    ll tpkm1 = pow1(2,K-1) ;
    fact[0] = 1 ;
    for(ll i = 1 ; i < 524290 ; i++){
        fact[i] = (fact[i-1]*i)%MOD ;
    }
    //cout << N << el ;
    for(int cur = 1 ; cur <= N ; cur++){
        //cout <<cur-1 << sp << tpkm1-1 <<sp<< nCr(cur-1,tpkm1-1) << el ;
        ll ans = (2*((((nCr(cur-1,tpkm1-1)*fact[tpkm1])%MOD)*fact[N-tpkm1])%MOD))%MOD ;
        cout << ans << el ;
    }





 }
