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
    int n ; sci(n) ; 
    int m[1003][1003] ; 
    memset(m,0,sizeof(m)) ; 
    int x , y ; 
    forn(i,n){
        sci(x)  ;sci(y) ; 
        m[x][y] = 1 ; 
    }
    int cnt = 0 ; 
    x = 1 ; y = 1 ;
    int sc = 0 ; 
    while((x <= 1000) && (y<= 1000)){
    	if (m[x][y]){
    		sc++ ; 
    	}
    	x++ ; y++ ; 
    }
    cnt += (sc*(sc-1))/2 ; 
    for(int j = 2 ; j < 1000 ; j++){
    	x = 1 ; y = j ; 
    	int scnt = 0 ; 
    	while(y <= 1000){
    		if (m[x][y]){
    			scnt++  ;
    		}
    		x++ ; y++ ; 
    	}
    	cnt += (scnt*(scnt-1))/2  ; 
    }
    for(int j = 2 ; j < 1000 ; j++){
    	x = j ; y = 1 ; 
    	int scnt = 0 ; 
    	while (x <= 1000){
    		if (m[x][y]){
    			scnt++ ; 
    		}
    		x++ ; y++ ; 
    	}
    	cnt += (scnt*(scnt-1))/2 ; 
    }
    for(int j = 2 ; j < 1000 ; j++){
    	x =  j ; y = 1 ; 
    	int scnt = 0 ; 
    	while(x >= 1){
    		if (m[x][y]){
    			scnt++ ; 
    		}
    		x-- ; y++ ; 
    	}
    	cnt += (scnt*(scnt-1))/2 ; 
    }
    x = 1000 ; y = 1 ; 
    sc = 0 ; 
    while(x >= 1 && y <= 1000){
    	if (m[x][y]){
    		sc++ ; 
    	}
    	x-- ; y++ ; 
    }
    cnt += (sc*(sc-1))/2 ; 
    for(int j = 2 ; j < 1000 ; j++){
    	x = 1000 ; y = j ; 
    	int scnt = 0  ; 
    	while(y <= 1000){
    		if (m[x][y]){
    			scnt++ ; 
    		}
    		x-- ; y++ ; 
    	}
    	cnt += (scnt*(scnt-1))/2 ; 
    }
    cout << cnt << el ; 
    return 0 ; 
}