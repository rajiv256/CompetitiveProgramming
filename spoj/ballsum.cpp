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

ll gcd(ll a , ll b ){
    if (a < b){
        return gcd(b,a) ; 
    }
    if (b == 0){
        return a ; 
    }
    return gcd(b,a%b) ; 
}

int main(){
    ll n , k ; 
    while (true){
        cin >> n >> k ;  
        if (n == -1 && k == -1){
            break ;
        }
        if (n < 2 || k > n){
            cout << "0" << el ; 
            continue ; 
        }
        ll sum = 0 ; 
        ll red = 2 ; 
        while (k-red > 0){
            sum += k-red ; 
            red += 2 ; 
        }
        ll temp = gcd(sum,(n*(n-1))/2) ; 
        ll p = (sum)/temp ; 
        ll q = ((n*(n-1))/2)/temp ;
        if (p == 0){
            cout <<"0" << el ;
            continue ;  
        }
        if (p == 1 && q == 1){
            cout << "1" << el ; 
            continue ; 
        }
        
        cout << p <<"/" << q << el;
    }
    return 0 ; 
}