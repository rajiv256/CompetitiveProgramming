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

bool a[1009] ; 

void sieve(){
    for(int i = 2 ; i <= 1000 ; i++){
        if (!a[i]){
            for (int j = 2 ; i*j <= 1000 ; j++){
                a[i*j] = true ; 
            }    
        }
    }   
}

int main(){
    int n , k ; cin >> n >> k ; 
    memset(a,false,sizeof(a)) ; 
    sieve() ; 
    vi v ; 
    for(int i=2 ; i <= n ; i++){
        if (!a[i]){
            v.pb(i) ; 
        }
    }
    int cnt = 0 ; 
    for (int i = 0 ; i < v.size()-1 ; i++){
        if ((v[i]+v[i+1]+1 < n) && !a[v[i]+v[i+1]+1]){
            //cout << v[i] << sp << v[i+1] << el  ; 
            cnt ++ ; 
        } 
    }
    if (cnt >= k){
        cout << "YES\n" ; 
    }
    else {
        cout << "NO\n" ; 
    }
    return 0 ; 
}