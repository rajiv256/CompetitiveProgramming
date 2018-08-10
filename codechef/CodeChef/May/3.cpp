#include <bits/stdc++.h>
using namespace std ;

typedef vector<int> vi ;
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ;
typedef vector<pair<int,pair<int,int> > > vpp ;
typedef vector<bool> vb ;
typedef set<int> si ;
typedef map<int,int> mi ;
typedef map<int,vector<int> > miv ;
typedef unsigned long long ull ;


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> >
#define pi pair<int,int>
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >
#define INF 1000000
#define LIM 1000000000
#define sp " "
#define el "\n"
#define ll long long
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x)
#define MXN 100003
#define gc getchar_unlocked

ll h[MXN] , r[MXN] ;

ll n , w , l ;
bool allgtl(){
    for (int i = 0 ; i < n ; i++){
        if (h[i] < l){
            return false ;
        }
    }
    return true ;
}
ll sum(){
    ll s = 0 ;
    for(int i = 0 ; i < n ; i++){
        if (h[i] >= l)
            s += h[i] ;
    }
    return s ;
}
void update(){
    for (int i = 0 ; i < n ; i++){
        h[i] += r[i] ;
    }
}
int main(){
    cin >> n >> w >> l  ;
    //ll ans = 0 ;
    for(int i =0 ; i < n ; i++){
        cin >> h[i] >> r[i] ;
    }
    ll tot = sum() ;
    if(tot >= w){
        cout << "0" << el;
        return 0 ;
    }
    ll mm = 0 ;
    for(int i = 0 ; i < n ; i++){
        if (h[i] < l){
            mm = max(mm, (l-h[i])/r[i] + 1) ;
        }
    }
    ll inc = 0 ;
    for(int i = 0 ; i < n ; i++){
        inc += r[i] ;
    }

    for(int i = 0 ; i < n ; i++){
        h[i] += r[i]*mm ;
    }
    tot = sum() ;
    if (tot == w){
        cout << mm << el ;
        return 0 ;
    }
    else if (tot < w){
        mm += (w-tot)/inc ;
        if ((w-tot)%inc != 0){
             mm += 1 ;
        }
        cout << mm << el;
        return 0 ;
    }
    else if (tot >w){
        ll k = sum() ;
        while (k >= w){
            mm-- ;
            for(int i = 0 ; i < n ; i++){
                h[i] -= r[i] ;
            }
            k = sum() ;
        }
        cout << mm+1 << el ;
        return 0 ;
    }

}