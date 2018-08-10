//rajiv's code
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
typedef vector<vector<pair<int,int> > > vvp ;

#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> > 
#define MOD 1000000007
#define MAXN 100005
#define sp " " 
#define el "\n"
#define ll long long int 
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x) 
#define mysqrt(n) (int)(sqrt(n))

int T[MAXN] ; // immediate parent 
int P[MAXN] ; // ancestor in the previous level 
int L[MAXN] ; // level of the node
int D[100005] ;

void dfs(int src, vvi& adj ,vb& vis, int level){
    vis[src] = true ; 
    L[src] = level ; 
    forn(i,adj[src].size()){
        if (!vis[adj[src][i]]){
            D[adj[src][i]] = D[src] + 1 ;  
            T[adj[src][i]] = src ; 
            dfs(adj[src][i],adj,vis,level+1) ; 
        }
    }
    return ; 
}

void DFS(int src, vvi& adj , vb& vis , int Nr){
    
    if (L[src] < Nr){
        P[src] = 1 ;
    }
    if (!(L[src]%Nr)){
        P[src] = T[src] ; 
    }
    else{
        P[src] = P[T[src]] ; 
    }
    vis[src] = true ;
    forn(i,adj[src].size()){
        if (!vis[adj[src][i]]){
            DFS(adj[src][i], adj , vis ,Nr);    
        }
    }
    return ; 
}

int LCA (int x , int y){
    //cout << x << sp << y << el ; 
     
    while (P[x] != P[y]){ 
        if (P[x] < P[y]){
            y = P[y] ; 
        }
        else{
            x = P[x] ; 
        }
    }
    
    while (x != y ){
        if (L[x] > L[y]){
            x = T[x] ; 
        }
        else{
            y = T[y] ; 
        }
    }
    return x ; 
} 
int main(){
    int kases ; sci(kases) ; 
    int kase = 1 ; 
    while (kases--){
        memset(T,0,sizeof(T)) ; 
        memset(L,0,sizeof(T)) ; 
        memset(D,0,sizeof(T)) ; 
        memset(P,0,sizeof(T)) ; 
        
        int N ; sci(N) ; 
        vi v ; 
        vvi adj(N+1,v) ; 
        for(int i = 1; i <= N ; i++){
            int n ; sci(n) ; int b ; 
            forn(j,n){
                sci(b) ; 
                adj[i].pb(b) ; 
            }
        }
        T[1] = 1 ; D[1] = 0 ; 
        int Nr = mysqrt(N) ;
        vb vis(N+1,false) ;  
        dfs(1,adj,vis,0) ;
        vb vis2(N+1,false) ; 
        DFS(1,adj,vis2,Nr) ;  
        
        int q ; sci(q) ; 
        int x , y ; 
        cout << "Case " << kase << ":" << el ;  
        while (q--){
            sci(x) ; sci(y) ; 
            //cout << "came" << el ;
            int lca = LCA(x,y) ; 
            cout << lca << el ; 
        }
        kase += 1 ;
        cout << el ; 
    }
}




