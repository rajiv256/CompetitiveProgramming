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
int n , m ;
 char a[100][100] ;
 map<char,pair<int,int> > ma ;
 int sx , sy , ex , ey ;


 bool valid(int x , int y){
     return (x>=0 && y>=0 && x<n && y<m) ;
 }
 bool solve(string s, int sx ,int sy){
     for(int i = 0 ; i < s.size() ; i++){
         PII p = ma[s[i]] ;
         sx += p.xx ;
         sy += p.yy ;
         if (!valid(sx,sy)){
             return false ;
         }
         if (a[sx][sy] == '#'){
             return false ;
         }
         if (sx == ex && sy == ey){
             return true ;
         }

     }
     if (sx == ex && sy == ey){
         return true ;
     }
     return false ;

 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> n >> m ; char c ;
    FORN(i,0,n){
        FORN(j,0,m){
            cin >> c ;
            a[i][j] = c ;
            if (c == 'S'){
                sx = i ; sy = j  ;
            }
            if (c == 'E'){
                ex = i ; ey = j ;
            }
        }
    }
    string s ; cin >> s ;


    vector<char> v ; v.pb('0') ; v.pb('1') ; v.pb('2') ; v.pb('3') ;
    sort(all(v)) ;
    int ans = 0 ;
    do{
        //cout << v[0] << sp << v[1] << sp << v[2] << sp << v[3] << el ;
        ma.clear() ;
        ma[v[0]] = mp(1,0) ;
        ma[v[1]] = mp(-1,0) ;
        ma[v[2]] = mp(0,1) ;
        ma[v[3]] = mp(0,-1) ;

        if (solve(s,sx,sy)){
            ans++ ;
        }
    }while (next_permutation(all(v))) ;

    cout << ans << el ;
 }
