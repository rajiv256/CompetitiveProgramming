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

int main(){
    int n , m ; sci(n); sci(m) ;
    int a[n] ; int t[n] ; int r[n] ; int b[n] ;
    forn(i,n){
        sci(a[i]) ;
    }
    int ti , ri ;
    int s = 0 ;
    forn(i,m){
        sci(ti) ; sci(ri) ;
        while (s > 0 & ri >= r[s-1]){
            --s ;
        }
        t[s] = ti ; r[s]= ri ; ++s ;
    }
    int bl = 0 , br = r[0] ; r[s]= 0 ; ++s ;
    for(int i = 0 ; i < br ; i++){
        b[i] = a[i] ;
    }
    sort(b,b+br) ;
    for (int i = 1 ; i < s ; i++){
        for (int j = r[i-1] ; j > r[i] ; j--){
            a[j-1] = (t[i-1]==1)?b[--br]:b[bl++] ;
        }
    }
    forn(i,n){
        cout << a[i] << sp ;
    }
    return 0 ;



}