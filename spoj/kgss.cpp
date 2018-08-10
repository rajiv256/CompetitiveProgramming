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

//fast io 
void scanInt(int &x){
    register int c = gc() ; 
    x = 0 ;
    for (;(c < 48 || c > 57); c=gc()) ; 
    for (;(c > 47 && c < 58);c=gc()){
        x = (x<<1)+(x<<3)+c - 48 ; 
    }
    return ; 
}

pair<int,int> build(vi& a ,vp& stree,int low ,int high , int s){
    if (low == high){
        stree[s] = mp(a[low],0) ; 
        return stree[s] ; 
    }
    int mid = (low+high)/2 ; 
    int t1 = 2*s ; int t2 = 2*s+1 ; 
    stree[t1] = build(a,stree,low,mid,t1) ; 
    stree[t2] = build(a,stree,mid+1, high,t2) ; 
    int x1 = stree[t1].xx , y1 = stree[t1].yy , x2 = stree[t2].xx , y2 = stree[t2].yy ; 
    vi v ; v.pb(x1) ; v.pb(y1) ; v.pb(y2) ; v.pb(x2) ; 
    sort(all(v)) ; 
    return (mp(v[3],v[2])) ; 
}

pair<int,int> query(vi& a , vp& stree , int low , int high , int left , int right , int s){
    if (left > high || right < low){
        return mp(0,INT_MIN) ; 
    }
    if (left <= low && right >= high){
        return stree[s] ; 
    }
    int mid = (low+high)/2 ; 
    pair<int,int> p1 = query(a,stree,low,mid,left,right,2*s) ; 
    pair<int,int> p2 = query(a,stree,mid+1,high,left,right,2*s+1) ; 
    vi v(4,0); v[0] = p1.xx ; v[1] = p1.yy ; v[2] = p2.xx ; v[3] = p2.yy ; 
    
    sort(all(v)) ; 
    return (mp(v[3],v[2])) ; 
}

void update(vp& stree,int low , int high, int idx ,int s, int k){
    
    if (low == idx && high == idx){
        stree[s] = mp(k,0) ; 
        return ; 
    }
    int mid  = (low+high)/2 ; 
    
    if (idx >= low && idx <= mid){
        update(stree,low,mid,idx,2*s,k) ; 
    }
    if (idx > mid && idx <= high){
       update(stree,mid+1,high,idx,2*s+1,k) ; 
    }
    int x1 = stree[2*s].xx , y1 = stree[2*s].yy , x2 = stree[2*s+1].xx , y2 = stree[2*s+1].yy ;
    vi v(4,0); v[0] = x1; v[1] = y1 ; v[2] = x2 ; v[3] = y2 ; 
    sort(all(v)) ; 
    stree[s] = mp(v[3],v[2]) ; 
    
    return ; 
}




int main(){
    int n ; scanInt(n) ; 
    vi a ; a.rsz(n+1) ; a[0] = 0 ; 
    forn(i,n){
        scanInt(a[i+1]) ; 
    } 
    int sz = 4*MXN+8 ;
    pair<int,int> aq = mp(0,0) ;  
    vector<pair<int,int> > stree(sz,aq)  ; 
    stree[1] = build(a,stree,1,n,1) ; 
    int m ; scanInt(m) ; 
    char c ; int p,q ; 
    while (m--){
        scanf("%c",&c) ; 
        scanInt(p) ; scanInt(q) ; 
        
        if (c == 'U') {
            a[p] =  q ; 
            update(stree,1,n,p,1,q) ; 
        }
        if (c == 'Q'){
            pair<int,int> ans = query(a,stree,1,n,p,q,1) ; 
            //cout << ans.xx << sp << ans.yy << el ; 
            cout << (ans.xx + ans.yy) << el ; 
        }
    }
    
    return 0 ;
}