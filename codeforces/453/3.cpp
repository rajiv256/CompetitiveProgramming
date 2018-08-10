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
 int h ;
 int a[MAXN] ;

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> h ;
    FORN(i,0,h+1){
        cin >> a[i] ;
    }
    bool amb = false ;
    FORN(i,0,h){
        if (a[i]>1 && a[i+1]>1){
            amb = true ;
        }
    }
    if (!amb){
        cout << "perfect" << el ;
    }
    else{
        cout << "ambiguous" << el ;
        int par = 0 ;
        cout << par << sp ;
        par = 1 ;
        for(int hei = 1 ; hei <= h ; hei++){
            for(int i = 0 ; i < a[hei] ; i++){
                cout << par << sp ;
            }
            par += a[hei-1] ;
        }
        cout << el ;
        par = 0 ;
        cout << par << sp ;
        par = 1 ;
        for(int hei = 1 ; hei <= h ; hei++){
            if (a[hei-1] == 1){
                for(int i = 0 ; i < a[hei] ; i++){
                    cout << par << sp ;
                }
            }
            else{
                cout << par << sp ;
                for(int j = 1 ; j < a[hei] ; j++){
                    cout << par+1 << sp ;
                }
            }
            par += a[hei-1] ;
        }
        cout << el ;
    }
    return 0  ;

 }
