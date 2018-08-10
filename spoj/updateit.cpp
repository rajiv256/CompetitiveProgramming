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

int BIT[10009] ; 
int t, u , n , q ,l,r,val,x; 
void update(int x , int val,int n){
    while (x <= n){
        BIT[x] += val ; 
        x += (x&-x) ; 
    }
    
}

int query(int x){
    int sum = 0 ; 
    while (x > 0){
        sum += BIT[x] ;
        x -= (x&-x) ; 
    }
    return sum ; 
}



int main(){
     sci(t) ; 
    while (t--){
        //int n, u ; 
        memset(BIT,0,sizeof(BIT)) ; 
        sci(n) ; sci(u) ; 
        while(u--){
            scanf("%d%d%d",&l,&r,&val) ; 
            update(l+1,val,n) ; 
            update(r+2,-val,n) ; 
        }
        //int q; sci(q) ; 
        sci(q) ; 
         
        while(q--){
            sci(x) ; 
            int ans = query(x+1) ; 
            printf("%d\n",ans) ; 
        }
    }
    return 0 ; 
}