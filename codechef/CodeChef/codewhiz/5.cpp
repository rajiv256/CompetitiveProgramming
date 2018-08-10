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

double L[100009][2]; 

// double dp(vector<double>& vol1 , int idx , int n, double initvol){
//     if (idx == n){
//         return 0 ; 
//     }
    
//     if (initvol < vol1[idx]){
//         return max(vol1[idx]+dp(vol1,L,idx+1,n,vol1[idx]),dp(vol1,L,idx+1,n,initvol)) ; 
//     }  
//     else {
//         return dp(vol1,L,idx+1,n,initvol) ; 
//     }
    
// }

double dp(vector<double>& vol1 , int idx , int n , double initvol ){
    if (idx == n){
        return 0 ; 
    }
    
    if (initvol < vol1[idx]){
        if (L[idx+1][0] == -1)
        L[idx+1][0] = dp(vol1,idx+1,n,initvol) ; 
        if (L[idx+1][1] == -1)
        L[idx+1][1] = dp(vol1,idx+1,n,vol1[idx]);
        return max(L[idx+1][0],vol1[idx]+L[idx+1][1]) ; 
    }
    else{
        if (L[idx+1][0] == -1)
        L[idx+1][0] = dp(vol1,idx+1,n,initvol) ; 
        return L[idx+1][0] ; 
    }
}





int main(){
    int n ; cin >> n ; 
    vector<pair<double,double> > v(n) ; 
    double r , h ; 
    vector<double> vol (n) ; 
    
    forn(i,n){
        scanf("%lf%lf",&r,&h) ; 
        v[i] = mp(r,h) ; 
        vol[i] = PI*r*r*h ; 
        //cout << vol[i] << el ; 
    }
    forn(i,n){
        L[i][0] = -1 ;
        L[i][1] = -1 ;  
    }
   double ans =dp(vol,0,n,0); 
  
   printf("%.8f\n",ans) ; 
   return 0 ; 
    
}