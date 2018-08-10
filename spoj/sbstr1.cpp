#include <iostream>
#include <cmath>
#include <cstring> 

using namespace std ; 
int main(){
    for(int i = 0 ; i < 24 ; i++){
    string s1 ; string s2 ; cin >> s1 >> s2 ; 
    int found = s1.find(s2) ; 
    if (found == string::npos){
          cout << "0\n"  ; 
           continue ;   
    }
    else{
        cout << "1\n"  ; 
        continue ; 
    }
    }
    return 0 ; 
}