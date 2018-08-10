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

int a[26] ; 
string s1 ; 
string s2 ; 
string str ;


bool check(string ss){
    string s1 = "" ;
    forn(i,ss.size()/2){
        s1 += ss[i] ; 
    } 
    int found = ss.find(s1) ; 
    found = ss.find(s1,found+1) ; 
    if (found != ss.size()/2){
        return false ;
    }
    return true  ; 
} 
int main(){
    int t ; 
    cin >> t ; 
    while (t--){
        string s; cin >> s ; 
        int n = s.size() ; 
        if (n == 1){
            cout << "NO" << el ; 
            continue ; 
        }
        if (n%2==0){
            if (check(s)){
                cout << "YES" << el ; 
                continue ; 
            }
            else {
                cout << "NO" << el ; 
                continue ; 
            }
        }
        else{
            int fl2 = 1 ; 
            memset(a,0,sizeof(a)) ; 
            forn(i,n){
                a[s[i]-'a'] += 1 ;
            }
            
            int num = 0 ; int ch ; 
            forn(i,26){
                //cout << el << a[i] << sp ; 
                if (a[i]&1){
                    num++ ; 
                    ch = i ; 
                }
            }
            //cout << num << el ; 
            if (num > 1){
                cout << "NO" << el ; 
                continue ; 
            }
            vi pos ; 
            forn(i,n){
                if ((s[i]-'a') == ch){
                    pos.pb(i) ; 
                }
            }
                
            str.clear() ; 
            int fl = 0 , nfl = 0 ; 
            for(int i = 0 ; i < pos.size() ; i++){
                str.clear() ;   
                forn(j,n){
                    if (j != pos[i]){
                        str += s[j] ; 
                    }
                }
                if (check(str)){
                    cout << "YES" << el ; 
                    fl = 1 ; 
                    break ;  
                }
                
            }
            if (fl == 1)
                continue ;  
            else{
                cout << "NO" << el ; 
                continue ;   
            }
        }
    } 
    return 0 ; 
}