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
 char s[20] ;
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    while (scanf("%s",s)!=EOF){
        int won[2] ;
        int gillette[2] ;
        won[0] = 0 ; gillette[0] = 5 ;
        won[1] = 0 ; gillette[1] = 5 ;
        int flag = 1 ;
        for(int sh = 0, fl = 0 ; sh < 10 ; sh++,fl=(fl+1)%2){
            if (s[sh]=='1'){
                won[fl]++ ;
            }
            if (s[sh]=='0'){
                gillette[fl]-- ;
            }

            int nfl = (fl+1)%2 ;
            //cout << gillette[0] << sp << gillette[1] << sp << won[0] << sp << won[1] << el ;
            if (gillette[0] < won[1]){
                cout << "TEAM-B" << sp << sh+1 << el;
                flag = 0 ;
                break ;
            }
            if (gillette[1] < won[0]){
                cout << "TEAM-A" << sp << sh+1 << el ;
                flag = 0 ;
                break ;
            }

        }
        if (flag == 0){
            continue  ;
        }
        for(int sh = 10 , fl = 0 ; sh < 20 ;sh++, fl =(fl+1)%2){
            if (s[sh]=='1'){
                won[fl] += 1;
            }
            // cout  << sh << sp won[0] << sp << won[1] << el ;
            int nfl = (fl+1)%2 ;
            if (fl%2 == 1){
                string s = "" ;
                if (won[fl]>won[nfl]){
                    s = "TEAM-B" ;
                    cout << s << sp << sh+1 << el ;
                    flag = 0 ;
                    break ;
                }
                else if (won[fl]<won[nfl]){
                    s = "TEAM-A" ;
                    cout << s << sp << sh+1 << el ;
                    flag = 0 ;
                    break ;
                }
            }
        }
        if (flag)
            cout << "TIE" << el ;




    }

 }
