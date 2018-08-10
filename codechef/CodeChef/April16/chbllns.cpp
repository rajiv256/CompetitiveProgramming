#include <bits/stdc++.h>

using namespace std ; 

#define ll long long 
#define sp " " 
#define el endl 
#define sci(x) scanf("%d",&x)
#define MAXN 100009 
#define MOD 1000000007
#define all(v) v.begin(),v.end()


int main(){
    int t; sci(t) ; 
    while (t--){
        vector<ll> v(3) ; 
        cin >> v[0] ; cin >> v[1] ; cin >> v[2] ; 
        ll k ; cin >> k ;  
        sort(all(v)) ; 
        ll ans = min(k-1,v[0])+min(k-1,v[1])+k ; 
        cout << ans << el ; 
    }
}