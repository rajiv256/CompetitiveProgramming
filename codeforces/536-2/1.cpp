
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <sys/time.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <cmath>

using namespace std ;
char a[503][503] ;
bool valid(int x , int y, int n){
    if (x < 0 || y < 0 || x >= n || y >= n) return  false ;
    return true ;
}
bool cross(int x, int y, int n){
    int val = valid(x+1, y+1, n) + valid(x+1, y-1, n) + valid(x-1, y-1, n) + valid(x-1,y+1,n) ;
    if (val != 4){
        return 0 ;
    }
    int xs = 0 ;
    xs = (a[x][y]=='X')+(a[x+1][y+1]=='X')+(a[x-1][y+1]=='X')+(a[x+1][y-1]=='X')+(a[x-1][y-1]=='X') ; 
    return (xs==5)?true:false ;
}
int main(){
    int n ; cin >> n ;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> a[i][j] ;
        }
    }
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            ans += cross(i, j, n) ;
        }
    }
    cout << ans << endl ;
    return 0 ;



}
