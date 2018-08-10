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


 

bool invalid(int x , int y,int n ,int m){
    if (x >= n || y >= m || x < 0 || y < 0){
        return true ;
    }
    return false ; 
}

bool sink(int x , int y,int px[],int py[],int a[25][25],int n,int m){
    forn(i,4){
        if (invalid(x+px[i],y+py[i],n,m)){
            continue ; 
        }
        if (a[x+px[i]][y+py[i]] < a[x][y]){
            return false ; 
        }
    }    
    return true ; 
}

pair<int,int> fsink(int x , int y,int px[],int py[],int a[25][25],int n , int m){
    int mini = INT_MAX ; 
    if (!invalid(x,y,n,m))
    if (sink(x,y,px,py,a,n,m)){
        return mp(x,y) ; 
    }
    forn(i,4){
    	if (!invalid(x+px[i],y+py[i],n,m))
        	mini = min(a[x+px[i]][y+py[i]],mini) ; 
    }
    
    forn(i,4){
        if (!invalid(x+px[i],y+py[i],n,m))
        if (a[x+px[i]][y+py[i]] < a[x][y]){
            if (a[x+px[i]][y+py[i]]==mini)
                return fsink(x+px[i],y+py[i],px,py,a,n,m) ; 
        }
    }
    return (mp(x,y)) ; 
}
int main(){
     int n , m ; 
int px[4] ; 
int py[4] ;
int a[25][25] ; 
    px[0] = -1 ; px[1] = 0 ; px[2] = 0 ; px[3] = 1 ; 
    py[0] = 0 ; py[1] = -1 ; py[2] = 1 ; py[3]= 0 ; 
    
    memset(a,0,sizeof(a)) ; 
    //scanf("%d%d",&n,&m) ; 
    cin >> n >> m ; 
    forn(i,n){
        forn(j,m){
            cin >> a[i][j] ;  
        }
    }
    vector<pair<int,int> > sinks ; 
    char cs[n][m] ; 
    memset(cs,0,sizeof(cs));   
    forn(i,n){
        forn(j,m){
            if (sink(i,j,px,py,a,n,m)){
                sinks.pb(mp(i,j)) ; 
            }
        }
    }
    vector<pair<int,int> > v ;  
    forn(i,n){
        forn(j,m){
            if (!sink(i,j,px,py,a,n,m)){
                pair<int,int> p = fsink(i,j,px,py,a,n,m) ; 
                v.pb(p) ;     
            }
            else{
                v.pb(mp(i,j)); 
            }
            
        }
    }
    // forn(i,v.size()){
    // 	cout << v[i].xx <<"," << v[i].yy << sp ; 
    // }
    //cout << el ; 
    map<int,char> ma ; 
    forn(i,v.size()){
        ma[i] = '@' ;
    }
    char curr = 'a' ; 
    int k = 0 ; 
    forn(i,n){
        forn(j,m){
            vector<pair<int,int> > :: iterator it ; 
            it = find(all(sinks),v[k]) ;
            k++ ; 
            if (it != sinks.end()){
                int pos = distance(sinks.begin(),it) ; 
                if (ma[pos] == '@'){
                    ma[pos] = curr ; 
                    curr++ ; 
                }
                cs[i][j] = ma[pos] ; 
            }
        }
    }
    forn(i,n){
        forn(j,m){
            cout << cs[i][j] << sp ; 
        }
        cout << el ; 
    }
     return 0 ; 
}