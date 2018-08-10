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



void dfs(int src , vb& vis,vvi& adj,int* ptr){
    vis[src] = true ;
    //cout << src << sp ;  
    *ptr += 1 ; 
    for(int i = 0 ; i < adj[src].size() ; i++){
        if (!vis[adj[src][i]]){
            dfs(adj[src][i],vis,adj,ptr) ; 
        }
    }
    return ; 
}



int main(){
    int n ; sci(n) ; 
    vi v ; 
    vvi adj(2*n+1,v) ;
    int x , y ;  
    int count = 0 ; 
    forn(i,n){
        sci(x) ; sci(y) ;
        x-- ; y-- ; 
        adj[x].pb(y) ; 
        adj[y].pb(x) ; 
    }
   
    vb vis(2*n+1,false) ; 
    int maxi = 1 ; int mini = INT_MAX ; 
    for (int i = 0 ; i < n ; i++){
        
        if (vis[i] == true){
            continue ; 
        }
        
        int temp = count ;
        dfs(i,vis,adj,&count) ; 
       
        if (count-temp ==1){
            continue ; 
        }
        maxi = max(maxi,count-temp) ;
        mini = min(mini,count-temp) ;  
    }
    cout << mini << sp << maxi << el ; 
    return 0 ; 
    
}