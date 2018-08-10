/* ONLY THE SOFT TESTCASES WERE PASSED */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <cmath>
#include <bits/stdc++.h>
 
using namespace std;
 
 
typedef vector<int> vi ;
typedef vector<vector<pair<int,int> > > vvp ;
typedef map<int,int> mi ;
 
#define forn(i,n) for(int i = 0 ; i < n ; i++)
 
 
void makegraph(map<int,vector<int> >& adj , map<int,vector<pair<int,int> > >& offers , int d ){
    forn(i,offers[d].size()){
        adj[offers[d][i].first].push_back(offers[d][i].second)  ;
        adj[offers[d][i].second].push_back(offers[d][i].first)  ;
    }
 
    return ;
 
}
 
void dfs (int src, map<int,vector<int> >& adj ,map<int,int>& maxx ,vi& all,map<int,bool>& visited ,vi& v){
    //cout << "In dfs\n";
    visited[src] = true ;
    //cout << src <<endl ;
    
    all.push_back(src) ;
    //cout << src << " @@@@@ " << maxx[src] << endl ;
    v.push_back(maxx[src]) ; 
   
    for (int i = 0 ; i < adj[src].size() ; i++){
        if (visited[adj[src][i]] == 0)
            dfs(adj[src][i],adj,maxx,all,visited,v) ;
 
    }
    
    //cout << "DFS Ok!\n"<< endl ; 
    return ;
}
 
 
 
void updateMaxx(map<int,vector<int> > &adj , map<int,int>& maxx , int d){
 
    if (adj.size() == 0)
        return ;
    else{
        map<int,bool> visited ;
        for(map<int,vector<int> > :: iterator it = adj.begin() ; it != adj.end() ; it++){
 
            int src = (*it).first ;
            if (visited[src] == false){
                vector<int> all ;
                int maxxxi = -1 ; 
                vi v ; 
                dfs(src,adj,maxx,all,visited,v) ;
                sort(v.begin(),v.end()) ; 
                int maxi = v[v.size()-1] ; 
                forn(i,all.size()){
                    maxx[all[i]] = maxi ;
                }
            }
 
        }
        
 
    }
 
}
 
int main() {
    int t ; cin >> t ;
    
    while (t--){
        int n , m ; cin >> n >> m ;
        mi maxx ;
        vector<pair<int,int> > dayof ;
        map<int,vector<pair<int,int> > > offers ;
        map<int,int> cnt ;
 
        forn(i,n){
            int temp ;
            cin >> temp ; 
            cnt[temp]++ ;
            maxx[temp] = temp ;
        }
        int mdays = -1 ;
        //cout << "Input not ok!\n" ; 
        while (m--){
            int d , a , b ;
            cin >> d >> a >> b ;
            //cout << d << endl; 
            offers[d].push_back(make_pair(a,b)) ;
            //cout << d << " " << a <<" "<<  b << " Taken\n" ; 
            maxx[a] = a ; maxx[b] = b ; 
            if (mdays < d )
                mdays = d ;
        }
        //cout << "Input ok!\n" ; 
        vi v ; 
 
        forn(i,mdays+1){
            
            map<int,vector<int> > adj ;    
            //cout << "In for : "<< mdays-i << "\n" ; 
            
                makegraph(adj,offers,mdays-i) ;
            //cout << "Make a graph Ok!\n" ; 
             updateMaxx(adj,maxx,mdays-i) ;
            //cout << "Update OK!" << endl ;     
            
        }
        int result = 0 ;
        for(map<int,int> :: iterator it = cnt.begin() ; it != cnt.end() ; it++){
            result += (*it).second*(maxx[(*it).first]) ;
        }
        //cout << "result Ok!\n" ; 
        cout << result << "\n" ;
 
    }
 
    
 
 
 
}
 