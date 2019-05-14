#include <iostream>
using namespace std;

string rep(char c, int x){
    string ret = "" ; 
    for(int i = 0 ; i < x ; i++){
        ret += c ; 
    }
    return ret ; 
}
int main() {
    int n , k ; cin >> n >> k ; 
    if (n == k){
        string ans = "" ; 
        for(int i = 0 ; i < n ; i++){
            ans += "0" ; 
        }
        cout << ans << endl ;
        return 0 ; 
    }
    else if (k == 1){
        string ans = "1" + rep('0',n-1) ; 
        cout << ans << endl ; 
        return 0 ; 
    }
    else{
       int diff = n-k ; 
       string repl = "1" + rep('0', diff/2) ;
       string ans = "" ; 
       while (true){
           if (ans.size() + repl.size() > n){
               break ; 
           }
           ans += repl ; 
       }
       int rem = n-ans.size() ; 
       for(int i = 0 ; i < rem ; i++){
           ans += repl[i] ; 
       }
    
       cout << ans << endl ; 
    }
    return 0 ; 
}
