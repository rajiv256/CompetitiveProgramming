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
 ll a[120][120] ;
 ll N , M ;
 ll A[120][120] ;


 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    CASET {
        memset(a,0,sizeof a) ;
        memset(A,0,sizeof A) ;
        cin >> N >> M ;
        FORN(i,1,N+1){
            FORN(j,1,M+1){
                cin >> a[i][j] ;
            }
        }
        ll prev = 1 ;
        for(int j = 1 ; j <= M ; j++){
            if (a[1][j] == -1) {A[1][j] = prev ; }
            else {prev = A[1][j] = a[1][j] ; }
        }

        for(int i = 2 ; i <= N ; i++){
            for(int j = 1 ; j <= M ; j++){
                if (a[i][j] == -1)
                A[i][j] = max(A[i-1][j], A[i][j-1]) ;
                else {
                    A[i][j] = a[i][j] ;
                }
            }
        }
        int fl = 1 ;
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= M ; j++){
                if (A[i][j-1] > A[i][j]){
                    fl = 0 ;
                    break ;
                }
            }
            if (fl == 0) break ;
        }
        for(int j = 1 ; j <= M ; j++){
            for(int i = 1 ; i <= N ; i++){
                if (A[i-1][j] > A[i][j]){
                    fl = 0 ; break ;
                }
            }
            if (fl == 0) break ;
        }
        if (fl == 0){
            cout << "-1" << el ;
        }
        else{
            FORN(i,1,N+1){
                FORN(j,1,M+1){
                    cout << A[i][j] << sp ;
                }
                cout << el ;
            }
        }
    }



 }
