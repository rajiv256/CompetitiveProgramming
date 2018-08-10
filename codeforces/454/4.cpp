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
int n, m ;
bool valid(int x, int y){
    return (x>=0 && y>=0 && x<n && y<m) ;
}


 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    cin >> n >> m ;

    int** c  = (int**)malloc(sizeof(int*)*n) ;

    for(int i = 0 ; i < n ; i++){
        c[i] = (int*)malloc(sizeof(int)*m) ;
    }
    int x = 1 ;
    FORN(i,0,n){
        FORN(j,0,m){
            c[i][j] = x++ ;
        }
    }
    bool transpose = false ;
    if (n > m){
        swap(n,m) ;
        transpose = true ;
    }
    int** a  = (int**)malloc(sizeof(int*)*n) ;
    int** b = (int**)malloc(sizeof(int*)*n) ;
    for(int i = 0 ; i < n ; i++){
        a[i] = (int*)malloc(sizeof(int)*m) ;
        b[i] = (int*)malloc(sizeof(int)*m) ;
    }
    if (transpose){
        FORN(i,0,n){
            FORN(j,0,m){
                a[i][j] = c[j][i] ;
            }
        }
    }
    else{
        a = c ;
    }

    if (n == 1){
        if (m > 1 && m < 4){
            cout << "NO" << el ;
            return 0 ;
        }
    }
    if (n == 3 && m == 3){
        cout << "YES" << el ;
        cout << "5 7 2" << el
            << "9 1 6" << el
            << "4 3 8" << el ;
        return 0 ;
    }
    if (n == 2 && m < 4){
        cout << "NO" << el ;
        return 0 ;
    }
    if (m %2 == 0){
        for(int i = 0 ; i < n ; i++){
            int j = (i%2==0)?0:m-1 ;
            int d = (i%2==0)?1:-1 ;
            for(int k = 1 ; k <m ; k += 2){
                b[i][j] = a[i][k] ;
                j += d ;
            }
            for(int k = 0 ; k < m ; k += 2){
                b[i][j] = a[i][k] ;
                j += d ;
            }
        }
    }
    else{
        for (int i = 0 ; i < n ; i++){
            int j = 0 ;
            for(int k = (i%2==0)?1:0 ; k < m ; k += 2){
                b[i][j++] = a[i][k] ;
            }
            for(int k = (i%2==0)?0:1 ; k < m ; k+=2){
                b[i][j++] = a[i][k] ;
            }
        }
    }
    cout << "YES" << el ;
    if (transpose){
        FORN(j,0,m){
            FORN(i,0,n){
                cout << b[i][j] << sp ;
            }
            cout << el ;
        }
    }
    else{
        FORN(i,0,n){
            FORN(j,0,m){
                cout << b[i][j] << sp ;
            }
            cout << el ;
        }
    }
    return 0 ;



}
