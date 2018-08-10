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
#define pii pair<int,int> 
#define pic pair<int,char> 
#define sii set<pair<int,int> >  
#define MOD 100000000
#define sp " " 
#define el "\n"
#define ll long long int 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x) 

ll pow(ll a , ll b){
    if (b==0) return 1 ;
    ll k = pow(a,b/2) ;
    if (b&1) return a*k*k ; 
    else   return k*k ; 
}

int fin[100005] ; 

bool placeAtDist(vector<ll>& stalls , int dist,int n,int ncows){
    int lastpos = 1 ; int cs = 1 ; 
    for(int i = 1 ; i < n ; i++){
        if (stalls[i]-lastpos >= dist){
            cs++ ;  
            if (ncows == cs) 
               return 1 ; 
            lastpos = stalls[i] ; 
             
        }
        
    }
    return 0 ; 
}



int main(){
    int t ; sci(t) ; 
    while(t--){
        memset(fin,0,sizeof(fin)) ; 
        int n , cows ; sci(n) ; sci(cows) ; 
        vector<ll> stalls(n) ;
        forn(i,n){
            cin >> stalls[i] ; 
        } 
        sort(all(stalls))  ; 
        ll minDist = stalls[0] ; 
        ll maxDist = stalls[n-1]-stalls[0] ; 
        while (minDist+1 < maxDist){
           ll mid = (minDist+maxDist)/2 ; 
           if (placeAtDist(stalls,mid,n,cows)){
               minDist = mid ;  
           } 
           else{
               maxDist = mid ; 
           }
        }
        cout << minDist << el ; 
        
    }
    return 0 ;
}

