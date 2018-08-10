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


int  n , mm ;
int a[3*MXN] ;


int main(){
    sci(n) ; sci(mm) ;
    forn(i,n){
        sci(a[i]) ;
    }
    int pos[n+1] ;
    forn(i,n){
        pos[a[i]] = i ;
    }
    int x , y ; vi v ;
    int res[n] ;
    forn(i,n){
        res[i] = n-1 ;
    }
    forn(i,mm){
        sci(x) ; sci(y) ;
        if (pos[x] < pos[y]){
            res[pos[x]] = min(res[pos[x]],pos[y]-1) ;
        }
        if (pos[x] > pos[y]){
            res[pos[y]] = min(res[pos[y]],pos[x]-1) ;
        }
    }
    int mini = res[n-1] ;
    for(int i = n-2 ; i >= 0 ; i--){
        if (res[i] <= mini){
            mini = res[i] ;
        }
        else{
            res[i] = mini ;
        }

    }
    ll ans = 0 ;
    forn(i,n){
        ans += res[i]-i+1 ;
    }
    cout << ans << el ;

    return 0 ;
}





