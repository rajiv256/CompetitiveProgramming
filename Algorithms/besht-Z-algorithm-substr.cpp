/* Resilience is the greatest of all virtues */
 /* Code by rajiv */

// Problem : http://codeforces.com/contest/126/problem/B


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


/*
Here Z[i] denotes the longest substring of S starting at 'i' that is also a prefix of the string S.
We obtain the values of Z[i] using an invariant [L,R] where [L,R] is an interval such that S[L,R] is a substring
that is prefix to the original string S, with R as maximum as possible.

*/

 int Z[10*MAXN] ;
 void Zalgo(string s){
     int L = 0 ; int R = 0 ;
     Z[0] = 0 ;
     int sz = s.size()  ;
     for(int i = 1 ; i < sz ; i++){
         if (i > R){
             L = R = i ;
             int j = 0 ;
             while (s[j] == s[i+j]){
                 R++ ; j++ ;
             }
             Z[i] = R-L ; R-- ;
             continue ;
         }
         else{
             int k = i-L ;
             if (Z[k] < R-i+1){
                 Z[i] = Z[k] ;
             }
             else{
                L = i ;
                int j = 0 ;
                while (R+j < s.size() && s[R+j]==s[R-L+j]){
                    j++ ;
                }
                R += j-1 ;
                Z[i] = R-L+1 ;
             }
         }
     }
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    string s ; cin >> s ;
    Zalgo(s) ;
    int sz = s.size() ;
    int maxz = -1 ; int res = -1 ;
    int i = 1 ;
    for(; i < sz ;i++){
        if (i+Z[i]==sz && i+maxz >= sz){
            res = sz-i ;
            break ;
        }
        maxz = max(maxz,Z[i]) ;
    }
    if (res == -1){
        cout << "Just a legend" << el ;
        return 0 ;
    }
    cout << s.substr(i,res) << el ;
    return 0 ;
 }
