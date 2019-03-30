/*
        Code written by rajiv.
        God speed!
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

#define ll long long
#define el "\n"
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define sclf(x) scanf("%lf",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MAXN 100005
#define INF 0x3f3f3f3f3f3f3f3fLL
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define set_bits(x) __builtin_popcount(x)
#define lsb(x) __builtin__ffs(x)-1
#define printV(container) copy(container.begin(), container.end(), ostream_iterator<vector<int> >(////cout, ' '));
#define printS(container) copy(container.begin(), container.end(), ostream_iterator<set<int> >(////cout, ' '));
#define gcd(a,b) __gcd(a,b)


typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ;
typedef pair<int,int> pii ;

typedef struct node {
    int low , high ;
    ll val ; ll d ; int idx ;
}node ;

node stree[3*MAXN] ;
bool lazy[3*MAXN] ;
ll S[MAXN], E[MAXN], D[MAXN], W[MAXN] ;
int n, m, k ;

void update(int s, int low, int high, int l, int r, int val, int d, int idx){
    if (low > r || high < l) return ;

    if (lazy[s]){
        stree[2*s+1].val = stree[2*s+2].val = stree[s].val ;
        stree[2*s+1].d   = stree[2*s+2].d   = stree[s].d   ;
        stree[2*s+1].idx = stree[2*s+2].idx = stree[s].idx ;
        lazy[2*s+1]      = lazy[2*s+2]      = true ;
        lazy[s] = false ;
    }
    if (high <= r && low >=l){

        if (stree[s].val  < val){
            stree[s].val  = val ;
            stree[s].d    = d   ;
            stree[s].idx  = idx ;
            lazy[s] = true ;
        }
        if (stree[s].val == val){
            if (stree[s].d <= d){
                stree[s].d = d ;
                stree[s].idx = idx ;
                lazy[s] = true ;    
            }

        }
        return ;
    }

    int mid = (low+high) >> 1 ;
    update(2*s+1, low, mid, l, r, val, d, idx) ;
    update(2*s+2, mid+1, high, l, r, val, d, idx);
}

node query(int s, int lo, int hi, int idx){
    if (lazy[s]){
        stree[2*s+1].val = stree[2*s+2].val = stree[s].val ;
        stree[2*s+1].d   = stree[2*s+2].d   = stree[s].d   ;
        stree[2*s+1].idx = stree[2*s+2].idx = stree[s].idx ;
        lazy[2*s+1]      = lazy[2*s+2]      = true ;
        lazy[s] = false ;
    }
    if (lo == hi && lo == idx){
        return stree[s]  ;
    }
    int mid = (lo+hi)>>1 ;
    if (idx <= mid){
        return query(2*s+1, lo, mid, idx) ;
    }
    else{
        return query(2*s+2, mid+1, hi, idx) ;
    }
}
ll L[MAXN][204] ;

ll dp(int idx, int m, vector<pair<ll,pair<ll,ll> > >& v){
    if (idx >= v.size()) return 0 ;
    if (m < 0) return 0 ;
    if (L[idx][m] != INF) return L[idx][m] ;

    ll ans = INF + 2 ;
    int jumpto = v[idx].yy.xx + 1 ;
    ll  wt = v[idx].xx ;

    if (v[idx].xx == 0){
        L[idx+1][m] = dp(idx+1, m, v) ;
        ans = min(ans, L[idx+1][m]) ;
    }
    else{

        L[jumpto][m] = dp(jumpto, m, v) ;
        ans   = min(ans, wt + L[jumpto][m]) ;

        if (m > 0){
            L[idx+1][m-1] = dp(idx+1, m-1, v) ;
            ans   = min(ans, L[idx+1][m-1]);
        }

    }

    return ans ;
}


int main(){
    cin >>n >> m >> k ;
    for(int i = k ; i <= n ; i++){
        S[i] = E[i] = D[i] = i ;
        W[i] = 0 ;
    }

    for(int i = 0 ; i < n ;i++){
        update(0, 0, n-1, i, i, 0, i, k+i) ;
    }

    for(int i = 0 ; i < k ; i++){
        cin >> S[i] >> E[i] >> D[i] >> W[i] ;
        S[i]-- ; E[i]-- ; D[i]-- ;
        update(0, 0, n-1, S[i], E[i], W[i], D[i], i) ;
    }



    vector<pair<ll,pair<ll,ll> > > v ;

    for(int i = 0 ; i < n ; i++){
        node nn = query(0, 0, n-1, i) ;
        v.pb(mp(nn.val, mp(nn.d, nn.idx))) ;
    }
    for(int i = 0 ; i < MAXN ; i++){
        for(int j = 0 ; j < 204 ; j++){
            L[i][j] = INF ;
        }
    }
    ll ans = dp(0, m , v) ;
    cout << ans << el ;

}
