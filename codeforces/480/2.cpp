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
 #define abs(x) ((x<=0)?(-x):(x))
 #define CASET  int t;cin>>t;while(t--)
 #define FORN(i,x,y) for(int i=x;i<y;i++)
 #define MAXN 100005
 #define INF 10000000010
 #define MOD 1000000007
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD
 #define PI 3.141592653589793

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;
 int C[300][300] ;
 bool valid(int x, int y, int ex , int ey){
     if (x < 0 || y < 0 || x > ex || y > ey) return false ;
     return true ;
 }
 void init(){
     C[0][0] = 1 ;
     for(int n = 1 ; n < 250 ; n++){
         C[n][0] = 1 ;
         for(int r = 1 ; r <= n; r++){
             C[n][r] = C[n-1][r] + C[n-1][r-1] ;
         }
     }
 }
 int up(int x , int y, int cols){
     int sx = 3, sy = 0 , ex = 0, ey = cols-1 ;
     int m1 = sx-x+1 ; int n1 = y-sy+1 ;
     int m2 = x-ex+1 ; int n2 = ey-y+1 ;
     //cout << x << sp << y << sp << "up: " << m1 << sp << n1 << sp << m2 << sp << n2 << el ;
     return C[m1+n1][n1]*C[m2+n2][n2] ;
 }
 int down(int x, int y , int cols){
     int sx = 0 , sy = 0 , ex = 3 , ey = cols-1 ;
     int m1 = x-sx+1 ; int n1 = y-sy+1 ;
     int m2 = ex-x+1 ; int n2 = ey-y+1 ;
     ////cout << x << sp << y << sp << "do: " << m1 << sp << n1 << sp << m2 << sp << n2 << el ;
     return C[m1+n1][n1]*C[m2+n2][n2] ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    memset(C,0,sizeof C) ;
    init() ;
    int cols, k ;
    cin >> cols >>  k ;
    char a[4][cols] ;
    FORN(i,0,4){
        FORN(j,0,cols){
            a[i][j] = '.' ;
        }
    }
    map<PII , set<PII > > m ;
    vector<PII > single ;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < cols ; j++){
            if (i == 0 || i == 3 || j == 0 || j==cols-1) continue ;
            int u = up(i,j,cols) ;
            int d = down(i,j,cols) ;
            if (u == d){
                //cout << "(" << i << "," << j << ")" << sp << u << sp << d << el ;
                single.pb(mp(i,j)) ;
                continue ;
            }
            if (k <= 1) continue ;
            if (m[mp(d,u)].size()==0){
                m[mp(u,d)].insert(mp(i,j)) ;
            }
            else{
                PII p = mp(d,u) ;
                PII p1 = *m[p].begin() ;
                PII p2 = mp(i,j) ;
                a[p1.xx][p1.yy] = '#' ;
                a[p2.xx][p2.yy] = '#' ;
                //cout << u << sp << d << "(" << p1.xx << "," << p1.yy << ")" << "(" << p2.xx << "," << p2.yy << ")" << el ;
                k -= 2  ;
                m[p].erase(m[p].begin()) ;

            }
        }
    }
    ////cout << k << el ;
    if (k > single.size()){
        cout << "NO" << el ;
        return 0 ;
    }
    int idx = 0 ;
    while (k > 0){
        PII p = single[idx++] ;
        a[p.xx][p.yy] = '#' ;
        k-- ;
    }
    cout << "YES" << el ;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < cols ; j++){
            cout << a[i][j] ;
        }
        cout << el ;
    }

    return 0 ;
 }
