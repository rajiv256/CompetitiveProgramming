#include <bits/stdc++.h>

using namespace std ; 

#define ll long long 
#define sp " " 
#define el endl 
#define sci(x) scanf("%d",&x)
#define MAXN 100009 
#define MOD 1000000007
#define forn(i,n) for(int i=0;i<n;i++)

int main(){
    int t ; sci(t) ; 
    while (t--){
        int n ; sci(n) ; 
        string s ; cin >> s ; 
        int r = 0 , g = 0  , b = 0 ;
        forn(i,n){
            if (s[i] == 'R') r++ ; 
            if (s[i] == 'G') g++ ; 
            if (s[i] == 'B') b++ ; 
        } 
        int maxi = max(r,max(g,b)) ; 
        cout << n-maxi << el ; 
    }
    return 0 ; 
}