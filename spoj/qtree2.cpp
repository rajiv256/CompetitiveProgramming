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
//DFS to preprocess all the immediate parents & parents and the level of each node. 
void dfs(int src,vvp& adj, vb& vis,int level){
    vis[src] = true ; 
    L[src] = level ; 
    forn(i,adj[src].size()){
        if (!vis[adj[src][i].xx]){
            T[adj[src][i].xx] = src ; 
            //vis[adj[src][i].xx] = true ; 
            D[adj[src][i].xx] = D[src]+adj[src][i].yy ; 
            dfs(adj[src][i].xx,adj,vis,level+1) ; 
        }
    }
    return ; 
}

void DFS(int src, vvp& adj, vb& vis , int Nr){
    // if the level of node is less than Nr --> first level ... 
    // so parent is 1. (The First source)
    if (L[src] <  Nr){
        P[src] = 1 ; 
    }
    // Otherwise.. two cases follow...
    // 1) If the node is the topmost node in that section.
    else{
        // If the level%Nr is 0, then it is the beginning of a section.
        // So, its immediate parent is its parent. 
        if (!(L[src] %Nr)){
            P[src] = T[src] ; 
        }
        // Otherwise its parent is the parent of its immediate parent. 
        else {
            P[src] = P[T[src]] ; 
        }
    }
    // Similarly proceed in the dfs manner. 
    vis[src] = true ; 
    forn(i,adj[src].size()){
        if (!vis[adj[src][i].xx]){
            //vis[adj[src][i].xx] = true ; 
            DFS(adj[src][i].xx,adj,vis,Nr) ; 
        }
    }
    return ; 
}

int LCA(int child1, int child2){
    // Make child1 in lesser level than child2. 
    if (L[child1] > L[child2]){
        return LCA(child2,child1) ; 
    }
    // Bring both child1 & child2 to the same level 
    while (P[child1] != P[child2]){
        if (L[child1] > L[child2]){
            child1 = P[child1] ; 
        }
        else{
            child2 = P[child2] ; 
        }
    }
    // If both the children have same parent but at different level. 
    while (child1 != child2){
        if (L[child1] < L[child2]){
            child2 = T[child2] ; 
        }
        else {
            child1 = T[child1] ; 
        }
    }
    return child1 ; 
}




int main(){
    int kases ; sci(kases) ; 
    while (kases--){
        memset(T,0,sizeof(T)) ; 
        memset(P,0,sizeof(P)) ; 
        memset(L,0,sizeof(L)) ; 
        memset(D,0,sizeof(D)) ; 
        int N ; sci(N) ;  // No.of nodes 
        vp v ;
        vvp adj(N+1,v) ;
        int a , b , w ; 
        forn(i,N-1){
            sci(a) ; sci(b) ; sci(w) ; 
            adj[a].pb(mp(b,w)) ; 
            adj[b].pb(mp(a,w)) ; 
        } 
        
        int src = 1 ; vb vis(N+1,false) ; 
        int Nr = mysqrt(N) ;  
        D[1] = 0 ; 
        // Do dfs to store node distances from the root,
        // Level of a node, and Immediate parents
        dfs(src,adj,vis,0) ;
        vb vis2(N+1,false) ; 
        // Find the parent in the previous level.
        DFS(src,adj,vis2,Nr) ;
        string s ; 
        T[1] = 1 ; 
        cin >> s ;  int lca ; 
        
       
        while (s != "DONE"){
            
            int x , y , k ; 
            sci(x) ; sci(y) ;     
            lca = LCA(x,y) ;
            
            if (s == "DIST"){
                int dist = 0 ; 
                // Distance of 'a' node from root + Distance of 'b' node from root
                // minus twice the distance to the lca. 
                dist += D[x] + D[y] - 2*(D[lca]) ; 
                cout << dist << el ; 
                cin >> s ; 
                continue ; 
            }
            if (s == "KTH"){
                sci(k) ; 
                vi path ; int lenx = 1 ;
                while (x != lca){
                    path.pb(x) ; 
                    x = T[x] ; 
                    lenx++ ; 
                }
                path.pb(lca) ; 
                while (y != lca){
                    path.pb(y) ; y = T[y] ; 
                }
                                reverse(path.begin()+lenx,path.end()) ; 
                cout << path[k-1] << el ; 
               
            }
            cin >> s ; 
            
        }  
    }
    return 0 ; 
}
