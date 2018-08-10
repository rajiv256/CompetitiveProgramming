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
    int n , m ; 
    sci(n) ; sci(m) ; 
    vector<pair<char,int> > v1 ; 
    vector<pair<char,int> > v2 ; 
    char c1 , c2 , c3 ; 
    int nd = n ; int md = m ;
    char prev = '@' ;  
    string s; 
    while (nd--){
        cin >> s ; 
        int res1 = 0, res2 = 0;
        int it = 0 ; 
        while(s[it]!='-'){
            res1 *= 10 ; 
            res1 += s[it]-'0' ; 
            it++ ; 
        }    
        it++ ; 
        c3 = s[s.size()-1] ; 
        if (prev != c3){
            v1.pb(mp(c3,res1)) ; 
            prev = c3 ;    
        } 
        else {
            v1[v1.size()-1].yy += res1 ;  
        }
         
    }
   
    int fl = 0 ; 
    prev = '@' ; 
    while (md--){
        cin >> s ; 
        int res1 = 0, res2 = 0;
        int it = 0 ; 
        while(s[it]!='-'){
            res1 *= 10 ; 
            res1 += s[it]-'0' ; 
            it++ ; 
        }    
        c3 = s[s.size()-1] ; 
        if (prev != c3){
            v2.pb(mp(c3,res1)) ; 
            prev = c3 ;    
        } 
        else {
            v2[v2.size()-1].yy += res1 ;  
        }
    }
    //cout << "came here" << el  ;
    ll ans = 0  ; 
    if (m == 1){
        for(int i = 0 ; i < n ; i++){
            //cout << v1[i].xx << " ## " << v2[0].xx << el ; 
            if (v1[i].xx == v2[0].xx){
                if (v1[i].yy >= v2[0].yy){
                    //cout << v1[i].yy << sp << v2[0].yy << el ; 
                    ans += (ll)v1[i].yy-(ll)v2[0].yy +1 ; 
                }
            }
        }
        cout << ans << el ; 
        return 0 ; 
    }
    for (int i = 0 ; i < n ; ){
        
        //cout << i << el ;  
        if (v1[i].xx != v2[0].xx){
            i++ ; 
            continue ; 
        }
        
        if (v1[i].yy < v2[0].yy){
            i++ ;
            continue ; 
        }
        else {
            int j = 1 ;  
            fl = 0 ;
            while (j < m-1){
            if (v1[i+j].xx != v2[j].xx){
                    fl = 1 ; 
                    break ; 
                }
                if (v1[i+j].yy != v2[j].yy){
                    fl = 1 ; 
                    break ;  
                }
                j++ ; 
                    
            }
            if (fl == 1){
                i++ ;
                continue ; 
            }
            if (v1[i+m-1].yy >= v2[m-1].yy){
                ans += 1 ; 
                i++ ; 
                continue ; 
            }
            i++ ; 
            
        }
    }
    cout << ans << el ; 
}
