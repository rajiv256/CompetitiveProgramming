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

int a[MXN] ;

int main(){
    int t ; sci(t) ;

    while (t--){
        int l , r ; sci(l) ; sci(r) ;
        int ans = 0 ;
        for(int i = 1 ; i <= r ; i+=2){
             ans += (r/i)*i ;
        }
        for(int i = 1 ; i < l ; i+=2){
            ans -= ((l-1)/i)*i ;
        }
        cout << ans << el ;

    }
    return 0 ;
}



