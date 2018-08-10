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
#define sci(x) scanf("%d",&x)
 
int main(){
    int n ; sci(n) ; 
    vector<ll> v(n) ; 
    forn(i,n){
        cin >> v[i] ;  
    }
    vector<ll> o ; vector<ll> e ;  
    forn(i,n){
        if (v[i]&1){
            o.pb(v[i]) ; 
        }
        else
            e.pb(v[i]) ; 
    }
    ll sum = 0 ; 
    sort(all(o)) ; 
    forn(i,e.size()){
        sum += e[i] ; 
    }
    if (o.size()&1){
        for(int i = 1 ; i < o.size() ; i++){
            sum += o[i] ; 
        }
    }
    else {
        forn(i,o.size()){
            sum += o[i] ; 
        }
    }
    cout << sum << el ; 
    return 0 ; 
}