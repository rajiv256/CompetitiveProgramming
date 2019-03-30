/*
	Resilience is the greatest of all virtues.
	Code by rajiv
*/
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
#define CASET  int t;cin>>t;while(t--)
#define forn(i,x,y) for(int i=x;i<y;i++)
#define maxn 100005
#define inf 10000000010
#define mod 1000000007
#define last_set_bit(x) log2((x)&(-x))
#define add(x,y) (x)=((x)+(y))%MOD
#define PI 3.141592653589793

typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

ll n , m ; ll a[1002][1002] ;
ll b[1002][1002] ;

ll solve(int x, int y, int n , int m){
    ll ans = m+n ;
    memset(b,0,sizeof b) ;
    b[x][y] = m+n ;
    for(int col = y+1 ; col < m ; col++){
        if (a[x][col] < a[x][col-1]){
            b[x][col] = b[x][col-1]-1 ;
        }
        if (a[x][col] > a[x][col-1]){
            b[x][col] = b[x][col-1]+1 ;
        }
        if (a[x][col] == a[x][col-1]){
            b[x][col] = b[x][col-1] ;
        }
    }
    for(int col = y-1 ; col >= 0 ; col--){
        if (a[x][col] < a[x][col+1]){
            b[x][col] = b[x][col+1]-1 ;
        }
        if (a[x][col] > a[x][col+1]){
            b[x][col] = b[x][col+1]+1 ;
        }
        if (a[x][col] == a[x][col+1]){
            b[x][col] = b[x][col+1] ;
        }
    }
    for(int row = x+1 ; row < n ; row++){
        if (a[row][y] < a[row-1][y]){
            b[row][y] = b[row-1][y]-1 ;
        }
        if (a[row][y] > a[row-1][y]){
            b[row][y] = b[row-1][y]+1 ;
        }
        if (a[row][y] == a[row-1][y]){
            b[row][y] = b[row-1][y] ;
        }
    }
    for(int row = x-1 ; row>=0 ; row--){
        if (a[row][y] < a[row+1][y]){
            b[row][y] = b[row+1][y] - 1 ;
        }
        if (a[row][y] > a[row+1][y]){
            b[row][y] = b[row+1][y] + 1 ;
        }
        if (a[row][y] == a[row+1][y]){
            b[row][y] = b[row+1][y] ;
        }
    }
    ll mini = 1e10+1 ;
    for(int i = 0 ; i < m ; i++){
        mini = min(mini, b[x][i]) ;
    }
    for(int i = 0 ; i < n ; i++){
        mini = min(mini, b[i][y]) ;
    }

     mini-- ;
    for(int i = 0 ; i < m ; i++){
        b[x][i] -= mini ;
    }
    for(int i = 0 ; i < n ; i++){
        if (i != x)
        b[i][y] -= mini ;
    }


    ll maxi = b[x][y] ;
    for(int i = 0 ; i < m ; i++){
        maxi = max(b[x][i], maxi) ;
    }
    for(int i = 0 ; i < n ; i++){
        maxi = max(b[i][y], maxi) ;
    }
    return maxi ;

}



int main(){
    cin >> n >> m ;
    forn(i,0,n) forn(j,0,m) cin >> a[i][j] ;

    forn(i,0,n){
        forn(j,0,m){
            cout << solve(i,j,n,m) << sp ;
        }
        cout << el ;
    }
    return 0  ;

}






















//}
