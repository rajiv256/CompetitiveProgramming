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
#define MXN 1000003
#define gc getchar_unlocked

int a[113][113] ; 
int L[113] ; 
bool vis[113] ; 

void dijkstra(int s){
    if (!vis[s]){
        //cout << s << el ; 
        vis[s] = true ; 
        for(int i = 1 ; i <= 100 ; i++){
            if (!vis[i] && (a[s][i]!=0)){
                if (L[i] > L[s]+a[s][i]){
                    L[i] = L[s]+a[s][i] ; 
                }
            }
        }
        
        int mini = INT_MAX ; 
        for(int i = 1 ; i <= 100 ; i++){
            if (!vis[i]){
                if (i < mini){
                    mini = i ; 
                }
            }
        }
        if (mini <= 113)
         dijkstra(mini) ;
        return ;  
    }
    return ; 
}
int main(){
    memset(a,0,sizeof(a)) ;
    memset(vis,false,sizeof(vis)) ;
    forn(i,113){
        L[i] = 1000000 ; 
    } 
    L[1] = 0 ;   
    int k ; cin >> k ; 
    for(int i = 1 ; i <= 100  ;i++ ){
        for(int j = 1; j <= k ; j++){
            a[i][i+j] = 1 ; 
            a[i+j][i] = 1 ; 
        }
    }
    int pass , vall ; 
    cin >> pass >> vall ; 
    int x , y ; 
    forn(i,pass){
        cin >> x >> y ;
        a[x][y] = 1 ;  
        
    }
    forn(i,vall){
        cin >> x >> y ; 
        a[x][y] = 1 ; 
    }
    dijkstra(1) ; 
    cout << L[100] << el ; 
    return 0 ; 
}