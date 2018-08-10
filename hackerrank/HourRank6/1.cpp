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
#define mp(a,b) make_pair(a,b)
#define abs(a) (a>0?a:-a)

int main(){
    int n , k ; cin >> n >> k ; 
    vi v(n+1) ; v[0] = 0 ;  
    forn(i,n){
        sci(v[i+1]) ; 
    }
    map<int,pair<int,int> > ma ; 
    int curpg = 1 ; int curchap = 1 ; 
    int st = 1 ; int probs = v[curchap] ;
    while (curchap <= n){
        if (probs > k){
            probs -= k ; 
            ma[curpg] = mp(st,st+k-1) ;
            st += k ; 
            curpg++ ; 
            continue ;  
        }
        else {
            ma[curpg] = mp(st,st+probs-1) ; 
            curpg++ ; curchap++ ;
            if (curchap > n){
                break ; 
            } 
            probs = v[curchap] ;
            st = 1 ;  
        }
    }
    int spec = 0 ; int pgnum = 1 ;
    for (map<int,pair<int,int> > :: iterator it = ma.begin() ; it != ma.end() ; it++ ){
        if ((*it).xx >= (*it).yy.xx && (*it).xx <= (*it).yy.yy){
            spec += 1 ;
        }
    }
    cout << spec << el ; 
    
}
