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

char* a[30003] ; 
char* b[30003] ; 
ll c[30003] ; 
ll BIT[30003] ; 
int n , t ; 
ll ans = 0 ; 

ll query(int idx){
    ll sum = 0 ; 
    while (idx > 0){
        sum += BIT[idx] ; 
        idx -= (idx&-idx) ;
    }
    return sum ; 
}
void update(int idx , int val){
    while (idx <= n){
        BIT[idx] += val ; 
        idx += (idx&-idx) ; 
    }
}


int main(){
    sci(t) ;
    forn(i,30003){
        a[i] = (char*)malloc(25) ; 
        b[i] = (char*)malloc(25) ; 
    } 
    while (t--){
        cin >> n ; 
        
        forn(i,n){
            c[i] = 0 ; 
            BIT[i] = 0 ; 
        }
        forn(i,n){
            scanf("%s",a[i]) ; 
        }
        forn(i,n){
            scanf("%s",b[i]) ; 
        }
        map<string,int> m ; 
        forn(i,n){
            m[b[i]] = i ; 
        }
        forn(i,n){
            c[i] = m[a[i]]+1 ;  
        }
        ans = 0 ; 
        for(int i = n-1 ; i>= 0 ; i--){
            ans += query(c[i]-1) ; 
            update(c[i],1) ;  
        }
        cout << ans << el ; 
    }
    return 0 ; 
}