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

 double dist(double x1 , double y1, double x2, double y2){
     return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)) ;
 }
 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;
    double x1,y1,x2,y2,R ;
    cin >> R >>  x1 >> y1 >> x2 >> y2 ;
    double d = dist(x1,y1,x2,y2) ;
    double cost , sint  ;
    //cout << d << el ;
    if (d == 0){
        double midx = (x1+x1+R)/2.0 ;
        double midy = (y2+y2)/2.0 ;
        double ans = dist(midx,midy,x1,y1) ;
        printf("%.9f %.9f %.9f\n",midx,midy,ans-0.000001);
        return 0 ;
    }
    else if (d<=R){
        cost = (x2-x1)/d ;
        sint = (y2-y1)/d ;
    }
    else{
        printf("%.9f %.9f %.9f\n",x1,y1,R);
        return 0 ; 
    }

    double endx = x1+R*(-cost) ;
    double endy = y1+R*(-sint) ;
    double midx = (x2+endx)/2.0 ;
    double midy = (y2+endy)/2.0 ;
    double ans = dist(midx,midy,endx,endy) ;
    ans = min(ans,dist(midx,midy,x2,y2)-0.000001) ;
    printf("%.9f %.9f %.9f\n",midx,midy,ans);

 }
