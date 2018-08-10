/* I solemnly swear that I am upto no good. */
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
 #define MAXN 100005
 #define INF (int)1E10+1
 #define MOD (int)1E9+7
 #define last_set_bit(x) log2((x)&(-x))
 #define add(x,y) (x)=((x)+(y))%MOD

 typedef pair<int,int> PII ; typedef vector<int> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef
 vector<VPII > VVPII ;

 ll mod1 = 909327 ;
 ll p1 = 1799 ;
 ll mod2 = 999931 ;
 ll p2 = 953 ;

 ll add1(ll a, ll b, int fl){
     return (a+fl*b+mod1)%mod1 ;
 }
 ll add2(ll a, ll b, int fl){
     return (a+fl*b+mod2)%mod2 ;
 }
 ll mul1(ll a , ll b){
     return (a*b)%mod1 ;
 }
 ll mul2(ll a, ll b){
     return (a*b)%mod2 ;
 }

 ll F[5002] ;
 ll B[5002] ;
 ll F2[5002] ;
 ll B2[5002] ;
 ll P[5050] ;
 ll P2[5050] ;
 char pal[5002][5002] ;
 int dp[5002][5002] ;

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    //clock_t begin = clock() ;
    string s ; cin >> s ;

    F[0] = (int)s[0] ;
    F2[0] = (int)s[0] ;
    for(int i = 1 ; i < s.size() ; i++){
        F[i] = ((F[i-1]*p1)%mod1+(int)s[i])%mod1  ;
        F2[i] = ((F2[i-1]*p2)%mod2+(int)s[i])%mod2 ;
    }
    int sz = s.size() ;
    B[sz-1] = (int)s[sz-1];
    B2[sz-1] = (int)s[sz-1] ;
    for(int i = sz-2 ; i >= 0 ; i--){
        B[i] = ((B[i+1]*p1)%mod1+(int)s[i])%mod1 ;
        B2[i] = ((B2[i+1]*p2)%mod2+(int)s[i])%mod2 ;
    }


    memset(pal,0,sizeof(pal)) ;
    memset(dp,0,sizeof(dp)) ;
    for(int i = 0 ; i < sz; i++){
        pal[i][i] = 1 ;
    }
    memset(P,0,sizeof(P)) ;
    memset(P2,0,sizeof(P2)) ;
    P[0] = 1 ;
    P2[0] = 1 ;
    for(int i = 1 ; i < 5050 ; i++){
        P[i] = (P[i-1]*p1)%mod1 ;
        P2[i] = (P2[i-1]*p2)%mod2;
    }
    for(int i = 0 ; i < sz ; i++){
        for(int j = i+1 ; j < sz ; j++){
            if (add1(F[j],mul1((i>0)?F[i-1]:0,P[j-i+1]),-1) == add1(B[i],mul1((j+1<sz)?B[j+1]:0,P[j-i+1]),-1) && (add2(F2[j],mul2((i>0)?F2[i-1]:0,P2[j-i+1]),-1) == add2(B2[i],mul2((j+1<sz)?B2[j+1]:0,P2[j-i+1]),-1)) ){
                pal[i][j] = 1 ;
            }
        }
        //cout << i << el ;
    }
    // clock_t end = clock() ;
    // cout << end-begin << el ;
    for(int i = sz-1 ; i >= 0 ; i--){
        for(int j = i ; j<sz ; j++){
            if (j == 0) dp[i][j] = pal[i][j] ;
            else{
                dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1] + pal[i][j] ;
            }

        }
    }

    int q ; cin >> q ;
    while (q--){
        int x , y ; cin >> x >> y ;
        x-- ; y-- ;
        cout << dp[x][y] << el ;
    }


 }
