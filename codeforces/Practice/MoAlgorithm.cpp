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
#define MXN 1000003
#define gc getchar_unlocked

int n , sq ; 


struct query{
    int idx ; 
    int l , r ; 

} ; 
bool comp(query a , query b){
    if (a.l/sq != b.l/sq){
        return (a.l/sq < b.l/sq) ; 
    }
    else{
        return (a.r < b.r) ; 
    }
}



ll a[200005] ; 
ll cnt[1000009] ; 
ll res[1000009] ; 
query q[200005] ; 

int currL = 0 ; 
int currR = 0 ; 
ll ans = 0 ; 
inline void add(int pos){
    ll x = cnt[a[pos]] ; 
    
    cnt[a[pos]]++ ; 
    ans += (2*x+1)*a[pos] ; 
     
}
inline void remove(int pos){
    ll x = cnt[a[pos]] ; 
    
    cnt[a[pos]]-- ; 
    ans -= (2*x-1)*a[pos]  ; 
}


int main(){
    int n ; sci(n) ; int d ; sci(d) ;  
    
    forn(i,n){
        cin >> a[i] ;  
    }
    int x, y; 
    forn(i,d){
        sci(x)  ; sci(y) ; x-- ; y-- ; 
        q[i].l = x ; q[i].r = y ; q[i].idx = i ; 
    }
    sq = sqrt(n) ; 
    sort(q,q+d,comp) ; 
    //memset(cnt,0,sizeof(cnt)) ; 
    forn(i,d){
       int l = q[i].l ; int r = q[i].r ; 
       while (currL < l){
           remove(currL) ; 
           currL++ ; 
       }
       while (currL > l){
           add(currL-1) ; 
           currL-- ; 
       }
       while (currR <= r){
           add(currR) ; 
           currR++  ; 
       }
       while (currR > r+1){
           remove(currR-1) ; 
           currR-- ; 
       }
       
       res[q[i].idx] = ans ; 
    }
    forn(i,d){
        cout << res[i] << el ; 
    }
    return 0  ;
}