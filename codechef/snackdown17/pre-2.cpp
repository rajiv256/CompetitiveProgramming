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

 const int N = 550 ;
 int a[2][N] ;
 bool vis[2][N] ;
 int n ;
 bool valid(int x , int y){
     if (x <0 || x > 1 || y<0 || y>n || a[x][y]==0) return false ;
     return true ;
 }
 int count(int str, int stc){
     if (!valid(str,stc)) return 0 ;
     vis[str][stc] = true ;
     if (valid((str+1)%2,stc) && !vis[(str+1)%2][stc] ){
         return 1+count((str+1)%2, stc) ;
     }
     if ( valid(str,stc+1) && !vis[str][stc+1] ){
         return 1+count(str,stc+1) ;
     }
     return 1 ;
 }





 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    CASET {
        cin >> n ;

        memset(a,0,sizeof a) ;
        memset(vis,0,sizeof vis);

        int b = 0 ;
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < n ; j++){
                char ch ;
                cin >> ch ;
                if (ch == '#'){
                    a[i][j] = 1 ;
                    b++  ;
                }
            }
        }

        int st0 = -1 ; int st1 = -1 ; int fl = 0 ;
        for(int i = 0 ; i < n ; i++){
            if (a[0][i] == 1){
                st0 = i ;
                fl = 1 ;
            }
            if (a[1][i] == 1){
                st1 = i ;
                fl = 1 ;
            }
            if (fl) break ;
        }
        int ans = 0;
        if(st0 != -1 && st1 == -1){
            ans = count(0,st0) ;
        }
        if(st0 == -1 && st1 != -1){
            ans = count(1,st1) ;
        }
        if (st0==-1 && st1==-1){
            ans = -1 ;
        }
        if (st0 != -1 && st1 != -1){
            int t1 = count(0,st0) ;
            memset(vis,0,sizeof vis) ;
            int t2 = count(1,st1) ;
            ans = max(t1,t2);
        }
        if (ans == b) cout << "yes" << el ;
        else cout << "no" << el ;

    }
    return 0 ;
 }
