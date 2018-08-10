#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    
    if (a+b+c == 42){
        cout << a <<'+'<<b<<'+'<<c << "\n" ; 
        return 0 ; 
    }
    if (a+(b*c) == 42){
        cout << a <<'+'<<b<<'*'<<c << "\n" ; 
        return 0 ; 
    }
    if ((a*b)+c == 42){
        cout << a <<'*'<<b<<'+'<<c << "\n" ; 
        return 0 ; 
    }
    if (a*b*c == 42){
        cout << a <<'*'<<b<<'*'<<c << "\n" ; 
        return 0 ; 
    }
    
    
    cout << "This is not the ultimate question\n" ; 
    
    return 0;
}
