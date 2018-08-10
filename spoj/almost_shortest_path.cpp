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

int spath[502] ; 

void dijkstra(int src,vb& vis,vvp& adj){
    priority_queue <pair<int,int>, vp , greater<pair<int,int> > > pq ;  
    spath[src] = 0 ; 
    pq.push(mp(0,src)) ; 
    while (pq.size()!=0){
        pii p = pq.top() ;
        pq.pop() ;  
        int parent = p.yy ; 
        forn(i,adj[p.yy].size()){
            int child = adj[p.yy][i].yy ; 
            //if (!vis[child]){
                if (spath[child] > spath[parent]+adj[p.yy][i].xx && adj[parent][i].xx != INF){
                    spath[child] = spath[parent]+adj[p.yy][i].xx ; 
                    pq.push(mp(spath[child],child)) ; 
                }
            //}
        }
        //vis[parent] = true ; 
    }
    return ; 
}

void removePaths(int dest,int src ,vvp& iadj){
    if (dest == src){
        return ; 
    }
    forn(i,iadj[dest].size()){
        if (spath[iadj[dest][i].yy] == spath[dest]-iadj[dest][i].xx){
            iadj[dest][i].xx = INF ;  
            removePaths(iadj[dest][i].yy,src,iadj) ;  
        }
    }
    return ; 
}



int main(){
    int n , m ; 
    sci(n) ; sci(m) ; 
    while(n!=0 && m!= 0){
        
        forn(i,502){
            spath[i] = INF ; 
        }
        int src , dest ; sci(src) ; sci(dest) ; 
        vp list ; 
        vvp adj(n,list) ; 
        vvp iadj(n,list) ; 
        int x , y , p ; 
        forn(i,m){
            sci(x) ; sci(y) ; sci(p) ; 
            adj[x].pb(mp(p,y)) ; 
            iadj[y].pb(mp(p,x)) ; 
        }
        vb vis(n,false); 
        dijkstra(src,vis,adj) ;
         
        removePaths(dest,src,iadj) ; 
        forn(i,502){
            spath[i] = INF ; 
        }
        spath[dest] = 0 ; 
        vb visi(n,false) ; 
        dijkstra(dest,visi,iadj) ;
        if (spath[src] == INF){
            cout << "-1" << el ; 
        } 
        else{
            cout << spath[src] << el ;  
        }
        
        sci(n) ; sci(m) ; 
    }
    return 0 ;         
}

