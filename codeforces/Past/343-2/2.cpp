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
    int n ; cin >> n ; 
    vp f ; vp m ; 
    char c ; int a , b ; 
    forn(i,n){
        cin >> c ; cin >> a >> b ; 
        if (c == 'F'){
            f.pb(mp(a,b)) ; 
        }
        else{
            m.pb(mp(a,b)) ; 
        }
    }
    int maxi = INT_MIN ; 
    for(int d = 1 ; d <= 366 ; d++){
        int nm = 0 ; int nw = 0 ; 
        for(int i = 0 ; i < m.size() ; i++){
            if (d >= m[i].xx && d <= m[i].yy){
                nm++ ; 
            }
        }
        for(int i = 0 ; i < f.size() ; i++){
            if (d >= f[i].xx && d <= f[i].yy){
                nw++ ; 
            }
        }
        maxi = max(min(nm,nw),maxi) ;  
    }
    cout << maxi*2 << el ; 
    return 0 ; 
    
}