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

 typedef pair<int,int> PII ; typedef vector<char> VI ; typedef vector<vector<int> > VVI ; typedef vector<bool> VB ; typedef vector<string> VS ;
 typedef map<int,int> MII ; typedef map<int,VI > MIV ; typedef set<int> SI ; typedef set<PII > SPII ; typedef vector<PII > VPII ; typedef vector<VPII > VVPII ;
char c[1] ;
char s[100005]  ;
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    set<char> poss ;
    for(int i = 0 ; i < 26 ; i++){
        poss.insert('a'+i) ;
    }
    int q ; scanf("%d",&q) ;
    int ans = 0 ;
    while (q--){
        scanf("%s",c) ;
        scanf("%s",s) ;

        if (poss.size() == 1){
            if (c[0] == '!' || (c[0] == '?' && s[0]!=*poss.begin())){
                ans++ ;
            }
        }
        else{
            if (c[0] == '.'){
                for(int i = 0 ; i < strlen(s) ; i++){
                    poss.erase(s[i]) ;
                }
            }
            if (c[0] == '!'){
                set<char> ss ;
                for(int i = 0 ; i < strlen(s) ; i++){
                    ss.insert(s[i]) ;
                }
                VI vs = VI(all(ss)) ;
                VI vp = VI(all(poss)) ;
                VI v(26) ;
                VI::iterator it = set_intersection(all(vs),all(vp),v.begin()) ;
                v.resize(it-v.begin());
                poss = set<char>(all(v)) ;
            }
            if (c[0] == '?'){
                poss.erase(s[0]) ; 
            }
        }
    }
    printf("%d\n",ans) ;
    return 0 ;

 }
