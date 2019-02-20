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

bool prime[10*MAXN] ;

void sieve(){
    memset(prime, true, sizeof prime) ;
    for(int i = 2 ; i < 10*MAXN ; i++){
        if (!prime[i]) continue ;
        for(int j = 2 ;i*j < 10*MAXN ; j++){
            prime[i*j] = false ;
        }
    }
}

pair<pair<ll,ll>, ll> sod(int n , int st, int k){
    ll ret = 0 ;
    ll cnt = 0 ;
    ll end = st + (n/k + 1)*k ;
    while (end > n+1){
        end -= k ;
    }
    if (end == n+1){
        ll stx = st ;  ll endx = end-k ;
        ll cnt = (endx-stx)/k +1 ;
        ret = (cnt*(stx + endx)) / 2 ;
        return mp(mp(cnt, ret), n+1) ;
    }
    cnt = (end-st)/k  +  1 ;
    ret = (cnt*(end+st))/2 ;
    return mp(mp(cnt, ret), end) ;


}
ll po(ll a, ll x, ll mod){
    if (x == 0) return 1 ;
    ll tmp = po(a, x/2, mod) ;
    tmp = (tmp*tmp) % mod ;
    if (x&1) return (a*tmp)%mod ;
    return tmp ;
}
bool isprime(ll n){
    if (n <= 2) return true ;
    if (n% 2 == 0 && n != 2){
        return false ;
    }
    if (po(2, n-1, n) == 1){
        return true ;
    }
    return false ;
}

int main(){

    ll n ; cin >> n ;



    set<ll> s ; s.insert(1) ;
    for(ll k = 1 ; k < n ; k++){
        if (!isprime(k) && n%k!=0) continue ;
        if (s.size() >= 100000) break ;
        ll end  = -1 ; ll st = 1 ;
        ll sumk = 0 ;
        while (end != n+1 ){
            pair<pair<ll,ll>, ll> p = sod(n , st, k) ;
            end = p.yy ;
            sumk += p.xx.yy ;
            st = (end + k) % n ;
        }
        //cout << k << sp << sumk << el ;
        s.insert(sumk) ;
    }
    for (auto it :s){
        cout << it << sp ;
    }
    return 0 ;


}
