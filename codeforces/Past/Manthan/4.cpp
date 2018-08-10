
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

ll a[1009] ; 

int main(){
    int n ; sci(n) ; 
    memset(a,0,sizeof(a)) ; 
    forn(i,n){
        cin >> a[i] ; 
        a[i] += 1000000003 ;  
    }
    
    sort(a,a+n) ; 
    int fst = -1 ; int sec = -1 ; 
    int count = INT_MIN ; 
    forn(i,n-1){
        for(int j = i+1; j < n ; j++){
            fst = i ; sec = j ; 
            int curr = j+1 ; 
            int scnt = 2 ; 
            while (curr < n){
                cout << a[curr] << sp << a[fst] << sp << a[sec] << el ; 
                if (a[curr] == a[fst]+a[sec]){
                    scnt++ ; 
                    cout << scnt << el ;
                    fst = sec ; sec = curr ; 
                    curr++ ;  
                }
                else{
                    curr++ ; 
                }
            }
            count = max(count,scnt) ; 
        }
    }
    cout << count << el ; 
    return 0 ; 
}