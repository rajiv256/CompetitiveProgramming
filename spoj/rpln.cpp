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
int stree[MXN] ; 

// fast input
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



int build(vi& v , int low , int high,int index){
   // cout << low << sp << high << sp << index << el ;  
    if (low == high){
        stree[index] = v[low] ; 
        return stree[index] ; 
    }
    int mid = (low+high)/2 ; 
    int t1 = 2*index ; int t2 = 2*index+1 ; 
    stree[t1] = build(v,low,mid,t1) ; 
    stree[t2] = build(v,mid+1,high,t2) ; 
    return min(stree[t1] , stree[t2]) ; 
    
}
int query(int low , int high , int left , int right, int s){
    // Non-overlapping
    if (left > high || right < low){
        return INT_MAX; 
    }
    if (left <= low && right >= high){
        return stree[s] ; 
    }
    int mid = (low+high)/2 ; 
    return min(query(low,mid,left,right,2*s),query(mid+1,high,left,right,2*s+1)) ; 
}



int main(){
    
    int T ; scanInt(T) ; int t= 1 ;  
    while (T--){
        int n , q ; scanInt(n) ; scanInt(q);    
        vi v ; v.pb(0) ; 
        memset(stree,0,sizeof(stree)) ; 
        int x ; 
        forn(i,n){
            scanInt(x) ;  
            v.pb(x) ; 
        } 
        //cout << "Hello" << el ;     
        stree[1] = build(v,1,n,1) ;
        int a , b ; 
        cout << "Scenario #" << t << ":\n\n" ;
        while (q--) {
             
            scanInt(a) ; scanInt(b) ;   
            int ans = query(1,n,a,b,1) ;
            cout << ans << el ; 
            cout << el ; 
            
        }    
        t += 1 ; 
    }
    
    return 0 ; 
}