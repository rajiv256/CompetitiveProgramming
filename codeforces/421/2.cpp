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
 typedef vector<pair<double,double> > VPDD ;
 typedef pair<double,double> PDD ;
 VPDD pts ;
 int n ; double ang ;
 double di(PDD p1, PDD p2){
     return (p1.xx-p2.xx)*(p1.xx-p2.xx)+(p1.yy-p2.yy)*(p1.yy-p2.yy) ;
 }
 double angle(int l, int m , int r){
     PDD p1 = pts[l] , p2 = pts[m], p3 = pts[r] ;
     double od1 = di(p2,p3) ;
     double od2 = di(p1,p3) ;
     double od3 = di(p1,p2) ;
     return acos((od1+od3-od2)/(2*sqrt(od1)*sqrt(od3))) ;
 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    cin >> n >> ang ;
    ang = ang*PI/180.0 ;
    double g = (360.0/n)*(PI/180.0)  ;
    double r = 1000000.0 ;
    double st = 0.0 ; int nv = 0 ;
    while (nv < n){
        pts.pb(mp(r*cos(st),r*sin(st))) ;
        st += g ;
        nv++ ;
    }
    int ans[3] ; ans[0] = -1 ; ans[1] = -1 ; ans[2] = -1 ;
    double minangle = 2*PI ;
    double aa ;
    for(int i = 2 ; i < n ; i++){
         aa = angle(0,1,i) ;
         if (minangle > abs(aa-ang)){
             minangle = abs(aa-ang) ;
             ans[0] = 0 ; ans[1] = 1 ; ans[2] = i ;
         }
         //cout << abs(aa-ang) << sp ;

         aa = angle(1,0,i) ;
         if (minangle > abs(aa-ang)){
             minangle = abs(aa-ang) ;
             ans[0] = 1 ; ans[1] = 0 ; ans[2] = i ;
         }
         //cout << abs(aa-ang) << sp ;
         aa = angle(0,i,1) ;
         if (minangle > abs(aa-ang)){
             minangle = abs(aa-ang) ;
             ans[0] = 0 ; ans[1] = i ; ans[2] = 1 ;
         }
         //cout << abs(aa-ang) << el ;
    }
    cout << (ans[0]+1) << sp << (ans[1]+1) << sp << (ans[2]+1) << el ;
    return 0  ;
 }
