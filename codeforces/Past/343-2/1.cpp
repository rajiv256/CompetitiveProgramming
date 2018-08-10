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

int main(){
    int n  ; cin >> n ; 
    char a[n][n] ; 
    forn(i,n){
       string s ; cin >> s; 
        forn(j,n){
            a[i][j] = s[j] ;    
        }
    }
    int cnt = 0 ;
    forn(i,n){
        int r = 0 ; 
        forn(j,n){
            if (a[i][j] == 'C'){
                r += 1; 
            }
        }
        cnt += (r*(r-1))/2  ; 
    }
    forn(j,n){
        int c = 0 ; 
        forn(i,n){
            if (a[i][j] == 'C'){
                c += 1 ; 
            }
        }
        cnt += (c*(c-1))/2 ; 
    }
    cout << cnt << el ;
    return 0 ; 
}