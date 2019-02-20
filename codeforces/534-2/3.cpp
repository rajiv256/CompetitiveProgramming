
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

#define xx first
#define yy second
#define ll long long
#define ld long double
#define el (char)0x0A
#define sp " "
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define clr(x) memset((x),0,sizeof(x))
#define uint unsigned int
#define abs(x) ((x<=0)?(-x):(x))
#define CASET  int t;cin>>t;while(t--)
#define FORN(i,x,y) for(int i=x;i<y;i++)
#define MAXN 100005
#define INF 10000000010
#define MOD 1000000007
#define last_set_bit(x) log2((x)&(-x))
#define add(x,y) (x)=((x)+(y))%MOD
#define pi 3.141592653589793
#define PII pair<int,int>

int grid[4][4] ;

void clear_row(int idx ){
    for(int i = 0 ; i < 4 ; i++){
        grid[idx][i] = 0 ;
    }
}
void  clear_col(int idx){
    for(int i = 0 ; i < 4 ; i++){
        grid[i][idx] = 0 ;
    }
}

bool valid(int x, int y){
    if (x < 0 || y < 0 || x >= 4 || y >= 4) return false ;
    return true ;
}
pair<int,int> find(int tile){
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            if (grid[i][j] == 0){
                if (tile == 0){
                    if (valid(i+1,j) && grid[i+1][j] == 0){
                        return mp(i,j) ;
                    }
                }
                if (tile == 1){
                    if (valid(i, j+1) && grid[i][j+1] == 0){
                        return mp(i,j) ;
                    }
                }
            }
        }
    }
    return mp(-1,-1) ;
}
void check_and_clear(){
    vector<int> rs , cs ;
    for(int i = 0 ; i < 4 ; i++){
        int nzr = 0 , nzs = 0  ;
        for(int j = 0 ; j < 4 ; j++){
            nzr += (grid[i][j] != 0) ;
            nzs += (grid[j][i] != 0) ;
        }
        if (nzr == 4){
            rs.pb(i) ;
        }
        if (nzs == 4){
            cs.pb(i) ;
        }
    }
    for(auto it : rs){
        clear_row(it) ;
    }
    for(auto it : cs){
        clear_col(it) ;
    }

}

int main(){
    string s ; cin >> s ;
    vector<pair<int,int> > v ;
    memset(grid, 0 , sizeof grid) ;
    int r , c ;
    for(int i = 0 ; i < s.size() ; i++){
        check_and_clear() ;
        if (s[i] == '0'){
            PII p = find(0) ;
            r = p.xx ; c = p.yy ;
            grid[r][c] = 1 ;
            grid[r+1][c] = 1 ;
            v.pb(mp(r+1,c+1)) ;
            continue ;
        }
        if (s[i] == '1'){
            PII p = find(1) ;
            r = p.xx ; c = p.yy ;
            grid[r][c] = 1 ;
            grid[r][c+1] = 1 ;
            v.pb(mp(r+1,c+1)) ;
            continue ; 
        }

    }
    for(auto it : v){

        cout << it.xx << sp << it.yy << el ;
    }
    return 0 ;
}
