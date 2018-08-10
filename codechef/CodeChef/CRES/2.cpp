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
     
    int t ; sci(t) ; 
    string s ;
    while (t--){
        vi v(2,0) ;  
        //cin >> s; 
        s = "" ;  
        int temp = gc() ; 
        while (!(((temp>='a') && (temp<='z'))||((temp >='A')&&(temp <='Z')))){
            temp = gc() ;
        }
        while (((temp>='a') && (temp<='z'))||((temp >='A')&&(temp <='Z'))){
           s += temp ; 
           temp = gc() ;  
        }
        vi sm(26,0) ; 
        vi bg(26,0) ; 
        forn(i,s.size()){
            if (s[i] >= 65 && s[i] <= 90){
                bg[s[i]-65] += 1 ; 
            }
            if (s[i] >= 97 && s[i]<= 122){
                sm[s[i]-97] += 1 ; 
            }
        }
        int fl = 0 ; 
        for(int i = 0 ; i < 26 ; i++){
            if (sm[i] != 0){
                if ((sm[i]&1) != (i&1)){
                    cout << "@0" << el ; 
                    fl = 1 ; 
                    break ; 
                }
            }
            if (bg[i] != 0){
                if ((bg[i]&1) != (i&1)){
                    cout << "@0" << el ;
                    fl = 1 ; 
                    break ;  
                }
            }
            
        }
        if (fl == 0){
            cout << "@1" << el ; 
            continue ; 
        }
    }
    
    return 0 ; 
} 