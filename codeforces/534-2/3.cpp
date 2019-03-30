
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
vector<PII > hs, vs ;

void consolidate(){
    vector<int> cols ;
    vector<int> rows ;
    for(int i = 0 ; i < 4 ; i++){
        int cr = 0 ;
        for(int j = 0 ; j < 4 ; j++){
            cr += grid[i][j] ;
        }
        if (cr == 4) rows.pb(i) ;
    }
    for(int i = 0 ; i < 4 ; i++){
        int cc = 0 ;
        for(int j = 0 ; j < 4 ; j++){
            cc += grid[j][i] ;
        }
        if (cc == 4) cols.pb(i) ;
    }

    for(auto it : rows){
        for (int j = 0 ; j < 4 ; j++){
            grid[it][j] = 0 ;
        }
    }
    for(auto it : cols){
        for(int j = 0 ; j < 4 ; j++){
            grid[j][it] = 0 ;
        }
    }

}
void init(){
    int x = 0 , y = 0 ;
    hs.pb(mp(0,0)) ; hs.pb(mp(1,0)) ; hs.pb(mp(2, 0)) ; hs.pb(mp(3,0)) ;
    x = 0 , y = 2;
    vs.pb(mp(0,2)) ; vs.pb(mp(2,2)) ; vs.pb(mp(0,3)) ; vs.pb(mp(2,3)) ;
}
int find_row(){
    for(int i = 0 ; i < 4 ; i++){
        int r = hs[i].xx ; int c = hs[i].yy ;
        if (grid[r][c] == 0) return i ;
    }
    return 0 ;
}
int find_col(){
    for(int i = 0 ; i < 4 ; i++){
        int r = vs[i].xx ; int c = vs[i].yy ;
        if (grid[r][c] == 0) return i ;
    }
}
void fill_h(int i){
    int r = hs[i].xx ; int c = hs[i].yy ;
    grid[r][c] = 1 ; grid[r][c+1] = 1 ;
}
void fill_v(int i){
    int r = vs[i].xx ; int c = vs[i].yy ;
    grid[r][c] = 1 ; grid[r+1][c] = 1 ;
}


int main(){
    memset(grid, 0, sizeof grid) ;
    init() ;
    string s ; cin >> s ;
    for(int i = 0 ; i < s.size() ; i++){

        if (s[i] == '1'){
            consolidate() ;
            int x = find_row() ;
            fill_h(x) ;
            cout << hs[x].xx+1 << sp << hs[x].yy + 1 << el ;
        }
        else{
            consolidate() ;
            int x = find_col() ;
            fill_v(x) ;
            cout << vs[x].xx+1 << sp << vs[x].yy+1 << el ;
        }

    }
    return 0 ;
}
