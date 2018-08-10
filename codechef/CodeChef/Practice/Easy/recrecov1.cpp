
#include <iostream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std ;
#include <bits/stdc++.h> 
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

bool adj[107][107] ; 
int path[107][107] ; 


int main(){
    int t ; sci(t) ; 
    while (t--){
       memset(adj,false,sizeof(adj)) ; 
       forn(i,107){
           forn(j,107){
               path[i][j] = INT_MAX ; 
           }
       }
       int n , m  ; sci(n) ; sci(m) ; 
       int a , b ;
       forn(i,m){
           sci(a) ; sci(b) ;
           adj[a][b] = true ;
           adj[b][a] = true ; 
       }
       //cout << adj[2][3] << el ; 
       int cnt = 0 ; 
       for(int i = 1 ; i <= n ; i++){
           if (!visited[i]){
               cnt += 1 ; 
               //cout << "end1" << el ;
               dfs(i,n) ; 
               
               
           }
           
       }
       cout << cnt << el ; 
       
    }   
}