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



string revstr(string s){
    string rev = "" ; 
    forn(i,3){
        rev+=s[3-i-1] ; 
    }
    return rev ; 
}


vi reverse(vi& a){
    vi rev(3) ; 
    forn(i,3){
        rev[i] = a[3-i-1] ; 
    }
    return rev ; 
}
vi numtoarr(int num){
    vi a(3) ; 
    forn(i,3){
        a[3-i-1] = num%10 ; 
        num /= 10 ; 
    }
    return a ; 
}
int arrtonum(vi& a){
    int num = 0 ; 
    forn(i,3){
        
        num *= 10 ; 
        num += a[i] ; 
        
        
    }
    return num ; 
}
string arrtostr(vi& a){
    string s = "" ;     
    forn(i,3){
        s += a[i]+'0' ; 
    }
    return s ; 
}

string numtostr(int num){
    vi a(3) ; 
    a = numtoarr(num) ; 
    string s = "" ; 
    s = arrtostr(a) ; 
    return s ; 
    
}


int abs(int a){
    if (a > 0 ){
        return a ; 
    }
    return -a ; 
}
int strtonum(string s){
    int num = 0 ; 
    forn(i,3){
        num *= 10 ;
        num += s[i]-'0' ; 
    }
    return num ; 
}

string ops(string s){
     int num = strtonum(s) ; 
     int rnum = strtonum(revstr(s)) ;
     int x = abs(num-rnum) ; 
     
     vi v = numtoarr(x) ;
     vi re = reverse(v);
     
     int y = arrtonum(re) ; 
     int z = (x+y)%1000 ;
      
     vi a(3,0) ;  
     a = numtoarr(z) ; 
     string fin = arrtostr(a) ; 
     return fin ;    
}


int main(){
    int t ; scanf("%d",&t); 
    while (t--){
        int m ; scanf("%d",&m) ; 
        string s ; cin >> s ; 
        int rem = s.size()% 3 ; 
        forn(i,3-rem){
            s += '0' ; 
        }
        string ans = "" ; 
        for(int i = 0 ; i < s.size() ; i+=3){
            string pro = "" ; 
            pro += s[i] ; pro += s[i+1] ; pro += s[i+2] ; 
            string aa = "" ; 
            forn(i,m){
                aa = ops(pro) ;
            }
            ans += aa ; 
        }
        cout << ans << el ; 
    }
    return 0 ; 
}