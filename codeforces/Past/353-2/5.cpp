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

int cnt = 0 ;
void dijkstra(int src,vvi& adj, vb& vis,int dist[]){

    priority_queue<pair<int,int> > pq ;
    pq.push(mp(0,src)) ;
    dist[src] = 0 ;
    while (!pq.empty()){
        pair<int,int> p = pq.top() ;
        int parent = p.yy ;
        dist[parent] = min(dist[parent],p.xx) ;
//        if (vis[parent]){
//            pq.pop() ;
//            continue ;
//        }
        vis[parent] = true ;
        pq.pop() ;
        for(int i = 0 ; i < adj[parent].size() ; i++){
            //if (!vis[adj[parent][i]]){
                dist[adj[parent][i]] = min(dist[adj[parent][i]],1+dist[parent]) ;
                pq.push(mp(dist[adj[parent][i]],adj[parent][i])) ;
           // }
        }
    }
}

int main(){
    vi v ;
    int n ; sci(n) ;
    vvi adj(n,v) ;
    forn(i,n-1){
        int x ; sci(x) ;
        for(int j = i+1 ; j < x ; j++){
            adj[i].pb(j) ;
        }
    }
    forn(i,n-1){
        vb vis(n,false) ;
        int dist[n] ;
        forn(j,n){
            vis[j] = false ;
            dist[j] = INT_MAX ;
        }
        dijkstra(i,adj,vis,dist) ;
        for(int j = i+1 ; j < n ; j++){
            cnt += dist[j] ;
        }
    }
    cout << cnt << el ;
}