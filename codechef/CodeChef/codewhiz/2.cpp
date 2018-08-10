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

int a[1009][1009] ; 
bool sv[110009] ; 

void sieve(){
    //cout << "came" << el ; 
    for (int i = 2 ; i <= 100019 ; i++){
        if (!sv[i]){
            for (int j = 2 ; i*j <= 100019 ; j++){
                sv[i*j] = true ; 
            }
        }
    }
    //cout << "nikaale" << el ; 
}

int nearPrime(int n){
    if (!sv[n]){
        return 0 ; 
    }
    int off = 1 ; 
    while (true){
        if (!sv[n+off]){
            return (off) ; 
        }
        off += 1 ; 
    }
}

int main() {
    memset(sv,false,sizeof(sv)) ; 
    memset(a,0,sizeof(a)) ; 
    sieve() ; 
    sv[1] = true  ; 
    sv[0] = true ; 
    int n ,m ; cin >> n >> m ; 
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            sci(a[i][j]) ; 
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            a[i][j] = nearPrime(a[i][j]) ; 
        }
    }
    int mini = INT_MAX ; 
    for(int i = 1 ; i <= n ; i++){
        int sum = 0 ; 
        for (int j = 1 ; j <= m ; j++){
            sum += a[i][j] ; 
        }
        mini = min(mini,sum) ; 
    }
    for(int j = 1 ; j <= m ; j++){
        int sumc = 0 ; 
        for(int i = 1 ; i <= n ; i++){
            sumc += a[i][j] ; 
        }
        mini = min(mini,sumc) ; 
    }
    cout << mini << el ;    
    return 0 ; 
}