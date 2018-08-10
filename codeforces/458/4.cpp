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

typedef struct node {
    ll g, m ;
}node;
ll gcd(ll a , ll b){
    if (b > a) return gcd(b,a) ;
    if (b == 0) return a ;
    return gcd(b,a%b) ;
}
node stree[12*MAXN] ;
ll a[5*MAXN] ;
int n, q ;
void build(int s, int lo , int hi, int idx){
    if (idx < lo || idx > hi){
        return ;
    }
    if (lo==hi && lo==idx){
        stree[s].m = stree[s].g = a[idx] ;
        return ;
    }
    int mid = (lo+hi)>>1 ;
    build(2*s+1,lo,mid,idx) ;
    build(2*s+2,mid+1,hi,idx) ;
    stree[s].m = min(stree[2*s+1].m, stree[2*s+2].m) ;
    stree[s].g = gcd(stree[2*s+1].g , stree[2*s+2].g) ;
    return ;
}
void update(int s, int lo , int hi, int idx , ll val){
    if (idx < lo || idx > hi){
        return ;
    }
    if (lo==hi && lo==idx){
        stree[s].m = stree[s].g = val ;
        return ;
    }
    int mid = (lo+hi)>>1 ;
    update(2*s+1,lo,mid,idx, val) ;
    update(2*s+2,mid+1,hi,idx,val) ;
    stree[s].m = min(stree[2*s+1].m, stree[2*s+2].m) ;
    stree[s].g = gcd(stree[2*s+1].g , stree[2*s+2].g) ;
    return ;
}
ll query(int s, int lo , int hi , int left, int right, ll x){
    if (hi < left || lo>right){
        return 0 ;
    }
    int mid = (lo+hi)>>1 ;
    if (lo >= left && hi <= right){
        if (stree[s].g % x == 0){
            return 0 ;
        }
        if (lo == hi){
            return 1 ; 
        }
        ll rem1 = stree[2*s+1].g % x ;
        ll rem2 = stree[2*s+2].g % x ;
        if (rem1 == 0 && rem2 != 0){
            return query(2*s+2,mid+1,hi,left,right,x) ;
        }
        if (rem1 != 0 && rem2 == 0){
            return query(2*s+1,lo,mid,left,right,x) ;
        }
        if (rem1 != 0 && rem2 != 0){
            return 2 ;
        }
        return 0 ;
    }

    ll ret1 = query(2*s+1,lo,mid,left,right,x) ;
    ll ret2 = query(2*s+2,mid+1,hi,left,right,x);
    return ret1+ret2 ;
}

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> n ;
    FORN(i,0,n){
        cin >> a[i] ;
    }
    FORN(i,0,n){
        build(0,0,n-1,i) ;
    }
    cin >> q ; int type ; ll  l , r , val, x ;
    while (q--){
        cin >> type ;
        if (type == 1){
            cin >> l >> r >> x  ;
            l-- ; r-- ;
            ll ans = query(0,0,n-1,l,r,x) ;
            //cout << ans << el;
            if (ans > 1){
                cout << "NO" << el ;
            }
            else cout << "YES" << el ;
        }
        else{
            int idx ;
            cin >> idx >> val ;
            idx-- ;
            a[idx] = val ;
            update(0,0,n-1,idx,val) ;
        }
    }


}
