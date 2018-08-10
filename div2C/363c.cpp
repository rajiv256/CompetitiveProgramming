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

 void solve(vector<int>& v, int st, int en){
     if (st >= en){
         return ;
     }
     for(int i = st+1 ; i <= en ; i += 2){
         v[i] = 1 ; 
     }
 }



 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    string s ; cin >> s ;
    int cnt = 1 ; char ch = s[0] ;
    string ss = "" ; ss += s[0] ;

    for(int i = 1 ; i < s.size() ; i++){
        if (ch == s[i]){
            if (cnt < 2){
                ss += ch ;
            }
            cnt++ ;
        }
        else{
            ch = s[i] ; cnt = 1 ;
            ss += ch ;
        }
    }
    vector<char> chars ;
    vector<int> v ;
    cnt = 1 ; ch = ss[0] ;
    for(int i = 1 ; i < ss.size() ; i++){
        if (ch == ss[i]){
            cnt++ ;
        }
        else{
            chars.pb(ch) ;
            v.pb(cnt) ;
            cnt = 1 ;
            ch = ss[i] ;
        }
    }
    chars.pb(ch) ;
    v.pb(cnt) ;
    int st = 0 ;
    while (st < v.size()){
        if (v[st] < 2) {st++ ; continue ; }
        int en = st ;
        while (v[en]==2) en++ ;
        solve(v,st,en-1) ;
        st = en ;
    }
    string ans = "" ;
    for(int i = 0 ; i < chars.size() ; i++){
        for(int j = 0 ; j < v[i] ; j++){
            ans += chars[i] ;
        }
    }
    cout << ans << el ;
    return 0 ;
 }
