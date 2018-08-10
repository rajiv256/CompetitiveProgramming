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
    int n ; cin >> n ; 
    string s ; cin >> s ; 
    int m ; cin >> m ; 
    vector<string> dic1(m) ; 
    
    forn(i,m){
        cin >> dic1[i] ; 
    }
    set<string> dicset(all(dic1)) ; 
    vector<string> dic ; 
    for(set<string>::iterator it = dicset.begin() ; it != dicset.end() ; it++){
        dic.pb(*it) ; 
    } 
    m = dic.size() ; 
    vector<string> orig(m) ; 
    forn(i,m){
        orig[i] = dic[i] ; 
        std:: transform(orig[i].begin(),orig[i].end(),orig[i].begin(),::tolower) ; 
    }
    forn(i,m){
        forn(j,dic[i].size()){
            orig[i][j] = tolower(dic[i][dic[i].size()-j-1]) ; 
        }
    }
    map<int,int> ma ; 
    forn(i,n){
        ma[i] = -1 ; 
    }
    forn(i,m){
        int found = s.find(orig[i]) ; 
        while (found != string::npos){
            if (ma[found] == -1)
                ma[found] = i ;
            else if (orig[ma[found]].size() < orig[i].size()){
                ma[found] = i ; 
            }
            found = s.find(orig[i],found+1) ;  
        }
    }
    int curr = 0 ; int prev = -100000 ; int prevsz = 0 ; 
    for(map<int,int>:: iterator it = ma.begin() ; it != ma.end() ; it++ ){
          curr = (*it).xx ; 
          if (curr >= prev+prevsz){
              cout << dic[(*it).yy] << sp ; 
              prevsz = dic[(*it).yy].size() ; 
              prev = curr ; 
          }
         
    }
    return 0 ; 
    
}