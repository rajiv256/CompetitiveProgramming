
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
ll n,s ; 
bool btrack(ll a[] ,vb& mask , ll curr, ll res , string str){
    if (curr == n){
        if (res == s){
            return true ; 
        }
        else{
            return false ; 
        }
    }
    for(int i = 0 ; i < n ; i++){
        if (!mask[i]){
            mask[i] = true ; 
            if(btrack(a,mask,curr+1,res+a[curr],str+'+')){
                return true ; 
            }
            else if (btrack(a,mask,curr+1,res-a[curr],str+'-')){
                return true ; 
            }
            else if (btrack(a,mask,curr+1,res+))
        }
    }   
}




int main(){ 
    cin >> n >> s ;
    ll a[n] ; 
    forn(i,n){
       cin >> a[i] ;  
    }
    str = "" ; 
    forn(i,n){
        str = "" ; 
        ll res = a[i] ;
        vb mark(n,false) ;
        mark[i] = true ;  
        if (btrack(a,i,res,str)){
            cout << str << el ;
            return 0 ;  
        }   
    }
    
    cout << "Impossible\n" << el ; 
    return 0 ; 
}