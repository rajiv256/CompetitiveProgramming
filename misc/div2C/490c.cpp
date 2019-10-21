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

 ll a , b ;
 ll moda[10*MAXN] ;
 ll modb[10*MAXN] ;
 ll fwd[10*MAXN] ;
 ll bwd[10*MAXN] ;

 void init(){
     ll po = 1 ; ll po1 = 1 ;
     for(int i = 0 ; i < 10*MAXN ; i++){
         moda[i] = po ;
         modb[i] = po1 ;
         po = (po*10)%a ;
         po1 = (po1*10)%b ;
     }
 }

int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    string s ; cin >> s ;
    cin >> a >> b ;
    memset(moda,0,sizeof moda) ;
    memset(modb,0,sizeof modb) ;
    memset(fwd,0,sizeof fwd) ;
    memset(bwd,0,sizeof bwd) ;
    init() ;


    int n = s.size() ;
    ll val = 0 ; fwd[0] = (s[0]-'0')%a ;
    for(int i = 1 ; i < s.size() ; i++){
        int num = s[i]-'0' ;
        fwd[i] = (fwd[i-1]*10 + num)%a ;

    }
    // for(int i = 0 ; i < 8 ; i++){
    //     cout << fwd[i] << sp ;
    // }
    // cout << el ;
    val = 0 ; bwd[n-1] = (s[n-1]-'0') % b ;
    for(int i = n-2 ; i >= 0 ; i--){
        int num = s[i]-'0' ;
        int po = modb[n-i-1] ;
        bwd[i] = (bwd[i+1] + (num * po) % b) % b ;
    }
    for(int i = 0 ; i < s.size()-1 ; i++){
        if (s[i+1] != '0'){
            if (fwd[i]==0 && bwd[i+1] == 0){
                cout << "YES" << el ;
                cout << s.substr(0,i+1) << el << s.substr(i+1,s.size()) << el ;
                return 0 ;
            }
        }
    }
    cout << "NO" << el ;
    return 0 ;

 }
