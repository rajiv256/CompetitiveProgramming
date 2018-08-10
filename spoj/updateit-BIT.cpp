//rajiv's code
// All tests passed.

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

int BIT[100003] ; 
int n , u ,q ; 


void update(int idx , int val){
    idx += 1 ; 
    while (idx <= n){
        BIT[idx] += val ; 
        idx += (idx&-idx) ; 
    }
}
int query(int idx ){
    idx += 1 ; 
    int sum = 0 ; 
    while(idx>0){
        sum += BIT[idx] ; 
        idx-= (idx&-idx) ; 
    }
    return sum ; 
}

int main(){
    int t ; sci(t) ; 
    while(t--){
        sci(n) ; sci(u) ; 
        memset(BIT,0,sizeof(BIT)) ;
        int l , r , v ; 
        forn(i,u){
            sci(l) ; sci(r) ; sci(v) ; 
            update(l,v) ; 
            update(r+1,-v) ; 
        }
        sci(q) ; int x ; 
        forn(i,q){
            sci(x) ; 
            int ans = query(x) ; 
            cout << ans << el ; 
        }
    }
}