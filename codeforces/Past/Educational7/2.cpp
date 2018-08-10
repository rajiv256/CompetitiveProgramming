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

int main(){
    string time ; cin >> time ; 
    int min ; cin >> min ; 
    vc h ; vc m ; 
    h.pb(time[0]) ; h.pb(time[1]) ; 
    m.pb(time[3]) ; m.pb(time[4]) ; 
    int hh = (h[1]-'0')+(h[0]-'0')*10 ; 
    int mm = (m[1]-'0')+(m[0]-'0')*10 ; 
    int inch = min/60 ; 
    int incm = min % 60 ;
    hh = (hh+inch)%24 ; 
    int temp = mm+incm ; 
    hh = (hh+temp/60)%24 ; 
    mm = temp % 60 ;
   // cout << mm << el ;  
    vi H ; vi M ; 
    H.pb(hh%10) ; hh/= 10 ; H.pb(hh%10) ; 
    M.pb(mm%10) ; mm/= 10 ; M.pb(mm%10) ; 
    cout << H[1]<<H[0]<<":"<<M[1] << M[0] << el ; 
    return 0 ;  
    
}