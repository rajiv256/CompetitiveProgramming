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

string t1 ; string t2 ; string t3 ;
 string res = "" ; 
 stack<string> st ;
string parse(string s){
    while (st.size()!= 0){
        st.pop() ; 
    } 
    int idx = 0 ; 
    while (idx < s.size()){
        if (s[idx] == ')'){
            
            t3 = st.top() ; st.pop() ; 
            t2 = st.top() ; st.pop() ; 
            t1 = st.top() ; st.pop() ; 
            st.pop() ; 
            res = "" ; res += t1 ; res += t3 ; res += t2 ; 
            st.push(res) ; 
            idx++ ; 
            continue ;  
        }
        else {
            string r(1,s[idx]) ; 
            st.push(r) ; 
            idx++ ; 
            continue ; 
        }
    }
    return st.top() ; 
}



int main(){
    
    int t ; sci(t) ;  
    while (t--){
        string s ; cin >> s ; 
        string ans = parse(s) ;
        cout << ans << el ;     
    }
     return 0 ; 
    
}