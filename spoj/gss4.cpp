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
    ll sum ; 
    bool flag ; 
    
    void merge(node l , node r){
        sum = l.sum+r.sum ; 
        if (l.flag & r.flag){
            flag = true ; 
        }
        else {
            flag = false ; 
        }
    }
}node ; 

ll a[100009] ; 
node stree[4*100009] ; 

void build(int low , int high , int s){
    if (low == high){
        stree[s].sum = a[low] ;
        if (a[low] == 1){
            stree[s].flag = true ; 
        }
        else {
            stree[s].flag = false; 
        }
        return ; 
    }
    int mid = (low+high)/2 ; 
    build(low,mid,2*s+1) ; 
    build(mid+1,high,2*s+2) ; 
    stree[s].merge(stree[2*s+1],stree[2*s+2]) ; 
    return ; 
}

void update(int low , int high , int left , int right , int s){
    if (right < low || left > high){
        return ; 
    }
    if (stree[s].flag){
        return ; 
    }
    if (low == high){
        a[low] = sqrt(a[low]) ; 
        stree[s].sum = a[low] ; 
        if (a[low] == 1){
            stree[s].flag = true ; 
        }
        return ; 
    }
    int mid = (low+high)/2 ; 
    if (mid >= right){
        update(low , mid,left,right,2*s+1) ;     
    }
    else if (mid < left){
        update(mid+1,high,left,right,2*s+2) ; 
    }
    else {
        update(low,mid,left,right,2*s+1)  ; 
        update(mid+1,high,left,right,2*s+2) ; 
    }
    stree[s].merge(stree[2*s+1],stree[2*s+2]) ; 
    return ; 
}

ll query(int low , int high , int left , int right , int s){
    if (left > high || right < low){
        return 0 ; 
    } 
    if (left <= low && right >= high){
        return stree[s].sum ; 
    }
    int mid = (low+high)/2 ; 
    ll l = query(low,mid,left,right,2*s+1) ; 
    ll r = query(mid+1,high,left,right,2*s+2) ; 
    return (l+r) ; 
}

int main(){
    int n ; int count = 1 ; 
    while (scanf("%d",&n)!= EOF){
        memset(a,0,sizeof(a)) ; 
        for (int i = 0 ; i < n ; i++){
            scanf("%lld",&a[i+1])  ;
        }
        forn(i,4*100009){
            stree[i].sum  = 0 ; 
            stree[i].flag = false ; 
        }
        build(1,n,1) ; 
        
        int m ; scanf("%d",&m)  ; 
        int w , x , y ; 
        printf("Case #%d:\n",count) ; 
        while (m--){
            scanf("%d%d%d",&w,&x,&y) ;
            
            if (w) {
                ll ans = query(1,n,min(x,y),max(x,y),1) ; 
                printf("%lld\n",ans) ; 
            }
            else{
                update(1,n,min(x,y),max(x,y),1) ; 
            }
        }
        printf("\n"); 
        count ++ ; 
    }
    return 0 ; 
}