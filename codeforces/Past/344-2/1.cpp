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

int a[1003] ; 
int b[1003] ;
int an[1003] ; 
int bn[1003] ;  
int as[1003] ;
int ans[1003] ;  
int bs[1003] ; 
int bns[1003]  ; 

int main(){
    int n ; cin >> n ; 
    memset(a,0,sizeof(a)) ; 
    memset(b,0,sizeof(b)) ;
    memset(an,0,sizeof(an)) ; 
    memset(bn,0,sizeof(bn)) ;  
    memset(as,0,sizeof(as)) ; 
    memset(bs,0,sizeof(bs)) ;
    forn(i,n){
       sci(a[i]) ;  
       an[i] = !a[i] ; 
    } 
    forn(i,n){
        sci(b[i]) ; 
        bn[i] = !b[i] ; 
    }
    int res = INT_MIN ; 
    forn(i,n){
         
        for(int j = i ; j < n ; j++){
            int sum = 0 ; int sum1 = 0 ; int sum2 = 0 ;
            for(int k = i ; k <= j ; k++){
                sum1 |= a[k] ; 
                sum2 |= b[k] ;     
            }
            sum = sum1+sum2 ; 
            res = max(res,sum) ; 
        }
    }
    cout << res << el ;  
}
