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
    int n , m , k ; 
    sci(n) ; sci(m) ; sci(k) ;
    vi v(2,-1) ;  
    map<int,vector<int> > r ; 
    map<int,vector<int> > c ;
    forn(i,n){
        r[i+1].pb(-1) ; 
        r[i+1].pb(-1) ; 
    } 
    forn(j,m){
        c[j+1].pb(-1) ;
        c[j+1].pb(-1) ;
    }
    int q = 0 ; int aa , b , kase;  
    while (k--){
        cin >> kase >> aa >> b ; 
        if (kase == 1){
            r[aa][0] = q ;  
            r[aa][1] = b ;  
        }
        else{
            c[aa][0] = q ; 
            c[aa][1] = b ;   
        }
        q++ ; 
    }
    int a[n+1][m+1] ;
    memset(a,0,sizeof(a)) ;  
    forn(i,n){
        forn(j,m){
            //cout << i << sp << j << el; 
            if ((r[i+1][0]== -1) && c[j+1][0] == -1){
                continue ; 
            }
            else if (r[i+1][0] == -1 && c[j+1][0]!= -1){
                a[i][j] = c[j+1][1] ; 
            }
            else if (r[i+1][0] != -1 && c[j+1][0] == -1){
                a[i][j] = r[i+1][1] ; 
            }
            else if (r[i+1][0] != -1 && c[j+1][0] != -1){
                if (r[i+1][0] < c[j+1][0]){
                    a[i][j] = c[j+1][1] ; 
                }
                else{
                    a[i][j] = r[i+1][1] ; 
                }
            }
        }
    }
    forn(i,n){
        forn(j,m){
            cout << a[i][j] << sp ; 
        }
        cout << el ; 
    }
}