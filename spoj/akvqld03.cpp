//rajiv's code

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
typedef map<int,int> mii ; 
typedef map<int,vector<int> > miv ; 
typedef unsigned long long ull ; 


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pp pair<int,pair<int,int> >
#define pii pair<int,int> 
#define pic pair<int,char> 
#define sii set<pair<int,int> >  
#define MOD 100000000
#define sp " " 
#define el "\n"
#define ll long long int 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x) 

 
int BIT[1000003] ; 
int n , q ; 
ll ans = 0 ; 
void update(int idx , int val){
    while (idx <= n ){
        BIT[idx] += val ; 
        idx += (idx&(-idx)) ; 
    }
}

ll query(int idx) {
    ll res = 0 ; 
    while (idx > 0){
        res += BIT[idx] ; 
        idx -= (idx&(-idx)) ; 
    }
    return res ; 
}



int main(){
    
    memset(BIT,0,sizeof(BIT)) ; 
    sci(n) ; sci(q) ;
    while (q--){
        string s ; cin >> s ; 
        int a , b ; 
        if (s == "find"){
            cin >> a >> b ; 
            ans = query(b)-query(a-1) ; 
            cout << ans << el ; 
        } 
        if (s == "add"){
            cin >> a >> b ; 
            update(a,b) ; 
        }   
    }
    return 0 ; 
     
}