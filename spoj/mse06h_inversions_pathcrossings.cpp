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



struct node{
    int l , r ; 
}; 

bool comp(node a , node b){
    if (a.l != b.l){
        return (a.l < b.l) ; 
    }
    return (a.r < b.r) ; 
}

node A[1000009] ; 
int B[1000009] ; 
ll BIT[1003] ; 
int sz ; 
ll ans = 0 ;

void update(int idx , ll val){
    while (idx <= sz){
        BIT[idx] += val ; 
        idx += (idx&-idx) ; 
    }
}
ll query(int idx){
    ll sum = 0 ; 
    while (idx){
        sum += BIT[idx] ; 
        idx -= (idx&-idx) ; 
    }
    return sum ; 
}


int main(){
    int t ;sci(t) ; int T = 1 ;  
    while (t--){
        ans = 0 ; 
        
        int n , m , k ; 
        memset(BIT,0,(1023)*sizeof(ll));
        sci(n) ; sci(m) ; sci(k) ; int a , b  ; 
        forn(i,k){
            sci(a) ; sci(b) ; 
            A[i].l = a ; A[i].r = b ; 
        }
        sort(A,A+k,comp) ; 
        
        sz = m ; 
        for(int i = k-1 ; i >= 0 ; i--){
            ans += query(A[i].r-1) ; 
            update(A[i].r,1) ; 
        }
        cout << "Test case " << T << ": " << ans << el ;
        T++ ;  
        
    }
    return 0 ; 
}