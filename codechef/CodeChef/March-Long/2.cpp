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

ll a[100003] ; 
ll b[100003] ; 

int main(){
   int t ; sci(t) ;  
   while(t--){
       memset(a,0,sizeof(a)) ; 
       memset(b,0,sizeof(b)) ; 
       int n , k ; sci(n) ; sci(k) ; 
       forn(i,n){
           scanf("%lld",&a[i]) ;  
       }
       forn(i,n){
           scanf("%lld",&b[i]) ; 
       }
       ll maxi = 0; 
       forn(i,n){
           maxi += a[i]*b[i] ; 
       }
       forn(i,n){
           if (b[i] <0){
               a[i] = -a[i] ; 
               b[i] = -b[i] ; 
           }
       }
       int maxV = b[0] ; int maxI = 0 ; 
       forn(i,n){
           if (maxV < b[i]){
               maxV = b[i] ; 
               maxI = i ; 
           }
       }
       maxi += k*maxV ; 
       cout << maxi << el ; 
   }
   return 0 ; 
}