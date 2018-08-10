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

int a[1000003] ; 
int fl = 0 ;

void fill(string s){
    for(int i = 0 ; i < s.size() ; i++){
        a[i+1] = s[i]-'0' ; 
    }
    return ; 
}

void adjust(int n) {
    int carry = 0 ; 
    a[n] += 1 ; 
    carry = a[n]/10 ; 
    a[n] = a[n]%10 ; 
    int idx = n-1 ; 
    while (carry != 0 && idx >= 0){
        a[idx] += carry ; 
        carry = a[idx]/10 ; 
        a[idx] %= 10 ; 
        idx-= 1; 
        
    }
    return ; 
}

void process(int st , int en){
    if (st == en){
        if (!fl){
            //a[st] += 1 ; 
            return ; 
        }
    }
    if (st > en ){
        return ; 
    }
    if (a[st] == a[en]){
        process(st+1,en-1) ; 
        return ; 
    }
    if (a[st] > a[en]){
        a[en] = a[st] ;
        process(st+1,en-1) ; 
        return ; 
    }
    if (a[st] < a[en]){
        a[en] = a[st] ; 
        a[en-1] += 1 ; 
        int carry = a[en-1]/10 ; 
        a[en-1] %= 10 ; 
        int idx = en-2 ; 
        while (idx >= 0 && carry != 0){
            a[idx] += carry ; 
            carry = a[idx]/10 ; 
            a[idx] %= 10 ; 
            idx -= 1; 
        } 
        process(st,en) ; 
        return ; 
        
    }
    return ; 
}

void print(int st , int en){
    for(int i = st ; i <= en ; i++){
        printf("%d",a[i]) ; 
    }
    cout << endl ; 
    return ; 
}
int main(){
    int t ; sci(t) ; 
    while (t--){
        memset(a,0,sizeof(a)) ; 
        string s ; cin >> s; 
        
        fill(s) ; 
        int n = s.size() ; 
        adjust(n) ; 
        //print (1,n) ; 
        if (a[0] == 0){
            process(1,n) ; 
            print(1,n) ; 
        } 
        else{
            process(0,n) ;
            print(0,n) ;  
        }
        
       
    }
}