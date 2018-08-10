#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<pair<int,int>,int > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mii ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> >
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >
#define pii pair<int,int>
#define INF 1000000000
#define sp " "
#define el "\n"
#define lld long long int
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define sci(x) scanf("%d",&x)
#define mp make_pair
#define ll long long
#define MXN 100003

pair<vi, vi > lca (int u , int v){
    vi v1 , v2 ;
    int d1 = log2(u) ; int d2 = log2(v) ;
    if (d1 >= d2){
        while (d1 != d2){
            v1.pb(u&1) ;
            u /= 2 ;
            d1 -= 1 ;
        }
        while (u != v){
            v1.pb(u&1) ;
            v2.pb(v&1) ;
            u /= 2 ; v /= 2 ;
        }
        //cout << u << el ;
        return mp(v1,v2) ;
    }
    else{
        pair<vi,vi > L = lca(v,u) ;
        return mp(L.yy,L.xx) ;
    }


}
bool check(int x , vi& lval, vi& rval, int n){
    int d = log2(x) ;
    int fd = log2(n) ;
    if ((d +lval.size() > fd) || (d +rval.size() > fd)){
            return false ;
    }
    if ((d +lval.size() < fd) && (d+rval.size()<fd)){
        return true ;
    }
    else{
        if (d +lval.size()==fd ){
            bool b = false;
            reverse(all(lval)) ;
            int xl = x ;
            forn(i,lval.size()){
                xl *= 2 ; xl += lval[i]&1 ;
            }
            if (xl > n)
                return false ;
        }
        if (d + rval.size() == fd){
            reverse(all(rval)) ;
            int xr = x ;
            forn(i,rval.size()){
                xr *= 2 ; xr += rval[i]&1 ;
            }
            if (xr > n){
                return false ;
            }
        }
        return true ;
    }
}

ll solve(int s , vi& lval, vi& rval ,int n){
    if (s > n){
        return 0 ;
    }
    if (check(s,lval,rval,n)){
        return (1+solve(2*s,lval,rval,n)+solve(2*s+1,lval,rval,n)) ;
    }
    else{
        return 0 ;
    }
}

int main(){
    int t ; sci(t) ;
    while (t--){
        int n , u , v ;
        cin >> n >> u >> v ;
        pair<vi,vi > L = lca(u,v) ;
        //reverse(all(L.xx)) ; reverse(all(L.yy)) ;
        ll ans = solve(1,L.xx,L.yy,n) ;
        cout << ans << el ;
    }
    return 0 ;
}