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
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ;   typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;
 ll a[2020][2020] ;
 ll al[2020][2020] ;
 ll ar[2020][2020] ;
 ll bl[2020][2020] ;
 ll br[2020][2020] ;
 ll tot[2020][2020] ;
 int n ;
 bool valid(int x , int y){
     return (x>=0 && y >=0 && x < n && y < n) ;
 }
 void init(){
     clr(al) ; clr(ar) ; clr(br) ; clr(bl) ;
     clr(tot) ;
     for(int i = 0 ; i < n ; i++){
         ll sum = 0 ;
         for(int j = 0 ; j < n ; j++) if (valid(j,i+j)) sum += a[j][i+j] ;
         for(int j = 0 ; j < n ; j++) if (valid(j,i+j)) al[j][i+j] = sum ;
         sum = 0 ;
         for(int j = 0 ; j < n ; j++) if (valid(j,i-j)) sum += a[j][i-j] ;
         for(int j = 0 ; j < n ; j++) if (valid(j,i-j)) ar[j][i-j] = sum ;
     }

     for(int i = 1 ; i < n-1 ; i++){
         ll sum = 0 ;
         for(int j = 0 ; j < n ; j++) if (valid(n-1-j,i-j)) sum += a[n-1-j][i-j] ;
         for(int j = 0 ; j < n ; j++) if (valid(n-1-j,i-j)) bl[n-1-j][i-j] = sum ;
         sum = 0 ;
         for(int j = 0 ; j < n ; j++) if (valid(n-1-j,i+j)) sum += a[n-1-j][i+j] ;
         for(int j = 0 ; j < n ; j++) if (valid(n-1-j,i+j)) br[n-1-j][i+j] = sum ;
     }
     for(int i = 0 ; i < n ; i++){
         for(int j = 0 ; j < n ; j++){
             tot[i][j] = al[i][j] + ar[i][j] + bl[i][j] + br[i][j] ;
             if ((i==n-1 & j == 0) || (i==n-1 &j==n-1)){
                 continue ;
             }
             tot[i][j] -= a[i][j] ;
         }
     }
     tot[0][0] = al[0][0] ;
     tot[0][n-1] = ar[0][n-1] ;

 }




 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> n ;
    FORN(i,0,n){
        FORN(j,0,n){
            cin >> a[i][j] ;
        }
    }
    init() ;
    ll max1 = -1 , max2 = -1 ; ll x1 = -1 , y1 = -1 , x2 =  -1 , y2 = -1 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if ((i+j)%2 == 0){
                if (max1 < tot[i][j]){
                    max1 = tot[i][j] ;
                    x1 = i+1 ; y1 = j+1 ;
                }
            }
            else if (max2 < tot[i][j]){
                max2 = tot[i][j] ;
                x2 = i+1 ; y2 = j+1 ;
            }
        }
    }
    cout << max1 + max2 << el ;
    cout << x1 << sp << y1 << sp << x2 << sp << y2 << el ;
    return 0 ;
 }
