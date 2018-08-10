//rajiv's code

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
typedef map<int,int> mii ; 
typedef map<int,vector<int> > miv ; 
typedef unsigned long long ull ; 


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define pii pair<int,int> 
#define pic pair<int,char> 
#define sii set<pair<int,int> >  
#define MOD 100000000
#define sp " " 
#define el "\n"
#define ll long long int 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x) 

ll L[100007][2]; 
bool overlap(int x1,int y1,int x2 , int y2){
   // //cout << p1.xx << sp << p1.yy << sp << sp << p2.xx << sp << p2.yy << el ; 
    if (y1 <= x2 || x1 >= y2){
        return false ; 
    }
    return true ; 
}
ll solve(vp& v , int n) {
    
    L[0][1] = 1 ; L[0][0] = 0 ; 
    vi entime ; 
    entime.pb(v[0].xx) ; 
    for(int i = 1 ; i < n ; i++){
        L[i][0] = L[i-1][0] + L[i-1][1] ; 
        L[i][0] %= MOD ; 
        if (v[i].yy < entime[0]){
            L[i][1] = 1 ; 
        }
        else {
            vi :: iterator it = upper_bound(all(entime),v[i].yy) ; 
            int diff = it - entime.begin() ; diff-- ; 
            L[i][1] = 1+L[diff][0] + L[diff][1] ; 
            L[i][1]%= MOD ; 
        }
        entime.pb(v[i].xx) ;
         
        
    }
    return  (L[n-1][0]+L[n-1][1])%MOD ; 
    
    
}


int main(){
    int n ; sci(n) ; 
    while (n != -1){
        vp v(n) ; 

        int a , b ; 
        forn(i,n){
            sci(a) ; sci(b) ; 
            v[i] = mp(b,a) ;  
        }
        sort(all(v)) ; 
        
        memset(L,0,sizeof(L)) ; 
        ll ans = solve(v,n) ; 
        //cout << "reach" << el ; 
        int nd = 0 ; 
        ll res = ans ; 
        while(res!=0) {
            res/=10 ; nd++ ; 
        }
        forn(i,8-nd) cout <<'0' ; 
        cout << ans << el ;
        sci(n) ; 
        
    }
    return 0  ;
}