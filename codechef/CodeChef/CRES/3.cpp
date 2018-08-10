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

int ans = 0 ; 

int solve(int st , int en , vi& v){
    if (st >= en){
        return 0; 
    }
    if (st >= v.size()){
        return 0 ; 
    }
    int maxI = st+1 ; 
    int maxV = v[st+1] ; 
    for(int i = st+1 ; i <= en ;i++){
        if (maxV >= v[st]){
            break ;
        }
        if (maxV < v[i]){
            maxV = v[i] ; 
            maxI = i ; 
        }
    }
    int sum = 0 ; 
    sum = (maxI-st-1)*min(v[maxI],v[st]) ; 
    for(int i = st+1 ; i < maxI ; i++){
        sum -= v[i] ; 
    }
    //cout << sum << el ; 
    return (sum+solve(maxI,en,v)) ; 
}

int main(){
    int t ; sci(t) ; 
    while (t--){
        int n ; sci(n)  ; 
        vi v(n,0) ; 
        forn(i,n){
            sci(v[i]) ; 
        }
        int st = 0 ; int en = n-1 ; 
        while ((v[st]==0) && (st < n)){
            st++ ;
        }
        while ((v[en] == 0) && (en >= 0)){
            en-- ; 
        }
        ans = 0 ; 
        ans = solve(st,en,v) ; 
        cout << ans << el ; 
    }
    return 0 ; 
}