// 12191 - File Recover UVa

// Tags : Suffix array - O(N*log(N)^2) 


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
 #define SZ(C) sizeof(C)/sizeof(C.at(0))
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
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 struct tup{
     int fi ;
     int se ;
     int idx ;
 };

 tup L[3*MAXN] ;
 int S[35][3*MAXN] ;
 ll LCP[3*MAXN] ;
 int P[3*MAXN] ;
 int N ;

 bool cmp(const tup& t1 , const tup& t2){
     return (t1.fi==t2.fi)?(t1.se<t2.se):(t1.fi<t2.fi) ;
 }

 void build_suffixarray(string s){
     N = s.size() ;

     for(int i = 0 ; i < N ; i++){
         S[0][i] = s[i] ;
     }
     int step = 1 ;
     for(int cnt = 1 ; cnt <= N ; cnt *= 2 ){

         for(int i = 0 ; i < N ; i++){
             L[i].fi = S[step-1][i] ;
             L[i].se = (i+cnt<N)?S[step-1][i+cnt]:-1 ;
             L[i].idx = i ;
         }
         sort(L,L+N,cmp) ;

         S[step][L[0].idx] = 0 ;
         for(int i = 1 ; i < N ; i++){
             if (L[i].fi == L[i-1].fi && L[i].se == L[i-1].se){
                 S[step][L[i].idx] = S[step][L[i-1].idx] ;
             }
             else{
                 S[step][L[i].idx] = i ;
             }
         }

         step++ ;

     }
     for(int i = 0 ; i < N ;i++){
         P[S[step-1][i]] = i ;
     }
 }
 ll lcp(int x, int y){
     if (x == y){
         return N-x ;
     }
     ll ret = 0 ;
     for(int i = ceil(log2(N)) ; i >= 0 ; i--){
         if (x < N && y < N && S[i][x]==S[i][y]){
             int k = pow(2,i) ;
             if (x+k-1<N &&  y+k-1<N){
                 x += k ;
                 y += k ;
                 ret += k ;
             }
         }
     }
     return ret ;
 }
 void build_lcp(){
     for(int i = 0 ; i < N-1 ; i++){
         LCP[i] = lcp(L[i].idx,L[i+1].idx) ;
     }
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    string s ;
    while (true){
        cin >> s ;
        if (s == "*") break ;
        memset(LCP,0,sizeof(LCP)) ;
        memset(L,0,sizeof(L));
        build_suffixarray(s) ;
        build_lcp() ;
        int ans = 0 ;  int curr = 0 ;
        for(int i = 0 ; i < N-1 ; i++){
            if (curr < LCP[i]){
                ans += LCP[i]-curr ;
            }
            curr = LCP[i] ;
        }

        cout << ans << el ;
    }

 }
