//rajiv's code


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
typedef map<int,int> mii ; 
typedef map<int,vector<int> > miv ; 
typedef unsigned long long ull ; 


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define pii pair<int,int>   
#define INF 1000000
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


int n ; 
int sq ; 


struct query{
    int idx ; 
    int l , r ; 
    
} ; 


bool comp(query a , query b){
    if (a.l/sq != b.l/sq){
        return (a.l/sq < b.l/sq) ; 
    }    
    return (a.r < b.r) ; 
}
// Everything using 1-indexing. 
int arr[1000009] ;
int cnt[1000009] ;  
query q[1000009] ; 
int aaa[1000005] ;
int ans = 0 ; 
int currL = 0 ; 
int currR = 0 ;


inline void add(int pos){
    cnt[arr[pos]]++ ; 
    if (cnt[arr[pos]] == 1){
        ans += 1; 
    }
}
inline void remove(int pos){
    cnt[arr[pos]]-- ; 
    if (cnt[arr[pos]] == 0){
        ans -= 1 ; 
    }
}

int main(){
    sci(n) ; 
    //memset(arr,0,sizeof(arr)) ; 
    //memset(cnt,0,sizeof(cnt)) ; 
    forn(i,n){
        sci(arr[i+1])  ; 
    }    
    sq = sqrt(n) ; 
    
    int d ; sci(d) ; 
    int a , b ; 
    forn(i,d){
        sci(a) ; sci(b) ;
        q[i].idx = i ; q[i].l = a ; q[i].r = b ;     
    }
    sort(q,q+d,comp) ;
    
    forn(i,d){
        int l = q[i].l ; int r = q[i].r ; 
        while (currL < l){
            remove(currL) ; 
            currL++ ; 
        }
        while(currL > l){
            add(currL-1) ; 
            currL-- ; 
        }
        while (currR < r){
            add(currR+1) ; 
            currR ++ ; 
        }
        while (currR > r){
            remove(currR) ;
            currR-- ; 
        }
       
        aaa[q[i].idx] = ans ; 
    }
    forn(i,d){
        printf("%d\n",aaa[i]) ; 
    } 
    return 0 ; 
}