/*
*METHOD IS CORRECT... TAKE CARE OF IMPLEMENTATION.
*/




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
#define MOD 1000000007
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

ll fact(ll n){
    if (n == 0)
       return 1 ; 
    ll res = (fact(n-1))%MOD ; 
    return (n*res)%MOD ; 
}




int main(){
    int t ; sci(t) ;
    map<char,int> maintain_count ;  
    while (t--){
        string s ; cin >> s ; 
        forn(i,s.size()){
            maintain_count[s[i]] += 1 ; 
        }
        ll n  = s.size() ; 
        ll tot = fact(n) ;
        for (map<char,int>::iterator it = maintain_count.begin() ; it != maintain_count.end();it++){
            tot /= (*it).yy ; 
        }
         
        ll nops = (tot*tot)%MOD ; 
        for(map<char,int>::iterator it = maintain_count.begin() ; it != maintain_count.end() ; it++){
            
        }
    }
}