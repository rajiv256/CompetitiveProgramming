
#include <bits/stdc++.h> 

using namespace std ;

typedef vector<int> vi ; 
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ; 
typedef vector<pair<int,pair<int,int> > > vpp ; 
typedef vector<bool> vb ;
typedef set<int> si ; 
typedef map<int,int> mii ; 
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
#define MXN 1000003

ll a[111111] ; 
ll L[111111] ; 

ll solve(int maxi , map<int,ll>& cnt){
    if (maxi <= 0){
        return 0 ; 
    }
    if (L[maxi] != -1){
        return L[maxi] ; 
    }
    L[maxi-1] = solve(maxi-1,cnt) ; 
    L[maxi-2] = solve(maxi-2,cnt) ; 
    return max(L[maxi-1],L[maxi-2]+cnt[maxi]*maxi) ; 
}


int main(){
    int n ; sci(n) ; 
    memset(a,0,sizeof(a)) ; 
    memset(L,-1,sizeof(L)) ; 
    forn(i,n){
        cin >> a[i] ;  
    }
    L[0] = 0 ;
    
    map<int,ll> cnt ;
    ll maxi = -1 ; 
    forn(i,n){
        if (maxi < a[i]){
            maxi = a[i] ; 
        }
        cnt[a[i]]++ ; 
    } 
    ll ans = solve(maxi, cnt) ;
    cout << ans << el ;  
    return 0 ; 
    
}
