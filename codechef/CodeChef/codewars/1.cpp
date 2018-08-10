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

int L[13][100000] ; 

int dp(int a[] , int idx , int sum , int n){
    //cout << idx << sp << sum << el ; 
    if (sum < 0){
        return 0 ; 
    }
    if (idx == n && sum == 0){
        return  1 ; 
    } 
    if (idx == n && sum != 0){
        return 0 ; 
    } 
    if (L[idx][sum] != -1){
        return L[idx][sum] ; 
    }
    else{
        int ans = 0 ; 
        for(int i = 0 ; i <= sum/a[idx] ; i++){
            L[idx+1][sum-i*a[idx]] = dp(a,idx+1,sum-i*a[idx],n) ;
            ans += L[idx+1][sum-i*a[idx]] ; 
        }
        return ans ; 
             
    }
    return 0 ; 
    
    
}
int main(){
    int n ; cin >> n ; 
    int a[n] ; 
    memset(L,-1,sizeof(L)) ; 
    
    forn(i,n){
        sci(a[i]) ; 
    }
    int sum ; sci(sum) ;
    int ans = dp(a,0,sum,n) ; 
    if (ans == 0){
        cout << "0\n" ; 
        return 0 ; 
    }
    cout << ans << el ; 
    return 0 ; 
}