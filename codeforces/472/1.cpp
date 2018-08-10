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

 bool valid(string  s){
     for(int i = 0 ; i < s.size()-1 ; i++){
         if (s[i]!='?' && s[i] == s[i+1]) return false ;
     }
     return true ;
 }
 int nq(string s){
     int ans = 0 ;
     for(auto it : s){
         ans += (it=='?')?1:0 ;
    }
    return ans ;
 }
 bool twoc(string s){
     for(int i = 0 ; i < s.size()-1 ; i++){
         if (s[i]=='?' && s[i]==s[i+1]) return true ;
     }
     return false ;
 }
 bool finalyes(string s){
     int sz = s.size() ;
     s = s[1]+s ; s += s[sz-1] ;
     for(int i = 1 ; i <= sz ; i++){
         if (s[i]=='?' && s[i-1]!='?' && s[i+1]!='?'){
            if (s[i-1]!=s[i+1]){
                continue ;
            }
            else return true  ;
         }
     }
     return false ;
 }



 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int n ; cin >> n ;
    string s ; cin >> s ;
    if (!valid(s) || nq(s)==0){
        cout << "No" << el ;
        return 0 ;
    }
    if (s.size()==1){cout << "Yes" << el ; return 0 ; }
    if (s.size()==2) {cout << "Yes" << el ; return 0 ; }
    if (twoc(s)){cout << "Yes" << el ; return 0 ;}
    if (finalyes(s)) {cout << "Yes" << el ; return 0 ;}
    cout << "No" << el ;
 }
