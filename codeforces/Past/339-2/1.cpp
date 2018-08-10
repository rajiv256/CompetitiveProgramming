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

ll powe(ll a , ll b){
    if (b == 0){
        return 1 ; 
    }
    if (b == 1){
        return a ; 
    }
    if (b&1){
        ll k = powe(a,b/2) ; 
        return (a*k*k) ; 
    }
    else{
        ll k = powe(a,b/2) ; 
        return k*k  ; 
    }
}

int main(){
    ll l , r , k ; 
    cin >> l >> r >> k ; 
    ll st = log2(l)/log2(k) ; 
    if (powe(k,st) != l){
        st += 1 ; 
    }
    int fl = 0 ; 
    ll init = powe(k,st) ; 
    while(init <= r){
        fl = 1 ; 
        cout << init << sp ; 
        init *= k ; 
    }
    if (fl == 0){
        cout << "-1" << el ; 
    }
    return 0 ; 
}