#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <climits>


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


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp " " 
#define el "\n"
#define lld long long int 
#define mp make_pair
#define pb push_back 
#define sci(x) scanf("%d",&x) 

int abs(int a){
    if (a < 0) 
        return -a ;
    return a ;  
}

void dfs(int a, vvi& adj , vector<bool>& visited,int wt[],int* weight){
    visited[a] = true ; 
    *weight += wt[a] ; 
    forn(i,adj[a].size()){
        if (!visited[adj[a][i]]){
            dfs(adj[a][i],adj,visited,wt,weight) ; 
        }
    }
    return ; 
}






int main(){
    int n ; sci(n) ; 
    int wt[n] ; int totWt = 0 ; 
    int dp[n] ; 
    forn(i,n){
        sci(wt[i]) ; 
        totWt += wt[i] ; 
    }
    vi v ; 
    vvi adj(n,v) ;
    pair<int,int> p = mp(0,0) ;  
    vp edges ;
    int a , b ; 
    forn(i,n-1){
        sci(a) ; sci(b) ; 
        a-- ; b-- ; 
        adj[a].pb(b) ; adj[b].pb(a) ;
        edges.pb(mp(a,b)) ;  
    }
    int res = INT_MAX  ;
    int duptotWt = totWt ;  
    // cout << duptotWt << el ; 
    
    
    cout << res << el ; 
    
    return 0 ; 
    
}