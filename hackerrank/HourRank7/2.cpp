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
#define ll long long

ll a[1<<15] ; 

ll sum(int l , int r){
    return a[r]-a[l-1]  ; 
}


int get(int l, int r, ll s) {
    int low, high, mid;
    low = l;
    high = r;
    while( low <= high ) {
        mid = ( low + high ) / 2;
        ll x = sum(l, mid);
        if( x == s && (mid == l || sum(l, mid-1) != s )) {
            return mid;
        } else if( x >= s ) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int solve(int l,int r){
    ll s = sum(l, r);
    if( l != r && s % 2 == 0 ) {
        int ind = get(l, r, s/2);
        if( ind != -1 ) {
            return max(solve(l, ind), solve(ind+1, r)) + 1;
        }
    }
    return 0;
}


int main(){
    int t ; sci(t) ; 
    while (t--){
        int n ; sci(n) ; 
        ll sum = 0 ; 
        memset(a,0,sizeof(a)) ; 
        for(int i = 1 ; i <= n ; i++){
            cin >> a[i] ; 
            a[i] += a[i-1] ; 
        }
        int cnt = solve(1,n); 
        cout << cnt << el ; 
    }
    return 0 ; 
}