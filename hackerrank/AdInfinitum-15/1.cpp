#include <bits/stdc++.h>

using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<vector<pair<int,int> > > vvp  ;
typedef vector<pair<int,pair<int,int> > > vpp ;
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
#define MXN 1000005
#define MOD 1000000007
#define ll long long

ll fact(int n){
    if (n == 0){
        return 1 ;
    }
    ll temp = fact(n-1) ;
    return (n*temp)%MOD ;
}

ll solve(int n , int k){
    ll x = fact(n-1) ;
    ll y = fact(k-1) ;
    ll z = fact(n-k) ;
    return (x/(y*z)) ;
}


int main(){
    int t ; sci(t) ;

    while (t--){
        int n , k ; sci(n) ; sci(k) ;
        ll ans = solve(n,k) ;
        cout << ans << el ;
    }
    return 0 ;
}