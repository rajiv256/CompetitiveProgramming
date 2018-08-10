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




typedef struct node {
    ll sum ; 
    ll ma ; ll mi ; ll sma ; ll smi ; 
    
    void init(ll x){
        sum = ma = mi = x ;
        sma = INT_MIN ; smi = INT_MAX ;  
    }
    
    void merge(node l , node r){
        sum = l.sum + r.sum ;
        ma  = max(l.ma,r.ma) ; 
        mi = min(l.mi,r.mi) ; 
        sma = min(l.ma,r.ma) ; sma = max(sma,l.sma) ; sma = max(sma,r.sma) ; 
        smi = max(l.mi,r.mi) ; smi = min(smi,l.smi) ; smi = min(smi,r.smi) ; 
    }
}node ; 

//ll a[100009] ; 
//node stree[2*100009] ; 

void build(ll a[] , node stree[] , int low  , int high , int s){
    if (low == high){
        stree[s].init(a[low]) ; 
        return ; 
    }
    int mid = (low+high)/2 ; 
    build(a,stree,low,mid,2*s) ; 
    build(a,stree,mid+1,high,2*s+1) ; 
    stree[s].merge(stree[2*s],stree[2*s+1]) ; 
    return ; 
}

void update(ll a[],node stree[],int low,int high,int idx,int val ,int s){
    if (low == idx && high == idx){
        stree[s].init(val) ; 
        return ; 
    }
    if (idx < low || idx > high){
        return ; 
    }
    int mid = (low+high)/2 ; 
    update(a,stree,low,mid,idx,val,2*s) ; 
    update(a,stree,mid+1,high,idx,val,2*s+1) ; 
    stree[s].merge(stree[2*s],stree[2*s+1]) ; 
    return ; 
}

node query(ll a[],node stree[] ,int low,int high,int left , int right , int s){
    
    if (left <= low && right >= high){
        return stree[s] ; 
    }
    int mid = (low+high)/2 ;
    if (mid >= right){
        return query(a,stree,low,mid,left,right,2*s) ; 
    } 
    else if (mid < left){
        return query(a,stree,mid+1,high,left,right,2*s+1) ; 
    }
    else{
        node l = query(a,stree,low,mid,left,right,2*s) ; 
        node r = query(a,stree,mid+1,high,left,right,2*s+1) ;  
        node res ; res.merge(l,r) ; 
        return res ; 
    }
}


int main(){
    //std::ios::sync_with_stdio(false);
    int n ; sci(n) ; 
    //vector<ll> v(n) ;
    ll a[n+1] ;
    node stree[2*n+4] ;     
    memset(a,0,sizeof(a)) ; 
    memset(stree,0,sizeof(stree)) ;  
    forn(i,n){
        scanf("%lld",&a[i+1]) ; 
    }
    
    build(a,stree,1,n,1) ; 
    
    int q ; sci(q) ; char c ; int x , y ;  
    for (int i = 0 ; i < q ; i++){
        //cout << "---- " << q << " ----" << el ; 
        cin >> c >> x >> y ;  
        //cout << c << sp << x << sp << y << el ; 
        if (c == 'U'){
            update(a,stree,1,n,x,y,1) ; 
        }
        else{
            node ans = query(a,stree,1,n,x,y,1) ; 
            if (c == 'A'){
                cout << ans.sum << el ; 
            }
            if (c == 'M'){
                cout << ans.ma << el ;
            }
            if (c == 'm'){
                cout << ans.mi << el ; 
            }
            if (c == 'S'){
                cout << ans.sma << el ; 
            }
            if (c == 's'){
                cout << ans.smi << el ; 
            }
        }
    }
    return 0 ; 
}