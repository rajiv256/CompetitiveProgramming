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
const int N = 505 ;
 char a[505][505] ;

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int r ,  c ; cin >> r >> c ;
    for(int i = 0 ; i < 505 ; i++){
        for(int j = 0 ; j < 505 ; j++){
            a[i][j] = 'D' ;
        }
    }
    char ch ;
    for(int i = 1 ; i <= r ; i++){
        for(int j = 1 ; j <= c ; j++){
            cin >> ch ;
            if (ch != '.') a[i][j] = ch ;
        }
    }
    for(int i = 1 ; i <= r ; i++){
        for(int j = 1 ; j <= c ; j++){
            if (a[i][j]=='W'){
                if (a[i-1][j]=='S' || a[i+1][j]=='S' || a[i][j-1]=='S' || a[i][j+1]=='S'){
                    cout << "No" << el ;
                    return 0 ;
                }
            }
        }
    }
    cout << "Yes" << el ;
    for(int i = 1 ; i <= r ; i++){
        for(int j = 1 ; j <= c; j++){
            cout << a[i][j] ;
        }
        cout << el ;
    }

 }
