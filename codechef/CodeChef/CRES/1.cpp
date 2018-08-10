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

int main(){
    int  t ; sci(t) ; 
    while (t--){
        int n ; sci(n) ; 
        vi v(n) ; 
        forn(i,n){
            sci(v[i]) ; 
        }
        int s ; sci(s) ; 
        sort(all(v)) ;
        int sum = 0 ; ll count = 0 ; 
        for(int i = 0 ; i < n ; i++){
            sum = v[i] ; 
            if (sum >= s){
                continue ; 
            }
            for(int j = i+1 ; j < n ; j++){
                sum += v[j] ; 
                if (sum >= s){
                    break ; 
                } 
                for(int k = j+1 ; k < n ; k++){
                    if (sum + v[k] < s){
                        //cout << i << sp << j << sp << k << el ;     
                        count++ ; 
                    }
                    else{
                        break ; 
                    }
                }
            }
        }
        cout << count << el ;  
        
    }
    return 0 ; 
}