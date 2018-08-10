#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std; 

#define forn(i,n) for(int i = 0 ; i < n ; i++)


int gcd(int a , int b) {
    if (b == 0){
        return a ; 
    }
    if (b > a){
        return gcd(b,a) ; 
    }
    if (a == b){
        return a ; 
    }
    return gcd(b,a%b) ; 
}


int main() {
    int t ; cin >> t ; 
    while (t--){
        int n ; cin >> n ; 
        vector<int> v ; v.resize(n) ; 
        forn(i,n){
            cin >> v[i] ; 
        }
        int res = v[0] ; 
        for (int i = 1 ; i < n ; i++){
            res = gcd(res,v[i]) ; 
            if (res == 1) 
                break ;
        }
        cout << n*res << endl ; 
    }
}
