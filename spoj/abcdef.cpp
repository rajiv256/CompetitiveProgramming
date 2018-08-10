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

int solve(vi& v1 , vi& v2){
    int cnt = 0 ; 
    forn(i,v2.size()){
        if (binary_search(all(v1),v2[i])){
            vi::iterator lo = lower_bound(all(v1),v2[i]) ; 
            vi::iterator up = upper_bound(all(v1),v2[i]) ; 
            cnt += up-lo ; 
        }
    }
    return cnt ; 
}

int main(){
    int n ; sci(n) ; 
    vi v(n) ; 
    forn(i,n){
        sci(v[i]) ; 
    }
   int N = n*n*n ; int idx = 0 ; 
   int a1[N] ; int a2[N] ; int sz1 = 0 , sz2 = 0 ; 
   vi v1 ;  
    forn(i,n){
        forn(j,n){
            forn(k,n){
               v1.pb(v[i]*v[j]+v[k]) ; 
               idx++ ;   
               sz1++ ; 
            }
        }
    }
    idx = 0 ; 
    vi v2 ; 
    forn(i,n){ 
        if (v[i] == 0){
            continue ; 
        }
        forn(j,n){
            forn(k,n){
                    v2.pb(v[i]*(v[j]+v[k])) ; 
                    idx++ ;
                    sz2++ ;     
                
                  
            }
        }
    }
    // int a11[sz1] ; int a22[sz2] ; 
    // forn(i,sz1){
    //     a11[i] = a1[i] ; 
    // }
    // forn(i,sz2){
    //     a22[i] = a2[i] ; 
    // }
    // sort(a11,a11+sz1) ; 
    // sort(a22,a22+sz2) ; 
    sort(all(v1)) ; 
    sort(all(v2)) ; 
    // forn(i,sz1){
    //     cout << a11[i] << sp ; 
    // }
    // cout << el ;
    // forn(i,sz2){
    //     cout << a22[i] << sp ; 
    // }
    // cout << el ; 
    int cnt = solve(v1,v2) ; 
    //int cnt = solve(a11,a22,sz1,sz2) ; 
    cout << cnt << el; 
    
}