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
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;

 int F[MAXN] ;

 void build_failure_function(string pat){
     F[0] = 0 ; F[1] = 0 ;

     int i = 2 ;
     while (i <= pat.size()){
         int j = i-1 ;
         F[i] = 0 ;
         while (j > 0){
             if (pat[i-1] == pat[F[j]]){
                 F[i] = F[j]+1 ;
                 break ;
             }
             j = F[j]-1 ;
         }
         i++ ;
     }
 }

 int kmp_dp(string s, string pat){
     int i = 0 , j = 0 ;
     int ans = 0 ;
     while (i < s.size()){
         if (s[i]==pat[j] || s[i]=='?'){
             i++ ; j++ ;
             if (j == pat.size()){
                 ans++ ;
                 j = F[pat.size()] ;
                 continue ;
             }
         }
         else{
             int temp = j ;
             j = F[j] ;
             while (j > 0){
                 if (s[i]==pat[j] || s[i]=='?'){
                     i++ ; j++ ;
                     break ; 
                 }
                 j = F[j] ;
             }
             if (j == 0){
                 i = i-temp+1 ;
             }
         }
     }
     return ans ;
 }









 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    string s , pat ;
    cin >> s >> pat ;
    memset(F,0,sizeof(F)) ;
    build_failure_function(pat) ;
    int ans = 0 ;

    ans = kmp_dp(s,pat) ;

    reverse(all(s)) ; reverse(all(pat)) ;
    ans = max(ans,kmp_dp(s,pat)) ;

    cout << ans << el ;
 }
