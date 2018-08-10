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

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    string days[7] = {"mon","tues", "wed","thurs","fri","sat","sun"} ;
    CASET {
        int nd ; string s ;
        cin >> nd >> s ;
        int idx ;
        if (s[0]=='m') idx = 0 ;
        if (s[0]=='t'){ if (s[1]=='u') idx = 1 ; else idx = 3 ;}
        if (s[0]=='w') idx = 2 ;
        if (s[0]=='f') idx = 4 ;
        if (s[1]=='a') idx = 5 ;
        if (s[0]=='s' && s[1]=='u') idx = 6 ;

        VI v(7,0) ;
        for(int i = 0 ; i < 7 ; i++){
            int I = (idx+i) % 7 ;
            int x = 1 + i ;
            int cnt = 0 ;
            while (x <= nd){
                cnt++ ;
                x += 7 ;
            }
            v[I] = cnt ;
        }
        for(auto it : v){
            cout << it << sp ;
        }
        cout << el ;
    }
 }
