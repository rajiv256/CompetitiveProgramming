// There is a small error somewhere. Couldn't find it out. :( 
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

int a[100009] ; 

void update(set<int>&s , int pos, int col){
    if (a[pos]== col){
        return ; 
    }
    if (pos == 1){
        if (a[pos] == a[pos+1]){
            s.insert(2) ; a[pos] = col ; return ; 
        }
        else{
            if (col == a[pos+1]){
                s.insert(1) ; s.erase(2) ; a[pos] = col ; return ; 
            }
        }
    }
    if (a[pos-1] == a[pos+1]){
        if (a[pos]==a[pos+1]){
            s.insert(pos) ; s.insert(pos+1) ; a[pos] = col ; return ; 
        }
        if (a[pos]!=a[pos+1]){
            
            if (col == a[pos+1]){
                s.erase(pos) ; s.erase(pos+1) ; a[pos] = col ; return ; 
            }
            
        }
    }
    else {
        if (a[pos]==a[pos+1]){
            if (col != a[pos-1]){
                s.insert(pos) ; s.insert(pos+1) ; a[pos] = col ; return ; 
            }
            if (col == a[pos-1]){
                s.insert(pos+1) ;s.erase(pos) ; a[pos] = col ; return ;  
            }
        }
        if (a[pos] == a[pos-1]){
            if (col == a[pos+1]){
                s.insert(pos) ; s.erase(pos+1) ; a[pos] = col ; return ; 
            }
            else{
                s.insert(pos) ; s.insert(pos+1) ; a[pos] = col ; return ; 
            }
        }
        if ((a[pos]!= a[pos-1]) && (a[pos]!= a[pos+1])){
            if (col == a[pos-1]){
                s.erase(pos) ; s.insert(pos+1) ; a[pos] = col ; return ; 
            }
            if (col == a[pos+1]){
                s.erase(pos+1) ; s.insert(pos) ; a[pos] = col ; return ; 
            }
        }
    }
}




int main(){
    int t ; cin >> t ; 
    while (t--){
        memset(a,0,sizeof(a)) ; 
        int n , w ; sci(n) ; sci(w) ; 
        for(int i = 1 ; i <= n ; i++){
            sci(a[i]) ; 
        }
        //int q ; sci(q) ; 
        set<int> s ; s.insert(1) ; 
        int now = a[1] ; int it = 2 ; 
        while (it <= n){
            if (a[it] != now){
                now = a[it] ; s.insert(it) ; it++ ; 
                continue ; 
            }
            it++ ; continue ; 
        }
        int q ; sci(q) ;  int x , y ; 
        vi v;  
        while (q--){
            sci(x) ; sci(y) ; int sum = 0 ; 
            v.clear() ;
            update(s,x,y) ;  s.insert(n+1) ; 
            for(set<int>:: iterator it = s.begin() ; it != s.end() ; it++){
                v.pb(*it) ; 
            }  
            for(int i = 0 ; i < v.size()-1 ; i++){
                int diff = v[i+1]-v[i] ; 
                 
                sum += max(diff-w+1,0) ; 
            }             
            cout << sum << el ; 
        }
         
    }
    return 0 ; 
}