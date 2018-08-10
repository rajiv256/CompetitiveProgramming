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
#define MXN 100005
#define MOD 1000000007
#define ll long long

int adj[403][403] ;
int n , m ;
int dist[403] ;

void dijkstra(int fl , int src , vi& parent , vb& vis){
    priority_queue<pair<int,int>,vp,greater<pair<int,int> > > pq ;
    pq.push(mp(dist[src],src)) ;
    while (pq.size()!=0){
        pair<int,int> p = pq.top();
        src = p.yy ;

        if (vis[src] == true){
            pq.pop() ;
            continue ;
        }
        vis[src] = true ;
        pq.pop() ;

        for(int i = 0 ; i < n ; i++){
            if (adj[src][i] == fl){
                if (!vis[i]){
                    if (dist[i] > 1+dist[src]){
                        dist[i] = 1+dist[src] ;
                        pq.push(mp(dist[i],i)) ;
                        parent[i] = src ;
                    }
                }
            }
        }
        //cout << "here" << el ;
    }
}




int main(){
    sci(n) ; sci(m) ;
    int x , y ;
    memset(adj,0,sizeof(adj)) ;
    forn(i,m){
        sci(x) ; sci(y) ; x-- ; y-- ;
        adj[x][y] = 1 ;
        adj[y][x] = 1 ;
    }
    forn(i,n){
        dist[i] = 10000 ;
    }
    dist[0] = 0 ;

    vi parent(n,-1)  ;
    vb vis(n,false) ;

    dijkstra(1,0,parent,vis) ;
    int len = 0 ;
    int dst = n-1 ;
    while (dst != 0){
        len++ ; dst = parent[dst] ;
        if (dst == -1){
            len = -1 ;
            break  ;
        }
    }


    forn(i,n){
        vis[i] = false ;
        parent[i] = -1 ;
    }
    forn(i,n){
            dist[i] = 10000 ;
        }
        dist[0] = 0 ;


    dijkstra(0,0,parent,vis) ;
    int len2 = 0 ; dst = n-1 ;
      while (dst != 0){
        len2++ ; dst = parent[dst] ;

        if (dst == -1){
            len2 = -1 ;
            break  ;
        }
    }

    if ((len == -1) || (len2 == -1)){
        cout << "-1" << el ;
        return 0 ;
    }
    else{
        cout << max(len,len2) << el ;
    }
    return 0 ;
}