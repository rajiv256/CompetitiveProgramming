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

 void dfs(int src, vb& vis, vvi& adj,int* ptr){
     vis[src] = true ; 
     //cout << src << sp ; 
     *ptr += 1 ; 
     forn(i,adj[src].size()){
         if (!vis[adj[src][i]]){
             dfs(adj[src][i],vis,adj,ptr) ; 
         }
     }
     return ; 
 }


int main(){
    int n ; sci(n) ; 
    vi v ; vvi adj(n,v) ; int x  , y , z ; char c ;  
    forn(i,n-1){
        cin >> x >> y ; 
        cin >> c ;  
       // cout << x << sp << y << sp ; cout << c << el ; 
        if (c == 'r')
            continue ; 
        x-- ; y-- ;  
        adj[x].pb(y) ; 
        adj[y].pb(x) ; 
    }
    
    ll ans = 0 ; 
    int count = 0 ; 
    vi cmps ; 
    vb vis(n,false) ; 
    for(int i = 0 ; i < n ; i++){
        if (vis[i] == true){
            continue ; 
        }
        int temp = count ; 
        dfs(i,vis,adj,&count) ; 
        i = 0 ; 
        //cout << el << count << el ; 
        cmps.pb(count-temp) ; 
    } 
    ll ans = 0 ; 
    int N =cmps.size()  ; 
    ll sum = 0 ; 
    forn(i,N){
        sum += cmps[i] ; 
    }
    ans = (sum*sum*sum)%MOD ; 
    forn(i,N){
        ans -= (cmps[i]*cmps[i]*cmps[i])%MOD ; 
        if (ans < 0){
            ans += MOD ; 
        }
    }
    forn(i,N){
        ans -= (3*cmps[i]*cmps[i]*(sum-cmps[i])) % MOD ; 
        if (ans < 0){
            ans += MOD ; 
        }
    }
    cout << ans%MOD << el ; 
}