/*
        Code written by rajiv.
        God speed!
*/
#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define el endl
#define sp " "
#define forn(i,st,en) for(int i=st;i<en;i++)
#define sci(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define sclf(x) scanf("%lf",&x)
#define clr(x) memset(x,0,sizeof(x))
#define MXN 100005
#define INF 1000000000
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

typedef vector<int> vi ; typedef vector<char> vc ; typedef vector<pair<int,int> > vp ; typedef vector<vector<int> > vvi ;
typedef vector<vector<pair<int,int> > > vvp  ;typedef vector<pair<pair<int,int>,int > > vpp ;typedef vector<bool> vb ;
typedef set<int> si ;typedef map<int,int> mii ;typedef map<int,vector<int> > miv ; typedef unsigned long long ull ;
typedef pair<int,int> pii ;

ll solve(ll r, ll g){
    ll ans = 0 ;
    if (r >= 2*g){
        return g ;
    }
cout << r << sp << g << el ;
    ans += r/2 ;
    r -= 2*(r/2) ;
    g -= r/2 ;

    cout << ans << el ;
    if (r == 0){
        return ans ;
    }
    if (g >= 2 && r != 0){
        return ans+1 ;
    }
    return ans ;
}



int main(){
	cin.tie(0) ;
	ios_base::sync_with_stdio(false)  ;
    vector<ll> v(3,0)  ;
    cin >> v[0] >> v[1] >> v[2] ;
    sort(all(v)) ;
    ll r , g , b ;
    b = v[0] ; g = v[1] ; r = v[2] ;
    ll t1 = b ;
    ll r1 = r-b ;
    ll g1 = g-b ;
    t1 += solve(r1,g1) ;


    ////// End of t1


    ll t2 = 0 ;
    if (r >= 2*b){
        t2 = b ;
        ll r2 = max(r-2*b,g) ;
        ll g2 = min(r-2*b,g) ;
        t2 += solve(r2,g2) ;
    }


    ll ans = max(t1,t2) ;
    cout << ans << el ;




}
