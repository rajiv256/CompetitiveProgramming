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


void scanInt(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}



typedef struct node {
    int sum ; 
    int psum ; 
    int ssum ; 
    int maxsum ; 
    
    void init(int x){
        sum = psum = ssum = maxsum = x ; 
    }
    
    void merge(node l , node r){
        sum = l.sum+r.sum ; 
        psum = max(l.psum , l.sum+r.psum) ; 
        ssum = max(r.ssum,l.ssum+r.sum) ; 
        maxsum = max(l.maxsum,max(r.maxsum,l.ssum+r.psum)) ;     
    }
    
}node ;

int a[50009] ; 
node stree[4*50009] ;  

void build(int low , int high , int s){
    if (low == high){
        stree[s].init(a[low]) ; 
        return ; 
    }
    int mid = (low+high)/2 ; 
    build(low,mid,2*s) ; 
    build(mid+1,high,2*s+1) ; 
    stree[s].merge(stree[2*s],stree[2*s+1]) ;
    return ; 
    
}

void update(int low , int high , int idx , int val , int s){
    if (low > idx || idx > high){
        return ; 
    }
    if (low == idx && high == idx){
        a[idx] = val ; 
        stree[s].init(val) ; 
        return ; 
    }
    int mid = (low+high)/2 ; 
    if (idx <= mid){
        update(low,mid,idx,val,2*s) ; 
    }
    else {
        update(mid+1,high,idx,val,2*s+1) ;
    }
    stree[s].merge(stree[2*s],stree[2*s+1]) ; 
    return ;  
    
}

node query(int low , int high , int left , int right , int s){
    
    if (left <= low && right >= high){
        return stree[s] ; 
    }
    int mid = (low+high)/2 ; 
    if (mid >= right){
        return query(low,mid,left,right,2*s) ; 
    }
    else if (mid < left){
        return query(mid+1,high,left,right,2*s+1) ; 
    }
    node l = query(low,mid,left,right,2*s) ; 
    node r = query(mid+1,high, left , right , 2*s+1) ;
    node temp ; temp.merge(l,r) ;
    return temp ; 

}

int main(){
    int n ; scanInt(n) ; 
    memset(a,0,sizeof(a)) ; 
    
    forn(i,n){
        scanInt(a[i+1]) ; 
    }
    build(1,n,1) ; 
    int m ; scanInt(m)  ; 
    int w , x ,y ; 
    while(m--){
        scanInt(w) ; scanInt(x) ; scanInt(y) ;  
        if (w){
            node ans = query(1,n,x,y,1) ; 
            printf("%d\n",ans.maxsum) ; 
        }
        else{
            update(1,n,x,y,1) ; 
        }
    }
    return 0 ; 
}