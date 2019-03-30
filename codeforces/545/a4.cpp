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
#define forn(i,x,y) for(int i=x;i<y;i++)
#define maxn 100005
#define inf 10000000010LL
#define mod 1000000007
#define last_set_bit(x) log2((x)&(-x))
#define add(x,y) (x)=((x)+(y))%MOD
#define PI 3.141592653589793

typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;


bool canadd(int x, vector<pair<int,int> >& check, vector<bool>& vis){
    bool ret = true ;
    for(auto it : check){
        if (x == it.yy){
            if(!vis[it.xx]){
                ret = false ;
            }
        }
    }
    return ret ;
}

int main(){
    int n ; cin >> n ;
    ll a[n][n] ;

    forn(i,0,n) forn(j,0,n) cin >> a[i][j] ;


    int m ; cin >> m ; int s, t ;
    vector<pair<int,int> > check ;
    forn(i,0,m){
        cin >> s >> t ; s-- ; t-- ;
        //a[t][s] = mod ;
        check.pb(mp(s,t)) ;
    }
    ll ans1 = 0 ;
    vector<bool> vis(n,false) ;
    int nvis = 1 ;
    int curr = 0 ;
    vis[0] = true ;

    while (nvis <= n){

        vector<pair<int,int> > v ;

        // cout << "curr : " << curr << el ;
        for(int i = 0 ; i < n ; i++){
            if ((i == curr) || vis[i] || !canadd(i,check,vis)) continue  ;
            v.pb(mp(a[curr][i], i)) ;
        }

        sort(all(v)) ;
        if (v.size() == 0) break ;
        curr = v[0].yy ;
        ans1  += v[0].xx ;
        vis[curr] = true ;
        nvis++ ;


    }
    cout << ans1 << el ;
    return 0 ;

}

























//}
