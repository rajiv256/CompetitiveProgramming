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
#define MXN 100005
#define MOD 1000000007
#define ll long long

double a[MXN] ;

int abs(int a){
    if (a < 0)
        return -a ;
    return a ;
}

int main(){
    int n ; sci(n) ;
    forn(i,n){
        cin >> a[i] ;
    }
    vector<pair<double,int> > v ;
    forn(i,n){
        v.pb(mp(a[i],i)) ;
    }
    sort(all(v)) ;
    vector<double> vx ;
    forn(i,v.size()){
        vx.pb(v[i].xx) ;
    }


    return 0 ;

}