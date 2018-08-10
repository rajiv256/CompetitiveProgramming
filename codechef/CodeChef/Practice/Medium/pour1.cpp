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
#define sii set<pair<int,int> >  
#define INF 1000000
#define sp " " 
#define el "\n"
#define lld long long int 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
#define pb push_back
#define sci(x) scanf("%d",&x)

int main(){
    int t ; sci(t) ; 
    while (t--){
        int a , b, c ; 
        sci(a) ; sci(b) ; sci(c) ; 
        int steps = INT_MAX ; 
        
        
        int f = max(a,b) ; int s = min(a,b) ; 
        if (c == 0){
            steps = 0 ; 
        }
        if (s == 0){
            if (f == c){
                steps = 1 ;
                cout << steps << el ;
                continue ;  
            }
            else{
                steps = -1 ;
                cout << steps << el; 
                continue ;  
            }
        }
        if (f == 0){
            steps = -1 ; 
        }
        if (c > f){
            steps = -1 ; 
            printf("%d\n",steps) ; 
            continue ; 
        }
        if ((f == c) || (s == c)){
            steps = 1 ; 
            printf("%d\n",steps) ; 
            continue ; 
        }
        if (c < s){
            if ((f-c)%s == 0){
                steps = min(steps,((f-c)/s)*2) ; 
            }
            
        }
        if ((c>s)&&(c<f)){
            
            if((f-c)%s == 0){
                steps = min(steps,2*((f-c)/s)) ; 
            }
        }
        if (steps == INT_MAX){
            steps = -1 ; 
        }
        printf("%d\n",steps) ; 
        
    }
    return 0 ; 
}