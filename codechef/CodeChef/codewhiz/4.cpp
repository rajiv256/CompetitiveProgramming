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
#define PI 3.141592653589793238

int L[109][109][2][19] ;
int n1, n2 , k1 , k2 ; 


int solve(int ri ,int rp ,int prev, int prevSize){
    
    if ((ri < 0) || (rp < 0)){
        return 0 ; 
    }
    if (prev == 0){
       if (prevSize > k1){
           return 0 ; 
       }
    }
    if (prev == 1){
        if (prevSize > k2){
            return 0 ; 
        }
    }
    if (ri == 0 && rp == 0){
        //cout << ri << sp << rp << sp<< prev << sp << prevSize << el ; 
        return 1 ; 
    }
    if (L[ri][rp][prev][prevSize] != -1){
        //cout << ri << sp << rp << sp<< prev << sp << prevSize << el ;
        return L[ri][rp][prev][prevSize] ; 
    }
    int ans = 0 ; 
    if (prev == 0){
        int res1 = 0 , res2 = 0 ; 
        if (ri > 0)
            res1 = L[ri-1][rp][prev][prevSize+1] = solve(ri-1,rp,prev,prevSize+1) ; 
        if (rp > 0)
            res2 = L[ri][rp-1][1][1] = solve(ri,rp-1,1,1) ; 
        ans = res1+res2 ; 
    }
    else{
        int res1 = 0 , res2 = 0 ; 
        if (ri > 0)
            res1 = L[ri-1][rp][0][1] = solve(ri-1,rp,0,1) ; 
        if (rp > 0)
            res2 = L[ri][rp-1][prev][prevSize+1] = solve(ri,rp-1,prev,prevSize+1) ; 
        ans = res1+res2 ;  
    }
    return ans ; 
        
} 

int main(){
    memset(L,-1,sizeof(L)) ; 
    scanf("%d%d%d%d",&n1,&n2,&k1,&k2) ; 
    int ans = solve(n1-1,n2,0,1)+solve(n1,n2-1,1,1) ; 
    cout << ans << el ;     
}