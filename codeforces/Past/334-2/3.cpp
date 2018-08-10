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

int main(){
    int n ; cin >> n ; 
    string s ; cin >> s; 
    vi v(n) ; 
    forn(i,n){
        if (s[i] == '0'){
            v[i] = 0; 
        }
        else{
            v[i] = 1 ; 
        }        
    }
    vi cnt ; 
    int count = 1 ; int prev = v[0] ; 
    for(int i = 1; i < n ; i++){
        if (v[i] == prev){
            count ++ ; 
        }
        else {
            cnt.pb(count) ; 
            prev = v[i] ; 
            count = 1 ; 
        }
    }
    cnt.pb(count) ; int maxi = 0 ; 
    
    cnt.pb(0) ; cnt.pb(0) ; 
    forn(i,cnt.size()-2){
        if (cnt[i] >= 3){
            cout << ((cnt.size()+2)-2) << el ; 
            return 0 ;         
        }
    }
    int tc = 0 ; 
    forn(i,cnt.size()-2){
        if (cnt[i] == 2){
            tc++ ; 
        }
    }
    if (tc == 1){
        cout << cnt.size()-2+1 << el ; 
        return 0 ; 
    }
    if (tc > 1){
        cout << cnt.size() << el ;
        return 0 ; 
    }
    cout << cnt.size()-2 << el  ; 
    return 0 ; 
    
}