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
 typedef struct node {
     int a, b , c ;
 }node ;
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    int n ; cin >> n ;
    vector<pair<int,PII > > ans ;
    pair<int,PII > p ; int v[3] ;
    for(int a = 1 ; a <= n ; a++){
        for(int b = a ; b <= n ; b++){
            int c = a^b ;
            if (c > n) continue ;

            if ((a+b)>c && (b+c)>a && (c+a)>b && abs(a-b)<c && abs(b-c)<a && abs(a-c)<b){

                if (c >= b){
                    p.xx = a ; p.yy.xx = b ; p.yy.yy = c ;
                }
                else if (c > a){
                    p.xx = a ; p.yy.xx = c ; p.yy.yy = b ;
                }
                else {
                    p.xx = c ; p.yy.xx = a ; p.yy.yy = b  ;
                }

                ans.pb(p) ;
            }
        }
    }
    if (ans.size() == 0){
        cout << "0" << el ;
        return 0 ;
    }
    sort(all(ans)) ;
    auto it = ans.begin() ;
    int cnt = 1 ; int idx = 1 ;  p = ans[0] ;
    for(; idx < ans.size() ; idx++){
        if (ans[idx] == p){
            continue ;
        }
        else{
            cnt++ ;
            p = ans[idx] ;
        }
    }

    cout << cnt << el ;
    return 0 ;

 }
